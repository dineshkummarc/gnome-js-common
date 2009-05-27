## Process this file with automake to produce Makefile.in

check_PROGRAMS = 
TESTS = 

if HAVE_SEED

check_PROGRAMS += run-tests-seed
TESTS += run-tests-seed

run_tests_seed_SOURCES = run-tests-seed.c run-tests.c

run_tests_seed_CFLAGS = \
	-Wall \
	$(SEED_CFLAGS)

run_tests_seed_LDFLAGS = \
	$(SEED_LIBS)

endif

if HAVE_GJS

check_PROGRAMS += run-tests-gjs
TESTS += run-tests-gjs

run_tests_gjs_SOURCES = run-tests-gjs.c run-tests.c

run_tests_gjs_CFLAGS = \
	-Wall \
	$(GJS_CFLAGS)

run_tests_gjs_LDFLAGS = \
	$(GJS_LIBS)

endif
