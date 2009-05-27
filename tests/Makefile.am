## Process this file with automake to produce Makefile.in

check_PROGRAMS = 
TESTS = 

if HAVE_SEED

check_PROGRAMS += run-tests-seed
TESTS += run-tests-seed

run_tests_seed_SOURCES = run-tests-seed.c

run_tests_seed_CFLAGS = \
	-Wall \
	$(SEED_CFLAGS)

run_tests_seed_LDFLAGS = \
	$(SEED_LIBS)

endif
