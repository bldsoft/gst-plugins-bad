plugin_LTLIBRARIES = libgstclocksync.la

libgstclocksync_la_SOURCES = gstplugin.c \
    gstclocksync.c

libgstclocksync_la_CFLAGS = \
	$(GST_PLUGINS_BAD_CFLAGS) \
	$(GST_PLUGINS_BASE_CFLAGS) \
	$(GST_BASE_CFLAGS) $(GST_CFLAGS)

libgstclocksync_la_LIBADD = \
	$(GST_PLUGINS_BASE_LIBS) -lgstvideo-@GST_API_VERSION@ \
	$(GST_BASE_LIBS) \
	$(GST_LIBS)

libgstclocksync_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)

noinst_HEADERS = gstclocksync.h