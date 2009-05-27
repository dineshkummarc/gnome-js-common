/*
 * -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- 
 */

#include <glib.h>
#include <stdlib.h>
#include <stdio.h>

gboolean failure_flag = FALSE;

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

