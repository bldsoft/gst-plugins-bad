/*
 * GStreamer
 * Copyright (C) 2015 Matthew Waters <matthew@centricular.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_VULKAN_INSTANCE_H__
#define __GST_VULKAN_INSTANCE_H__

#include <gst/vulkan/vulkan.h>

G_BEGIN_DECLS

#define GST_TYPE_VULKAN_INSTANCE         (gst_vulkan_instance_get_type())
#define GST_VULKAN_INSTANCE(o)           (G_TYPE_CHECK_INSTANCE_CAST((o), GST_TYPE_VULKAN_INSTANCE, GstVulkanInstance))
#define GST_VULKAN_INSTANCE_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), GST_TYPE_VULKAN_INSTANCE, GstVulkanInstanceClass))
#define GST_IS_VULKAN_INSTANCE(o)        (G_TYPE_CHECK_INSTANCE_TYPE((o), GST_TYPE_VULKAN_INSTANCE))
#define GST_IS_VULKAN_INSTANCE_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE((k), GST_TYPE_VULKAN_INSTANCE))
#define GST_VULKAN_INSTANCE_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS((o), GST_TYPE_VULKAN_INSTANCE, GstVulkanInstanceClass))
GST_VULKAN_API
GType gst_vulkan_instance_get_type       (void);

#define GST_VULKAN_INSTANCE_CONTEXT_TYPE_STR "gst.vulkan.instance"

struct _GstVulkanInstance
{
  GstObject parent;

  VkInstance instance; /* hides a pointer */
  VkPhysicalDevice *physical_devices; /* hides a pointer */
  guint32 n_physical_devices;

  VkDebugReportCallbackEXT msg_callback;
  PFN_vkCreateDebugReportCallbackEXT dbgCreateDebugReportCallback;
  PFN_vkDestroyDebugReportCallbackEXT dbgDestroyDebugReportCallback;
  PFN_vkDebugReportMessageEXT dbgReportMessage;
};

struct _GstVulkanInstanceClass
{
  GstObjectClass parent_class;
};

GST_VULKAN_API
GstVulkanInstance * gst_vulkan_instance_new                     (void);
GST_VULKAN_API
gboolean            gst_vulkan_instance_open                    (GstVulkanInstance * instance,
                                                                 GError ** error);

GST_VULKAN_API
gpointer            gst_vulkan_instance_get_proc_address        (GstVulkanInstance * instance,
                                                                 const gchar * name);

GST_VULKAN_API
GstVulkanDevice *   gst_vulkan_instance_create_device           (GstVulkanInstance * instance,
                                                                 GError ** error);

GST_VULKAN_API
void                gst_context_set_vulkan_instance             (GstContext * context,
                                                                 GstVulkanInstance * instance);
GST_VULKAN_API
gboolean            gst_context_get_vulkan_instance             (GstContext * context,
                                                                 GstVulkanInstance ** instance);
GST_VULKAN_API
gboolean            gst_vulkan_instance_handle_context_query    (GstElement * element,
                                                                 GstQuery * query,
                                                                 GstVulkanInstance * instance);
GST_VULKAN_API
gboolean            gst_vulkan_instance_run_context_query       (GstElement * element,
                                                                 GstVulkanInstance ** instance);
GST_VULKAN_API
gboolean            gst_vulkan_instance_check_version           (GstVulkanInstance * instance,
                                                                 guint major,
                                                                 guint minor,
                                                                 guint patch);
GST_VULKAN_API
void                gst_vulkan_instance_get_version             (GstVulkanInstance * instance,
                                                                 guint * major,
                                                                 guint * minor,
                                                                 guint * patch);

G_END_DECLS

#endif /* __GST_VULKAN_INSTANCE_H__ */
