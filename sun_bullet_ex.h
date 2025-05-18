#ifndef _SUN_BULLET_EX_H_
#define _SUN_BULLET_EX_H_

#include "bullet.h"
#include "animation.h"
#include "camera.h"

extern Atlas atlas_sun_ex;								//�����չ⶯��ͼ��
extern Atlas atlas_sun_ex_explode;						//�����չⱬը����ͼ��

extern Camera camera;

class SunBulletEx : public Bullet {
public:
	SunBulletEx();
	~SunBulletEx() = default;

	void on_collide();

	void on_update(int delta);

	void on_draw(const Camera& camera) const;

	bool check_collision(const Vector2D& position, const Vector2D& size);

private:
	Animation animation_idle;
	Animation animation_explode;
	Vector2D explode_render_offset;
};

#endif // !_SUN_BULLET_EX_H_

