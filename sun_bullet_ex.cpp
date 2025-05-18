#include "sun_bullet_ex.h"

SunBulletEx::SunBulletEx() {
	size.x = 288;
	size.y = 288;

	damage = 20;
	
	animation_idle.set_atlas(&atlas_sun_ex);
	animation_idle.set_interval(50);

	animation_explode.set_atlas(&atlas_sun_ex_explode);
	animation_explode.set_interval(50);
	animation_explode.set_loop(false);
	animation_explode.set_callback_function([&]() {can_remove = true; });
	
	IMAGE* idle_frame = animation_idle.get_frame(0);
	IMAGE* explode_frame = animation_explode.get_frame(0);

	explode_render_offset.x = (idle_frame->getwidth() - explode_frame->getwidth()) / 2.0f;
	explode_render_offset.y = (idle_frame->getheight() - explode_frame->getheight()) / 2.0f;
}

void SunBulletEx::on_collide() {
	Bullet::on_collide();

	camera.shake(20, 350);

	mciSendString(_T("play sun_explode_ex from 0"), NULL, 0, NULL);
}

bool SunBulletEx::check_collision(const Vector2D& position, const Vector2D& size) {
	bool is_collision_x = (max(this->position.x + this->size.x, position.x + size.x) -
		min(this->position.x, position.x) <= this->size.x + size.x);
	bool is_collision_y = (max(this->position.y + this->size.y, position.y + size.y) -
		min(this->position.y, position.y) <= this->size.y + size.y);
	return is_collision_x && is_collision_y;
}

void SunBulletEx::on_update(int delta) {
	if (valid) {
		position += velocity * delta;
	}
	if (!valid) {
		animation_explode.on_update(delta);
	}
	else {
		animation_idle.on_update(delta);

		if (check_if_out_screen()) {
			can_remove = true;
	}
	}
}

void SunBulletEx::on_draw(const Camera& camera) const {
	if (valid) {
		animation_idle.on_draw(camera, this->position.x, this->position.y);
	}
	else {
		animation_explode.on_draw(camera,
			(int)(position.x + explode_render_offset.x),
			(int)(position.y + explode_render_offset.y));
	}
}