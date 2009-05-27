/*
 * -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- 
 */

#include <glib.h>
#include <seed.h>
#include <stdlib.h>
#include <stdio.h>

SeedEngine * eng;
gboolean failure_flag = FALSE;

SeedValue js_assert(SeedContext ctx,
                    SeedObject function,
                    SeedObject this_object,
                    size_t argument_count,
                    const SeedValue arguments[],
                    SeedException * exception)
{
	if(!seed_value_to_boolean(ctx, arguments[0], NULL))
		seed_make_exception(ctx, exception, "AssertionError", "Assertion failed");
}

gboolean test_exec(gchar * filename)
{
	SeedObject global;
	SeedScript * script;
	SeedException e;
	gchar * buffer;

	g_file_get_contents(filename, &buffer, 0, 0);

	if(!buffer)
	{
		g_critical("File %s not found!", filename);
		exit(1);
	}

	if(*buffer == '#')
	{
		while(*buffer != '\n')
			buffer++;
		buffer++;
	}

	script = seed_make_script(eng->context, buffer, filename, 1);
	global = seed_context_get_global_object(eng->context);
	seed_importer_add_global(global, filename);
	
	seed_create_function(eng->context, "assert", js_assert, global);

	seed_evaluate(eng->context, script, 0);
	
	if((e = seed_script_exception(script)))
	{
		printf("%s... FAIL (%s: line %d)\n",
			filename,
			seed_exception_get_name(eng->context, e),
			seed_exception_get_line(eng->context, e));
		
		failure_flag = TRUE;
		
		return FALSE;
	}

	g_free(script);
	
	return TRUE;
}

void run_tests(gchar * tests_dir_name)
{
	GDir * tests_dir;
	const gchar * test_name;
	const gchar * test_path;
	
	tests_dir = g_dir_open(tests_dir_name, 0, NULL);
	while((test_name = g_dir_read_name(tests_dir)) != NULL)
	{
		if(!g_str_has_suffix(test_name, ".js")) // TODO: casing problem
			continue;
		
		test_path = g_build_filename(tests_dir_name, test_name, NULL);

		if(test_exec((char*)test_path))
			printf("%s... OK\n", test_path);
	}
	
}

int main(int argc, char ** argv)
{
	eng = seed_init(&argc, &argv);
	
	if(argc == 1)
		run_tests(".");
	else
	{
		int i;
		
		for(i = 1; i < argc; i++)
			run_tests(argv[i]);
	}
	
	return failure_flag;
}

