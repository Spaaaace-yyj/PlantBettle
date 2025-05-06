#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"
#include "scene_manager.h"
#include "atlas.h"
#include "animation.h"
#include "easyx.h"
#include "util.h"
#include "plantform.h"

extern IMAGE img_sky;
extern IMAGE img_hills;
extern IMAGE img_platform_large;
extern IMAGE img_platform_small;

extern Camera camera;

extern SceneManager scene_manager;

extern std::vector<Plantform> plantform_list;

extern bool is_debug;

class GameScene : public Scene {
public:
	void on_enter();
	void on_update(int delta);
	void on_draw(const Camera& camera);
	void on_input(const ExMessage& msg);
	void on_exit();
private:
	POINT pos_img_sky = { 0 };
	POINT pos_img_hills = { 0 };
};
 
#endif