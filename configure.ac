AC_INIT(gnome_js_common, 0.1)

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AC_CONFIG_HEADERS([config.h])
AM_MAINTAINER_MODE

AC_ISC_POSIX
AC_PROG_CC
AM_PROG_CC_STDC
AC_HEADER_STDC




dnl ***************************************************************************
dnl Internatinalization
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
   PKG_CHECK_MODULES(SEED, seed)
   AC_SUBST(SEED_CFLAGS)
   AC_SUBST(SEED_LDFLAGS)
fi

AC_ARG_ENABLE(gjs,
	AC_HELP_STRING([--enable-gjs],
	[enable building and testing of gjs. [default=yes]]),
	[want_gjs=$enableval],[want_gjs="yes"])

if test x"$want_gjs" == x"yes" ; then
   PKG_CHECK_MODULES(GJS, gjs-1.0)
   AC_SUBST(GJS_CFLAGS)
   AC_SUBST(GJS_LDFLAGS)
fi

AC_OUTPUT([
Makefile
po/Makefile.in
])

echo "
Configured Engines:
   Seed......................$want_seed
   gjs.......................$want_gjs
"
