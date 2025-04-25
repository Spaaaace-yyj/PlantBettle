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
	Vector2D position;				//摄像机位置
	Timer timer_shake;
	bool is_shaking = false;		//摄像机是否启用抖动特效
	float shaking_strength = 0;		//摄像机抖动幅度
};

#endif 