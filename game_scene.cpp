#include "game_scene.h"
#include <iostream>

void GameScene::on_enter() {
	pos_img_sky.x = (getwidth() - img_sky.getwidth()) / 2;
	pos_img_sky.y = (getheight() - img_sky.getheight()) / 2;

	pos_img_hills.x = (getwidth() - img_hills.getwidth()) / 2;
	pos_img_hills.y = (getheight() - img_hills.getheight()) / 2;

	plantform_list.resize(4);
	Plantform& large_plantform = plantform_list[0];
	large_plantform.img = &img_platform_large;
	large_plantform.render_position.x = 122;
	large_plantform.render_position.y = 455;
	large_plantform.shape.left = (float)large_plantform.render_position.x + 30;
	large_plantform.shape.right = (float)large_plantform.render_position.x + img_platform_large.getwidth() - 30;
	large_plantform.shape.y = (float)large_plantform.render_position.y + 60;
	
	Plantform& small_plantform_1 = plantform_list[1];
	small_plantform_1.img = &img_platform_small;
	small_plantform_1.render_position.x = 175;
	small_plantform_1.render_position.y = 360;
	small_plantform_1.shape.left = (float)small_plantform_1.render_position.x + 40;
	small_plantform_1.shape.right = (float)small_plantform_1.render_position.x + img_platform_small.getwidth() - 40;
	small_plantform_1.shape.y = (float)small_plantform_1.render_position.y + img_platform_small.getheight() / 2;

	Plantform& small_plantform_2 = plantform_list[2];
	small_plantform_2.img = &img_platform_small;
	small_plantform_2.render_position.x = 855;
	small_plantform_2.render_position.y = 360;
	small_plantform_2.shape.left = (float)small_plantform_2.render_position.x + 40;
	small_plantform_2.shape.right = (float)small_plantform_2.render_position.x + img_platform_small.getwidth() - 40;
	small_plantform_2.shape.y = (float)small_plantform_2.render_position.y + img_platform_small.getheight() / 2;

	Plantform& small_plantform_3 = plantform_list[3];
	small_plantform_3.img = &img_platform_small;
	small_plantform_3.render_position.x = 515;
	small_plantform_3.render_position.y = 255;
	small_plantform_3.shape.left = (float)small_plantform_3.render_position.x + 40;
	small_plantform_3.shape.right = (float)small_plantform_3.render_position.x + img_platform_small.getwidth() - 40;
	small_plantform_3.shape.y = (float)small_plantform_3.render_position.y + img_platform_small.getheight() / 2;

}

void GameScene::on_draw(const Camera& camera) {
	putimage_alpha(camera, pos_img_sky, &img_sky);
	putimage_alpha(camera, pos_img_hills, &img_hills);
	for (const Plantform& plantform : plantform_list) {
		putimage_alpha(camera, plantform.render_position, plantform.img);
	}

	if (is_debug) {
		setlinecolor(RGB(255, 0, 0));

		for (const Plantform& plantform : plantform_list) {
			draw_line(camera, plantform.shape.left, plantform.shape.y, plantform.shape.right, plantform.shape.y);
		}
	}
}

void GameScene::on_input(const ExMessage& msg) {
	if (msg.message == WM_KEYUP) {
		if (msg.vkcode == 0x51) {
			if (is_debug) {
				is_debug = false;
			}
			else {
				is_debug = true;
			}
		}
	}
}

void GameScene::on_update(int delta) {
	
}

void GameScene::on_exit() {
	
}