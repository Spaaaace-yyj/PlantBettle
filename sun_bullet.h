#ifndef _SUN_BULLET_H_
#define _SUN_BULLET_H_

#include "bullet.h"
#include "animation.h"

extern Atlas atlas_sun;								//�չ⶯��ͼ��
extern Atlas atlas_sun_explode;						//�չⱬը����ͼ��

extern Camera camera;


class SunBullet : public Bullet {
public:
	SunBullet();
	~SunBullet() = default;

	void on_collide();

	void on_update(int delta);

	void on_draw(const Camera& camera) const;

private:
	const float gravity = 1e-3f;
private:
	Animation animation_idle;
	Animation animation_explode;
	Vector2D explode_render_offset;	//��ը������Ⱦƫ��

};

#endif // !_SUN_BULLET_H_

