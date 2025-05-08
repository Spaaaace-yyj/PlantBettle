#ifndef _BULLET_H_
#define _BULLET_H_


#include <functional>
#include <easyx.h>

#include "vector2D.h"
#include "player_id.h"
#include "camera.h"

class Bullet {
public:
	Bullet() = default;
	~Bullet() = default;

	void set_damage(int val);
	int get_damage();

	void set_size(float width, float height);
	const Vector2D& get_size();

	void set_position(float x, float y);
	void set_position(const Vector2D& position);
	const Vector2D& get_position();

	void set_velocity(float x, float y);

	void set_collide_target(PlayerID target);

	void set_callback(std::function<void()> callback);

	void set_valid(bool val);
	bool get_valid() const;

	bool check_can_remove() const;

	virtual void on_collide();

	virtual bool check_collision(const Vector2D& position, const Vector2D& size);

	virtual void on_update(int delta);
	virtual void on_draw(const Camera& camera) const;

protected:
	bool check_if_out_screen();

protected:
	bool valid = true;
	bool can_remove = false;
protected:
	Vector2D size;
	Vector2D position;
	Vector2D velocity;
	int damage = 10;

	std::function<void()> callback;
	PlayerID target_id = PlayerID::P1;
};


#endif // !_BULLET_H_

