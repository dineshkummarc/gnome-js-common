SUBDIRS = po modules tests

gnome_js_commondocdir = ${prefix}/share/doc/gnome_js_common
gnome_js_commondoc_DATA = \
	README \
	COPYING \
	AUTHORS \
	ChangeLog \
	INSTALL \
	NEWS

INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = $(gnome_js_commondoc_DATA) \
	$(INTLTOOL_FILES)

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache

pkgconfig_DATA = gnome-js-common.pc
pkgconfigdir = $(libdir)/pkgconfig

# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(gnome_js_commondocdir)
