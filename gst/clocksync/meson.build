clocksync_sources = [
  'gstclocksync.c',
  'gstplugin.c',
]

gstclocksync = library('gstclocksync',
  clocksync_sources,
  c_args : gst_plugins_bad_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : [configinc, libsinc],
  dependencies : [gstbase_dep],
  install : true,
  install_dir : plugins_install_dir,
)
pkgconfig.generate(gstclocksync, install_dir : plugins_pkgconfig_install_dir)
