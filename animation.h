#ifndef _AINIMATION_H_
#define _AINIMATION_H_

#include "atlas.h"
#include "util.h"
#include "camera.h"

#include <functional>
#include <graphics.h>

class Animation {
public:
	Animation() = default;
	~Animation() = default;

	void reset();

	void set_atlas(Atlas* atlas);

	void set_interval(int interval);

	void set_loop(bool is_loop);

	int get_idx_frame();

	IMAGE* get_frame(int idx);

	bool is_finish();

	void on_update(int delta);

	void on_draw(const Camera& camera, int x, int y) const;

	void set_callback_function(std::function<void()> callback);

private:
	int timer = 0;
	int interval = 0;	//µ¥Î»ms
	int idx_frame = 0;
	bool is_loop;
	Atlas* atlas = nullptr;
	std::function<void()> callback;
};

#endif
