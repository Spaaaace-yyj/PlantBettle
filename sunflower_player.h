#ifndef _SUNFLOWER_PLAYER_H_
#define _SUNFLOWER_PLAYER_H_

#include "player.h"
#include <iostream>

extern Atlas atlas_sunflower_idle_left;				//龙日葵朝向左的默认动画图集
extern Atlas atlas_sunflower_idle_right;				//龙日葵朝向右的默认动画图集
extern Atlas atlas_sunflower_run_left;					//龙日葵朝向左的奔跑动画图集
extern Atlas atlas_sunflower_run_right;				//龙日葵朝向右的奔跑动画图集
extern Atlas atlas_peashooter_attack_ex_left;			//豌豆射手朝向左的特殊攻击动画图集
extern Atlas atlas_peashooter_attack_ex_right;			//豌豆射手朝向右的特殊攻击动画图集

class SunFlowerPlayer : public Player{
public:
	SunFlowerPlayer();
	~SunFlowerPlayer() = default;

	void on_update(int delta);

private:

};

#endif // !_SUNFLOWER_PLAYER_H_
