#ifndef _PEASHOOTER_PLAYER_H_
#define _PEASHOOTER_PLAYER_H_

#include "player.h"
#include <iostream>

extern Atlas atlas_peashooter_idle_left;				//豌豆射手朝向左的默认动画图集
extern Atlas atlas_peashooter_idle_right;				//豌豆射手朝向右的默认动画图集
extern Atlas atlas_peashooter_run_left;				//豌豆射手朝向左的奔跑动画图集
extern Atlas atlas_peashooter_run_right;				//豌豆射手朝向右的奔跑动画图集

class PeashooterPlayer : public Player{
public:
	PeashooterPlayer();
	~PeashooterPlayer() = default;

	void on_update(int delta);

private:

};

#endif // !_PEASHOOTER_PLAYER_H_

