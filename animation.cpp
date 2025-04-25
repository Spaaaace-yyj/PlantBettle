#include "animation.h"

void Animation::reset() {
	timer = 0;
	idx_frame = 0;
}

void Animation::set_atlas(Atlas* atlas) {
	this->atlas = atlas;
}

void Animation::set_interval(int interval) {
	this->interval = interval;
}

void Animation::set_loop(bool is_loop) {
	this->is_loop = is_loop;
}

int Animation::get_idx_frame() {
	return idx_frame;
}

IMAGE* Animation::get_frame(int idx) {
	return atlas->get_image(idx);
}

bool Animation::is_finish() {
	
	if (is_loop) {
		return false;
	}

	if (idx_frame >= atlas->get_size()) {
		return true;
	}
}

void Animation::on_update(int delta) {
	timer += delta;
	
	if (timer >= interval) {
		timer = 0;
		idx_frame++;
		if (idx_frame >= atlas->get_size()) {
			idx_frame = is_loop ? 0 : atlas->get_size() - 1;
			if (!is_loop && callback) {
				callback();
			}
		}
	}
}

void Animation::on_draw(int x, int y) const {
	putimage_alpha(x, y, atlas->get_image(idx_frame));
}

void Animation::set_callback_function(std::function<void()> callback) {
	this->callback = callback;
}
