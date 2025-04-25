#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

//include user
#include "scene.h"
#include "scene_manager.h"
#include "timer.h"
#include "atlas.h"
#include "animation.h"
#include "camera.h"
//include c++
#include <iostream>

extern SceneManager scene_manager;

extern IMAGE img_menu_background;

class MenuScene :public Scene{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter();
	void on_update(int delta);
	void on_draw(const Camera& camera);
	void on_input(const ExMessage& msg);
	void on_exit();

private:
	Timer timer;
	Animation animation_peashooter_run_right;

};

#endif