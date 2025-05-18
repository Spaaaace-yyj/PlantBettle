#ifndef _PEASHOOTER_PLAYER_H_
#define _PEASHOOTER_PLAYER_H_

#include "player.h"
#include <iostream>
#include "pea_bullet.h"
#include "camera.h"

extern Atlas atlas_peashooter_idle_left;				//�㶹���ֳ������Ĭ�϶���ͼ��
extern Atlas atlas_peashooter_idle_right;				//�㶹���ֳ����ҵ�Ĭ�϶���ͼ��
extern Atlas atlas_peashooter_run_left;				//�㶹���ֳ�����ı��ܶ���ͼ��
extern Atlas atlas_peashooter_run_right;				//�㶹���ֳ����ҵı��ܶ���ͼ��

extern Atlas atlas_sunflower_attack_ex_left;			//���տ�����������⹥������ͼ��
extern Atlas atlas_sunflower_attack_ex_right;			//���տ������ҵ����⹥������ͼ��

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

