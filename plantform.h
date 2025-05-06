#ifndef _PLANTFORM_H_
#define _PLANTFORM_H_

#include "camera.h"
#include "easyx.h"
#include "util.h"

class Plantform {
public:
	Plantform() = default;
	~Plantform() = default;
public:
	struct CollisionShape
	{
		float y;
		float left, right;
	};
public:	
	void on_draw(const Camera &camera) const;

public:
	CollisionShape shape;
	IMAGE* img = nullptr;
	POINT render_position = { 0 };
};


#endif 
