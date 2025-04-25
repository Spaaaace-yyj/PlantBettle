#ifndef _SCENE_H_
#define _SCENE_H_

#include <graphics.h>
#include "camera.h"

//基类，模板menu，gamescene，selectscene
			//共同的代码逻辑
class Scene {
public:
	Scene() = default;
	~Scene() = default;

	virtual void on_enter();
	virtual void on_update(int delta);
	virtual void on_draw(const Camera& camera);
	virtual void on_input(const ExMessage& msg);
	virtual void on_exit();
private:

};

#endif
