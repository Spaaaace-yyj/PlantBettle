#ifndef _PEA_BULLET_H_
#define _PEA_BULLET_H_

#include "bullet.h"
#include "animation.h"
#include "util.h"

extern IMAGE img_pea;									//Õ„∂πÕº∆¨
extern Atlas atlas_pea_break;							//Õ„∂π∆∆ÀÈ∂Øª≠ÕººØ

class PeaBullet : public Bullet {
public:
	PeaBullet();
	~PeaBullet() = default;

	void on_collide();

	void on_update(int delta);
	void on_draw(const Camera& camera) const;

private:
	Animation animation_break;
};

#endif // !_PEA_BULLET_H_

