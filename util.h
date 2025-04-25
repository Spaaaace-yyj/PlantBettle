#ifndef _UTIL_H_
#define _UTIL_H_

#include <graphics.h>
#include "camera.h"
#pragma comment(lib , "MSIMG32.LIB")

inline void flip_image(IMAGE* src, IMAGE* dst) {
	int w = src->getwidth();
	int h = src->getheight();
	Resize(dst, w, h);
	DWORD* src_buffer = GetImageBuffer(src);
	DWORD* dst_buffer = GetImageBuffer(dst);
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int idx_src = y * w + x;
			int idx_dst = y * w + (w - x - 1);
			dst_buffer[idx_dst] = src_buffer[idx_src];
		}
	}
}

inline void putimage_alpha(const Camera& camera, int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), (int)(x - camera.get_position().x), (int)(y - camera.get_position().y), w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA });
}

inline void putimage_alpha(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL),x , y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA });
}

inline void putimage_alpha(int x, int y, int width, int height, IMAGE* img) {
	int w = width > 0 ? width : img->getwidth();
	int h = height > 0 ? height : img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA });
}

inline void putimage_alpha(const Camera& camera, int x, int y, int width, int height, IMAGE* img) {
	int w = width > 0 ? width : img->getwidth();
	int h = height > 0 ? height : img->getheight();
	AlphaBlend(GetImageHDC(NULL), (int)(x - camera.get_position().x), (int)(y - camera.get_position().y), w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA });
}
#endif // !_UTIL_H_
