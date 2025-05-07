#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "camera.h"
#include "easyx.h"
#include "vector2D.h"
#include "animation.h"
#include "player_id.h"

class Player {
public:
	Player();
	~Player() = default;

	virtual void on_update(int delta);
	virtual void on_draw(const Camera& camera);
	virtual void on_input(const ExMessage& msg);

	void set_id(PlayerID id);

	void set_position(float x, float y);

	virtual void on_run(float distance);

protected:
	bool is_left_key_down = false;
	bool is_right_key_down = false;
protected:
	bool is_facing_right = true;
protected:
	const float run_velocity = 0.55f;
protected:
	Vector2D position;

	Animation animation_idle_left;
	Animation animation_idle_right;
	Animation animation_run_left;
	Animation animation_run_right;

	Animation* current_animation = nullptr;

	PlayerID id = PlayerID::P1;
};

#endif
