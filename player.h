#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "camera.h"
#include "easyx.h"
#include "vector2D.h"
#include "animation.h"
#include "player_id.h"
#include "easyx.h"
#include "plantform.h"
#include "bullet.h"

extern std::vector<Plantform> plantform_list;
extern std::vector<Bullet*> bullet_list;

class Player {
public:
	Player();
	~Player() = default;

	virtual void on_update(int delta);
	virtual void on_draw(const Camera& camera);
	virtual void on_input(const ExMessage& msg);

	void set_id(PlayerID id);

	void set_position(float x, float y);
	Vector2D get_position() const;

	Vector2D get_velocity() const;

	Vector2D get_size() const;

	virtual void on_run(float distance);

	virtual void on_jump();

	virtual void on_attack() {

	}
	virtual void on_attack_ex() {

	}

protected:
	void move_and_collide(int delta);

protected:
	bool is_left_key_down = false;
	bool is_right_key_down = false;

	bool can_attack = true;
	int attack_cd = 500;
	Timer timer_attack_cd;

	bool is_attacking_ex = false;
protected:
	bool is_facing_right = true;
protected:
	const float run_velocity = 0.55f;
	const float gravity = 1.6e-3f; //ÕÊº“÷ÿ¡¶	
	const float jump_velocity = -0.8f;
protected:
	int mp = 0;
	int hp = 100;

	Vector2D position;
	Vector2D velocity;
	Vector2D size;

	Animation animation_idle_left;
	Animation animation_idle_right;
	Animation animation_run_left;
	Animation animation_run_right;
	Animation animation_attack_ex_left;
	Animation animation_attack_ex_right;

	Animation* current_animation = nullptr;

	PlayerID id = PlayerID::P1;
};

#endif
