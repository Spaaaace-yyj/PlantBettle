#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "scene.h"

extern Scene* menu_scene;
extern Scene* game_scene;
extern Scene* select_scene;

class SceneManager {
public:
	enum class SceneType {
		Menu,
		Game,
		Select
	};

	SceneManager() = default;
	~SceneManager() = default;

	void set_current_scene(Scene* scene);
	void switch_to(SceneType type);
	void on_update(int delta);
	void on_draw(const Camera& camera);
	void on_input(const ExMessage& msg);

private:
	Scene* current_scene = nullptr;
};

#endif