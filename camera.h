#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector.h"
#include "timer.h"

class Camera {
public:
	Camera();
	~Camera() = default;

	const Vector2D get_position() const;

	void reset();

	void on_update(int delta);

	void shake(float strength, int duration);

private:
	Vector2D position;				//�����λ��
	Timer timer_shake;
	bool is_shaking = false;		//������Ƿ����ö�����Ч
	float shaking_strength = 0;		//�������������
};

#endif 