/*
 * -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- 
 */

#include <glib.h>
#include <gjs/gjs.h>
#include <stdlib.h>
#include <stdio.h>

gboolean initialized = FALSE;
extern gboolean failure_flag;

/*SeedValue js_assert(SeedContext ctx,
                    SeedObject function,
                    SeedObject this_object,
                    size_t argument_count,
                    const SeedValue arguments[],
                    SeedException * exception)
{
	if(!seed_value_to_boolean(ctx, arguments[0], NULL))
		seed_make_exception(ctx, exception, "AssertionError", "Assertion failed");
}*/

gboolean test_exec(gchar * filename)
{
	gchar * buffer;
	
	if(!initialized)
	{
		// init gjs
		initialized = TRUE;
	}

	// eval filename in a new context, discard context, check errors etc.
	
	return TRUE;
}

