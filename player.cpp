#include "player.h"

Player::Player() {
	current_animation = &animation_idle_left;
}

void Player::on_update(int delta) {
	int direction = is_right_key_down - is_left_key_down;

	if (direction != 0) {
		is_facing_right = direction > 0;
		current_animation = is_facing_right ? &animation_run_right : &animation_run_left;
		float distance = run_velocity * delta * direction;
		on_run(distance);
	}
	else {
		current_animation = is_facing_right ? &animation_idle_right : &animation_idle_left;
	}
	current_animation->on_update(delta);
}

void Player::on_draw(const Camera& camera) {
	current_animation->on_draw(camera, (int)position.x, (int)position.y);
}

void Player::on_input(const ExMessage& msg) {
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (id) {
		case PlayerID::P1:
			switch (msg.vkcode) {
			case 0x41:
				is_left_key_down = true;
				break;
			case 0x44:
				is_right_key_down = true;
				break;
			}
			break;
		case PlayerID::P2:
			switch (msg.vkcode) {
			case 0x25:
				is_left_key_down = true;
				break;
			case 0x27:
				is_right_key_down = true;
				break;
			}
			break;
		}
		break;
	case WM_KEYUP:
		switch (id) {
		case PlayerID::P1:
			switch (msg.vkcode) {
			case 0x41:
				is_left_key_down = false;
				break;
			case 0x44:
				is_right_key_down = false;
				break;
			}
			break;
		case PlayerID::P2:
			switch (msg.vkcode) {
			case 0x25:
				is_left_key_down = false;
				break;
			case 0x27:
				is_right_key_down = false;
				break;
			}
			break;
		}
		break;
	default:
		break;
	}
}

void Player::set_id(PlayerID id) {
	this->id = id;
}

void Player::set_position(float x, float y) {
	position.x = x;
	position.y = y;
}

void Player::on_run(float distance) {
	position.x += distance;
}