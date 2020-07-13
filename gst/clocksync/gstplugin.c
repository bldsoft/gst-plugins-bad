#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "gstclocksync.h"

static gboolean
plugin_init (GstPlugin * plugin)
{
  if (!gst_element_register (plugin, "clocksync", GST_RANK_NONE,
          gst_clock_sync_get_type ()))
    return FALSE;

  return TRUE;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    clocksync, "clocksync",
    plugin_init, VERSION, "LGPL", GST_PACKAGE_NAME, GST_PACKAGE_ORIGIN)
