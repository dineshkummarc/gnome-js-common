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

static JSBool js_assert(JSContext *context,
                        JSObject * obj,
                        uintN argc,
                        jsval * argv,
                        jsval * retval)
{
    gboolean success;

    if(!JSVAL_TO_BOOLEAN(argv[0]))
    {
        gjs_throw(context, "Assertion failed");
        return JS_FALSE;
    }

    return JS_TRUE;
}

gboolean test_exec(gchar * filename)
{
	gchar * buffer;
	GError *error = NULL;
	gboolean success;
	int code;
	char *search_path[1];
    search_path[0] = NULL;
    GjsContext * context;
	
	if(!initialized)
	{
		gjs_crash_after_timeout(60*7); /* give the unit tests 7 minutes to complete */
		gjs_init_sleep_on_crash();
		
		g_type_init();
		initialized = TRUE;
	}

	context = gjs_context_new_with_search_path(search_path);
	
	if (!JS_DefineFunction(context, JS_GetGlobalObject(context),
                           "assert",
                           js_assert,
                           1, GJS_MODULE_PROP_FLAGS))
        return FALSE;
    
	success = gjs_context_eval_file(context, filename, &code, &error);
	
	if (!success)
	{
		g_error("%s", error->message);
		return FALSE;
	}
	
	return TRUE;
}

