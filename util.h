#ifndef _UTIL_H_
#define _UTIL_H_

#include <graphics.h>
#include "camera.h"
#include "vector2D.h"
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

//转换坐标位置到摄像机坐标系下的渲染
inline void putimage_alpha(const Camera& camera, int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), (int)(x - camera.get_position().x), (int)(y - camera.get_position().y), w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA });
}

inline void putimage_alpha(const Camera& camera,POINT p, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), (int)(p.x - camera.get_position().x), (int)(p.y - camera.get_position().y), w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA });
}
//渲染到屏幕坐标系
inline void putimage_alpha(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL),x , y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA });
}
//渲染到屏幕坐标系，并裁切渲染
inline void putimage_alpha(int x, int y, int width, int height, IMAGE* img) {
	int w = width > 0 ? width : img->getwidth();
	int h = height > 0 ? height : img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA });
}
//转换相机坐标系并且裁切渲染
inline void putimage_alpha(const Camera& camera, int x, int y, int width, int height, IMAGE* img) {
	int w = width > 0 ? width : img->getwidth();
	int h = height > 0 ? height : img->getheight();
	AlphaBlend(GetImageHDC(NULL), (int)(x - camera.get_position().x), (int)(y - camera.get_position().y), w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA });
}

inline void putimage_alpha(const Camera& camera, POINT p, int width, int height, IMAGE* img) {
	int w = width > 0 ? width : img->getwidth();
	int h = height > 0 ? height : img->getheight();
	AlphaBlend(GetImageHDC(NULL), (int)(p.x - camera.get_position().x), (int)(p.y - camera.get_position().y), w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA });
}

//将两个图像水平拼接渲染
inline IMAGE combine_image(IMAGE src1, IMAGE src2, int scan_line) {
	IMAGE result;
	int w1 = src1.getwidth();
	int w2 = src2.getwidth();
	int h1 = src1.getheight();
	int h2 = src2.getheight();
	int comb_w = w1 + w2;
	int comb_h = h1 > h2 ? h1 : h2;
	Resize(&result, comb_w, comb_h);
	SetWorkingImage(&result);
	putimage(scan_line - w1, 0, &src1);
	putimage(scan_line, 0, &src2);
	SetWorkingImage(NULL);
	return result;
}

inline void draw_line(const Camera& camera, Vector2D p1, Vector2D p2) {
	const Vector2D camera_pos = camera.get_position();
	line((int)(p1.x - camera_pos.x), (int)(p1.y - camera_pos.y), (int)(p2.x - camera_pos.x), (int)(p2.y - camera_pos.y));
}

inline void draw_line(const Camera& camera, int x1, int y1, int x2, int y2) {
	const Vector2D camera_pos = camera.get_position();
	line((int)(x1 - camera_pos.x), (int)(y1 - camera_pos.y), (int)(x2 - camera_pos.x), (int)(y2 - camera_pos.y));
}
#endif // !_UTIL_H_
