#ifndef _SUN_BULLET_H_
#define _SUN_BULLET_H_

#include "bullet.h"
#include "animation.h"

extern Atlas atlas_sun;								//日光动画图集
extern Atlas atlas_sun_explode;						//日光爆炸动画图集

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
	Vector2D explode_render_offset;	//爆炸动画渲染偏移

};

#endif // !_SUN_BULLET_H_

