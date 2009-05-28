/*
 * -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- 
 */

#include <glib.h>
#include <seed.h>
#include <stdlib.h>
#include <stdio.h>

SeedEngine * eng = NULL;
extern gboolean failure_flag;

gboolean test_exec(gchar * filename)
{
  SeedObject global;
  SeedScript * script;
  SeedException e;
  gchar * buffer;
	
  if(!eng)
    eng = seed_init(NULL, NULL);

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

