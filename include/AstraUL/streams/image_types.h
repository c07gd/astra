#ifndef IMAGE_TYPES_H
#define IMAGE_TYPES_H

#include <stdint.h>
#include <Astra/astra_types.h>

#if ! defined(__ANDROID__) && (defined(__GNUC__) || defined(__clang__))
#define PACK_STRUCT __attribute__((packed))
#else
#define PACK_STRUCT
#endif

#ifdef _MSC_VER
#pragma pack(push, 1)
#endif

typedef uint32_t astra_pixel_format_t;

typedef enum {
    ASTRA_PIXEL_FORMAT_UNKNOWN = 0,
    ASTRA_PIXEL_FORMAT_DEPTH_MM = 100,

    // color layouts
    ASTRA_PIXEL_FORMAT_RGB888 = 200,
    ASTRA_PIXEL_FORMAT_YUV422 = 201,
    ASTRA_PIXEL_FORMAT_YUYV = 202,
    ASTRA_PIXEL_FORMAT_GRAY8 = 300,
    ASTRA_PIXEL_FORMAT_GRAY16 = 301
} astra_pixel_formats;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} PACK_STRUCT astra_rgb_pixel_t;

typedef struct {
    uint32_t width;
    uint32_t height;
    astra_pixel_format_t pixelFormat;
    uint8_t bytesPerPixel;
} PACK_STRUCT astra_image_metadata_t;

typedef struct {
    uint32_t id;
    uint32_t width;
    uint32_t height;
    astra_pixel_format_t pixelFormat;
    uint8_t bytesPerPixel;
    uint8_t fps;
} astra_imagestream_mode_t;

#ifdef _MSC_VER
#pragma pack(pop)
#endif

typedef struct _astra_imageframe* astra_imageframe_t;
typedef astra_streamconnection_t astra_imagestream_t;

#endif // IMAGE_TYPES_H
