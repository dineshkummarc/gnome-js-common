AC_INIT(gnome-js-common, 0.1)

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AC_CONFIG_HEADERS([config.h])
AM_MAINTAINER_MODE

AC_ISC_POSIX
AC_PROG_CC
AM_PROG_CC_STDC
AC_HEADER_STDC
AM_PROG_CC_C_O

dnl ***************************************************************************
dnl Internationalization
dnl ***************************************************************************

GETTEXT_PACKAGE=gnome_js_common
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
AM_GLIB_GNU_GETTEXT
IT_PROG_INTLTOOL([0.35.0])

AM_PROG_LIBTOOL

AC_ARG_ENABLE(seed,
	AC_HELP_STRING([--enable-seed],
	[enable building and testing of Seed. [default=yes]]),
	[want_seed=$enableval],[want_seed="yes"])

if test x"$want_seed" == x"yes" ; then
   PKG_CHECK_EXISTS(seed, have_seed=yes, have_seed=no)

   if test x"$have_seed" == x"yes" ; then
      PKG_CHECK_MODULES(SEED, seed)
      AC_SUBST(SEED_CFLAGS)
      AC_SUBST(SEED_LDFLAGS)
   fi
else
   have_seed=no
fi

AC_ARG_ENABLE(gjs,
	AC_HELP_STRING([--enable-gjs],
	[enable building and testing of gjs. [default=yes]]),
	[want_gjs=$enableval],[want_gjs="yes"])

if test x"$want_gjs" == x"yes" ; then
   PKG_CHECK_EXISTS(gjs-gi-1.0, have_gjs=yes, have_gjs=no)

   if test x"$have_gjs" == x"yes" ; then
      PKG_CHECK_MODULES(GJS, gjs-1.0 gjs-gi-1.0)
      AC_SUBST(GJS_CFLAGS)
      AC_SUBST(GJS_LDFLAGS)
   fi
else
   have_gjs=no
fi

AM_CONDITIONAL(HAVE_SEED, test "x$have_seed" = "xyes")
AM_CONDITIONAL(HAVE_GJS, test "x$have_gjs" = "xyes")

AC_SUBST(HAVE_SEED)
AC_SUBST(HAVE_GJS)

AC_OUTPUT([
Makefile
po/Makefile.in
modules/Makefile
modules/tweener/Makefile
tests/Makefile
gnome-js-common.pc
])

echo "
Tests:
   Seed.........$have_seed
   gjs..........$have_gjs
"
