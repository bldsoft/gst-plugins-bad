/* GStreamer
 * Copyright (C) 2011 Andoni Morales Alastruey <ylatuya@gmail.com>
 *
 * gstm3u8playlist.h:
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

#ifndef __GST_M3U8_PLAYLIST_H__
#define __GST_M3U8_PLAYLIST_H__

#include <glib.h>
#include <glib-object.h>


G_BEGIN_DECLS

extern const int RIXJOB_GSTM3U8PLAYLIST_H_PATCH_VERSION;
extern const int RIXJOB_GSTM3U8PLAYLIST_C_PATCH_VERSION;

enum
{
  GST_HLS_PROGRAM_DATE_TIME_NEVER,
  GST_HLS_PROGRAM_DATE_TIME_FIRST_CHUNK,
  GST_HLS_PROGRAM_DATE_TIME_ALL_CHUNKS
};

GType gst_hls_program_date_time_mode_get_type(void);

#define GST_HLS_PROGRAM_DATE_TIME_MODE_TYPE     \
    (gst_hls_program_date_time_mode_get_type ())

typedef struct _GstM3U8Playlist GstM3U8Playlist;

struct _GstM3U8Playlist
{
  guint version;
  gboolean allow_cache;
  gint window_size;
  gint type;
  gboolean end_list;
  guint sequence_number;
  guint discontinuity_sequence_number;
  const gchar *key_location;
  gint encryption_method;
  gint program_date_time_mode;

  /*< Private >*/
  GQueue *entries;
};

typedef enum
{
  GST_M3U8_PLAYLIST_RENDER_INIT = (1 << 0),
  GST_M3U8_PLAYLIST_RENDER_STARTED = (1 << 1),
  GST_M3U8_PLAYLIST_RENDER_ENDED = (1 << 2),
} GstM3U8PlaylistRenderState;


GstM3U8Playlist * gst_m3u8_playlist_new (guint version, 
				         guint window_size,
					 gboolean allow_cache);

void              gst_m3u8_playlist_free (GstM3U8Playlist * playlist);

gboolean          gst_m3u8_playlist_add_entry (GstM3U8Playlist * playlist,
                                               const gchar     * url,
                                               const gchar     * title,
                                               gfloat            duration,
                                               guint             index,
                                               gboolean          discontinuous,
                                               GDateTime       * program_date_time);

gchar *           gst_m3u8_playlist_render (GstM3U8Playlist * playlist);


void gst_m3u8_playlist_add_discontinuity(GstM3U8Playlist * playlist);
G_END_DECLS

#endif /* __M3U8_H__ */
