#include "sun_bullet.h"

SunBullet::SunBullet() {
	size.x = 96;
	size.y = 96;

	damage = 20;
	animation_idle.set_atlas(&atlas_sun);
	animation_idle.set_interval(50);
	
	animation_explode.set_atlas(&atlas_sun_explode);
	animation_explode.set_interval(50);
	animation_explode.set_loop(false);
	animation_explode.set_callback_function([&]() {can_remove = true; });

	IMAGE *idle_frame = animation_idle.get_frame(0);
	IMAGE* explode_frame = animation_explode.get_frame(0);
	explode_render_offset.x = (idle_frame->getwidth() - explode_frame->getwidth()) / 2.0f;
	explode_render_offset.y = (idle_frame->getheight() - explode_frame->getheight()) / 2.0f;
}

void SunBullet::on_collide() {
	Bullet::on_collide(); 

	camera.shake(5, 250);

	mciSendString(_T("play sun_explode from 0"), NULL, 0, NULL);
}

void SunBullet::on_update(int delta) {
	if (valid) {
		velocity.y += gravity * delta;
		position += velocity * delta;
	}
}

void SunBullet::on_draw(const Camera& camera) const {
	if (valid) {
		animation_idle.on_draw(camera, position.x, position.y);
	}
	else {
		animation_explode.on_draw(camera,
			(int)(position.x + explode_render_offset.x), 
			(int)(position.y + explode_render_offset.y));
	}
}