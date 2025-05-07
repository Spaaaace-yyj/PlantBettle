#ifndef _PEASHOOTER_PLAYER_H_
#define _PEASHOOTER_PLAYER_H_

#include "player.h"
#include <iostream>

extern Atlas atlas_peashooter_idle_left;				//�㶹���ֳ������Ĭ�϶���ͼ��
extern Atlas atlas_peashooter_idle_right;				//�㶹���ֳ����ҵ�Ĭ�϶���ͼ��
extern Atlas atlas_peashooter_run_left;				//�㶹���ֳ�����ı��ܶ���ͼ��
extern Atlas atlas_peashooter_run_right;				//�㶹���ֳ����ҵı��ܶ���ͼ��

class PeashooterPlayer : public Player{
public:
	PeashooterPlayer();
	~PeashooterPlayer() = default;

	void on_update(int delta);

private:

};

#endif // !_PEASHOOTER_PLAYER_H_

