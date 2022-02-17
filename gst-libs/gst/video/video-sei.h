/* GStreamer
 * Copyright (C) <2021> Fluendo S.A. <contact@fluendo.com>
 *   Authors: Andoni Morales Alastruey <amorales@fluendo.com>
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

#ifndef __GST_VIDEO_SEI_USER_DATA_UNREGISTERED_H__
#define __GST_VIDEO_SEI_USER_DATA_UNREGISTERED_H__

#include <gst/gst.h>
#include <gst/video/video.h>

G_BEGIN_DECLS

/**
 * MISB UUID for H.264 Precision Time Stamp
 *
 * This is from MISB ST 0604.6 Section 11.1.
 */
static const guint8 H264_MISP_MICROSECTIME[] = {
  0x4D, 0x49, 0x53, 0x50, 0x6D, 0x69, 0x63, 0x72,
  0x6F, 0x73, 0x65, 0x63, 0x74, 0x69, 0x6D, 0x65
};

/**
 * MISB UUID for H.265 Precision Time Stamp
 *
 * This is from MISB ST 0604.6 Section 12.1.
 */
static const guint8 H265_MISP_MICROSECONDS[] = {
  0xA8, 0x68, 0x7D, 0xD4, 0xD7, 0x59, 0x37, 0x58,
  0xA5, 0xCE, 0xF0, 0x33, 0x8B, 0x65, 0x45, 0xF1
};

/**
 * MISB UUID for H.265 Nano Time Stamp
 *
 * This is from MISB ST 0604.6 Section 12.1.
 */
static const guint8 H265_MISP_NANOSECONDS[] = {
  0xCF, 0x84, 0x82, 0x78, 0xEE, 0x23, 0x30, 0x6C,
  0x92, 0x65, 0xE8, 0xFE, 0xF2, 0x2F, 0xB8, 0xB8
};

/**
 * GstVideoSEIUserDataUnregisteredMeta:
 * @meta: parent #GstMeta
 * @description: H.264 H.265 metadata from SEI User Data Unregistered messages
 * @uuid: User Data Unregistered UUID
 * @data: Unparsed data buffer
 * @size: Size of the data buffer
 *
 * Since: 1.22
 */
typedef struct {
  GstMeta meta;

  guint8 uuid[16];
  guint8 *data;
  gsize size;
} GstVideoSEIUserDataUnregisteredMeta;

GST_VIDEO_API
GType gst_video_sei_user_data_unregistered_meta_api_get_type (void);
/**
 * GST_VIDEO_SEI_USER_DATA_UNREGISTERED_META_API_TYPE:
 *
 * Since: 1.22
 */
#define GST_VIDEO_SEI_USER_DATA_UNREGISTERED_META_API_TYPE (\
    gst_video_sei_user_data_unregistered_meta_api_get_type())

GST_VIDEO_API
const GstMetaInfo *gst_video_sei_user_data_unregistered_meta_get_info (void);
/**
 * GST_VIDEO_SEI_USER_DATA_UNREGISTERED_META_INFO:
 *
 * Since: 1.22
 */
#define GST_VIDEO_SEI_USER_DATA_UNREGISTERED_META_INFO (\
    gst_video_sei_user_data_unregistered_meta_get_info())

/**
 * gst_buffer_get_video_sei_user_data_unregistered_meta:
 * @b: A #GstBuffer
 *
 * Gets the #GstVideoSEIUserDataUnregisteredMeta that might be present on @b.
 *
 * Since: 1.22
 *
 * Returns: The first #GstVideoSEIUserDataUnregisteredMeta present on @b, or %NULL if
 * no #GstVideoSEIUserDataUnregisteredMeta are present
 */
#define gst_buffer_get_video_sei_user_data_unregistered_meta(b) \
        ((GstVideoSEIUserDataUnregisteredMeta*)gst_buffer_get_meta((b),GST_VIDEO_SEI_USER_DATA_UNREGISTERED_META_API_TYPE))

GST_VIDEO_API
GstVideoSEIUserDataUnregisteredMeta *gst_buffer_add_video_sei_user_data_unregistered_meta (GstBuffer * buffer,
                                                                                           guint8 uuid[16],
                                                                                           guint8 * data,
                                                                                           gsize size);

GST_VIDEO_API
gboolean gst_video_sei_user_data_unregistered_parse_precision_time_stamp (GstVideoSEIUserDataUnregisteredMeta * user_data,
                                                                          guint8 * status,
                                                                          guint64 * precision_time_stamp);

G_END_DECLS

#endif /* __GST_VIDEO_SEI_USER_DATA_UNREGISTERED_H__ */
