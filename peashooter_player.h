#ifndef _PEASHOOTER_PLAYER_H_
#define _PEASHOOTER_PLAYER_H_

#include "player.h"
#include <iostream>
#include "pea_bullet.h"
#include "camera.h"

extern Atlas atlas_peashooter_idle_left;				//豌豆射手朝向左的默认动画图集
extern Atlas atlas_peashooter_idle_right;				//豌豆射手朝向右的默认动画图集
extern Atlas atlas_peashooter_run_left;				//豌豆射手朝向左的奔跑动画图集
extern Atlas atlas_peashooter_run_right;				//豌豆射手朝向右的奔跑动画图集

extern Atlas atlas_sunflower_attack_ex_left;			//龙日葵朝向左的特殊攻击动画图集
extern Atlas atlas_sunflower_attack_ex_right;			//龙日葵朝向右的特殊攻击动画图集

extern Camera camera;

class PeashooterPlayer : public Player{
public:
	PeashooterPlayer();
	~PeashooterPlayer() = default;

	void on_update(int delta);

	void on_attack();

	void on_attack_ex();

private:
	void spawn_pea_bullet(float speed);

private:
	const float bullet_speed = 0.75f;
	const float bullet_speed_ex = 1.5f;
	const int attack_ex_duration = 2500;

private:
	Timer timer_attack_ex;
	Timer timer_spawn_pea_ex;
};

#endif // !_PEASHOOTER_PLAYER_H_

