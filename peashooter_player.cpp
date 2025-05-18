#include "peashooter_player.h"

void PeashooterPlayer::on_update(int delta) {
	Player::on_update(delta);

	if (is_attacking_ex) {
		camera.shake(5, 100);
		timer_attack_ex.on_update(delta);
		timer_spawn_pea_ex.on_update(delta);
	}
}

PeashooterPlayer::PeashooterPlayer() {
	animation_idle_left.set_atlas(&atlas_peashooter_idle_left);
	animation_idle_right.set_atlas(&atlas_peashooter_idle_right);
	animation_run_left.set_atlas(&atlas_peashooter_run_left);
	animation_run_right.set_atlas(&atlas_peashooter_run_right);
	animation_attack_ex_left.set_atlas(&atlas_sunflower_attack_ex_left);
	animation_attack_ex_right.set_atlas(&atlas_sunflower_attack_ex_right);

	animation_idle_left.set_interval(75);
	animation_idle_right.set_interval(75);
	animation_run_left.set_interval(75);
	animation_run_right.set_interval(75);
	animation_attack_ex_left.set_interval(75);
	animation_attack_ex_right.set_interval(75);
	size.x = 96;
	size.y = 96;

	timer_attack_ex.set_wait_time(attack_ex_duration);
	timer_attack_ex.set_trigger_once(true);
	timer_attack_ex.set_callback([&]() {
		is_attacking_ex = false;
		});
	timer_spawn_pea_ex.set_wait_time(100);
	timer_spawn_pea_ex.set_callback([&]() {
		spawn_pea_bullet(bullet_speed_ex);
		});
	attack_cd = 100;
}

void PeashooterPlayer::on_attack() {
	spawn_pea_bullet(bullet_speed);

	switch (rand() % 2)
	{
	case 0:
		mciSendString(_T("play pea_shoot_1 from 0"), NULL, 0, NULL);
		break;
	case 1:
		mciSendString(_T("play pea_shoot_2 from 0"), NULL, 0, NULL);
		break;
	default:
		break;
	}
}

void PeashooterPlayer::spawn_pea_bullet(float speed) {
	Bullet* bullet = new PeaBullet();

	Vector2D bullet_position, bullet_velocity;
	const Vector2D& bullet_size = bullet->get_size();
	bullet_position.x = is_facing_right
		? position.x + size.x - bullet_size.x / 2
		: position.x - bullet_size.x / 2;
	bullet_position.y = position.y;
	bullet_velocity.x = is_facing_right ? speed : -speed;
	bullet_velocity.y = 0;

	bullet->set_position(bullet_position.x, bullet_position.y);
	bullet->set_velocity(bullet_velocity.x, bullet_velocity.y);

	bullet->set_collide_target(id == PlayerID::P1 ? PlayerID::P2 : PlayerID::P1);
	bullet->set_callback([&]() {mp += 25; });

	bullet_list.push_back(bullet);
}

void PeashooterPlayer::on_attack_ex(){
	is_attacking_ex = true;
	timer_attack_ex.restart();

	is_facing_right ? animation_attack_ex_right.reset() : animation_attack_ex_left.reset();
	mciSendString(_T("play pea_shoot_ex from 0"), NULL, 0, NULL);
}