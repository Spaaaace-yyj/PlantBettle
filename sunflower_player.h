#ifndef _SUNFLOWER_PLAYER_H_
#define _SUNFLOWER_PLAYER_H_

#include "player.h"
#include <iostream>

extern Atlas atlas_sunflower_idle_left;				//���տ��������Ĭ�϶���ͼ��
extern Atlas atlas_sunflower_idle_right;				//���տ������ҵ�Ĭ�϶���ͼ��
extern Atlas atlas_sunflower_run_left;					//���տ�������ı��ܶ���ͼ��
extern Atlas atlas_sunflower_run_right;				//���տ������ҵı��ܶ���ͼ��
extern Atlas atlas_peashooter_attack_ex_left;			//�㶹���ֳ���������⹥������ͼ��
extern Atlas atlas_peashooter_attack_ex_right;			//�㶹���ֳ����ҵ����⹥������ͼ��

class SunFlowerPlayer : public Player{
public:
	SunFlowerPlayer();
	~SunFlowerPlayer() = default;

	void on_update(int delta);

private:

};

#endif // !_SUNFLOWER_PLAYER_H_
