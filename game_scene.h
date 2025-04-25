#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"
#include "scene_manager.h"

extern SceneManager scene_manager;

class GameScene : public Scene {
public:
	void on_enter();
	void on_update(int delta);
	void on_draw(const Camera& camera);
	void on_input(const ExMessage& msg);
	void on_exit();
private:

};

#endif