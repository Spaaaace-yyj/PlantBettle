#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

//include user
#include "scene.h"
#include "scene_manager.h"
//include c++
#include <iostream>

extern SceneManager scene_manager;

class MenuScene :public Scene{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter();
	void on_update();
	void on_draw();
	void on_input(const ExMessage& msg);
	void on_exit();

private:

};

#endif