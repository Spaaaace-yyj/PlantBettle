#include "player.h"
#include <iostream>

Player::Player() {
	current_animation = &animation_idle_left;

	timer_attack_cd.set_wait_time(attack_cd);
	timer_attack_cd.set_trigger_once(true);
	timer_attack_cd.set_callback([&]() {
		can_attack = true;
		});
}

void Player::on_update(int delta) {
	int direction = is_right_key_down - is_left_key_down;

	if (direction != 0) {
		is_facing_right = direction > 0;
		current_animation = is_facing_right ? &animation_run_right : &animation_run_left;
		float distance = run_velocity * delta * direction;
		//on_run(distance);
		std::cout << distance << std::endl;
		velocity.x = run_velocity * direction;
	}
	else {
		current_animation = is_facing_right ? &animation_idle_right : &animation_idle_left;
		velocity.x = 0;
	}
	current_animation->on_update(delta);
	move_and_collide(delta);

	timer_attack_cd.on_update(delta);
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
			case 0x57:
				on_jump();
				break;
			case 0x46:
				if (can_attack) {
					on_attack();
					can_attack = false;
					timer_attack_cd.restart();
				}
			case 0x47:
				if (mp >= 100) {
					on_attack_ex();
					mp = 0;
				}
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
			case 0x26:
				on_jump();
				break;
			case VK_OEM_PERIOD:
				if (can_attack) {
					on_attack();
					can_attack = false;
					timer_attack_cd.restart();
				}
			case VK_OEM_2:
				if (mp >= 100) {
					on_attack_ex();
					mp = 0;
				}
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
	if (is_attacking_ex) {
		return;
	}

	position.x += distance;
}

void Player::move_and_collide(int delta) {
	velocity.y += gravity * delta;
	position += velocity * (float)delta;

	if (velocity.y > 0) {

		for (const Plantform& plantform : plantform_list) {
			const Plantform::CollisionShape& shape = plantform.shape;
			bool is_collide_x = (max(position.x + size.x, shape.right) - min(position.x, shape.left)
				<= size.x + (shape.right - shape.left));
			bool is_collide_y = (shape.y >= position.y && shape.y <= position.y + size.y);
			
			if (is_collide_x && is_collide_y) {
				float delta_pos_y = velocity.y * delta;
				float last_tick_foot_pos_y = position.y + size.y - delta_pos_y;
				if (last_tick_foot_pos_y <= shape.y) {
					position.y = shape.y - size.y;
					velocity.y = 0;

					break;
				}
			}
		}
	}
}

void Player::on_jump() {
	if (velocity.y == 0 && !is_attacking_ex) {
		velocity.y += jump_velocity;
	}
}

Vector2D Player::get_position() const{
	return position;
}

Vector2D Player::get_velocity() const {
	return velocity;
}

Vector2D Player::get_size() const {
	return size;
}
