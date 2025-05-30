#include "select_scene.h"

void SelectScene::on_enter() {

	animation_peashooter.set_atlas(&atlas_peashooter_idle_right);
	animation_sunflower.set_atlas(&atlas_sunflower_idle_right);
	animation_peashooter.set_interval(100);
	animation_sunflower.set_interval(100);
	animation_peashooter.set_loop(true);
	animation_sunflower.set_loop(true);

	static const int OFFSET_X = 50;

	pos_img_vs.x = (getwidth() - img_VS.getwidth()) / 2;
	pos_img_vs.y = (getheight() - img_VS.getheight()) / 2;
	pos_img_tip.x = (getwidth() - img_selector_tip.getwidth()) / 2;
	pos_img_tip.y = getheight() - 125;
	pos_img_1P.x = (getwidth() / 2 - img_1P.getwidth()) / 2 - OFFSET_X;
	pos_img_1P.y = 35;
	pos_img_2P.x = getwidth() / 2 + (getwidth() / 2 - img_2P.getwidth()) / 2 + OFFSET_X;
	pos_img_2P.y = pos_img_1P.y;
	pos_img_1P_desc.x = (getwidth() / 2 - img_1P_desc.getwidth()) / 2 - OFFSET_X;
	pos_img_1P_desc.y = getheight() - 150;
	pos_img_2P_desc.x = getwidth() / 2 + (getwidth() / 2 - img_2P_desc.getwidth()) / 2 + OFFSET_X;
	pos_img_2P_desc.y = pos_img_1P_desc.y;
	pos_img_1P_gravestone.x = (getwidth() / 2 - img_gravestone_right.getwidth()) / 2 - OFFSET_X;
	pos_img_1P_gravestone.y = pos_img_1P.y + img_1P.getheight() + 35;
	pos_img_2P_gravestone.x = getwidth() / 2 + (getwidth() / 2 - img_gravestone_left.getwidth()) / 2 + OFFSET_X;
	pos_img_2P_gravestone.y = pos_img_1P_gravestone.y;
	pos_animation_1P.x = (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 - OFFSET_X;
	pos_animation_1P.y = pos_img_1P_gravestone.y + 80;
	pos_animation_2P.x = getwidth() / 2 + (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 + OFFSET_X;
	pos_animation_2P.y = pos_animation_1P.y;
	pos_img_1P_name.y = pos_animation_1P.y + 155;
	pos_img_2P_name.y = pos_img_1P_name.y;
	pos_1P_selector_btn_left.x = pos_img_1P_gravestone.x - img_1P_selector_btn_idle_left.getwidth();
	pos_1P_selector_btn_left.y = pos_img_1P_gravestone.y + (img_gravestone_right.getheight() - img_1P_selector_btn_idle_left.getheight()) / 2;
	pos_1P_selector_btn_right.x = pos_img_1P_gravestone.x + img_gravestone_right.getwidth();
	pos_1P_selector_btn_right.y = pos_1P_selector_btn_left.y;
	pos_2P_selector_btn_left.x = pos_img_2P_gravestone.x - img_2P_selector_btn_idle_left.getwidth();
	pos_2P_selector_btn_left.y = pos_1P_selector_btn_left.y;
	pos_2P_selector_btn_right.x = pos_img_2P_gravestone.x + img_gravestone_left.getwidth();
	pos_2P_selector_btn_right.y = pos_1P_selector_btn_left.y;
	
}

void SelectScene::on_draw(const Camera& camera) {
	putimage(0, 0, &img_selector_background);
	switch (player_type_1) {
	case PlayerType::Peashooter:
		img_peashooter_selector_background_right_extern = combine_image(img_peashooter_selector_background_left, img_peashooter_selector_background_left, 560 - scan_line);
		putimage_alpha(getwidth() - 560, 0, 560, 720, &img_peashooter_selector_background_right_extern);
		break;
	case PlayerType::SunFlower:
		img_sunflower_selector_background_right_extern = combine_image(img_sunflower_selector_background_left, img_sunflower_selector_background_left, 560 - scan_line);
		putimage_alpha(getwidth() - 560, 0, 560, 720, &img_sunflower_selector_background_right_extern);
		break;
	}

	switch (player_type_2) {
	case PlayerType::Peashooter:
		img_peashooter_selector_background_left_extern = combine_image(img_peashooter_selector_background_right, img_peashooter_selector_background_right, scan_line);
		putimage_alpha(0, 0, 560, 720, &img_peashooter_selector_background_left_extern);
		break;
	case PlayerType::SunFlower:
		img_peashooter_selector_background_left_extern = combine_image(img_sunflower_selector_background_right, img_sunflower_selector_background_right, scan_line);
		putimage_alpha(0, 0, 560, 720, &img_peashooter_selector_background_left_extern);
		break;
	}

	putimage_alpha(pos_img_vs.x, pos_img_vs.y, &img_VS);

	putimage_alpha(pos_img_1P.x, pos_img_1P.y, &img_1P);
	putimage_alpha(pos_img_2P.x, pos_img_2P.y, &img_2P);

	putimage_alpha(pos_img_1P_gravestone.x, pos_img_1P_gravestone.y, &img_gravestone_right);
	putimage_alpha(pos_img_2P_gravestone.x, pos_img_2P_gravestone.y, &img_gravestone_left);

	switch (player_type_1) {
	case PlayerType::Peashooter:
		animation_peashooter.on_draw(camera, pos_animation_1P.x, pos_animation_1P.y);
		pos_img_1P_name.x = pos_img_1P_gravestone.x + (img_gravestone_right.getwidth() - textwidth(str_peashooter_name)) / 2;
		outtextxy_shaded(pos_img_1P_name, str_peashooter_name);
		break;
	case PlayerType::SunFlower:
		animation_sunflower.on_draw(camera, pos_animation_1P.x, pos_animation_1P.y);
		pos_img_1P_name.x = pos_img_1P_gravestone.x + (img_gravestone_right.getwidth() - textwidth(str_sunflower_name)) / 2;
		outtextxy_shaded(pos_img_1P_name, str_sunflower_name);
		break;
	}

	switch (player_type_2) {
	case PlayerType::Peashooter:
		animation_peashooter.on_draw(camera, pos_animation_2P.x, pos_animation_2P.y);
		pos_img_2P_name.x = pos_img_2P_gravestone.x + (img_gravestone_left.getwidth() - textwidth(str_peashooter_name)) / 2;
		outtextxy_shaded(pos_img_2P_name, str_peashooter_name);
		break;
	case PlayerType::SunFlower:
		animation_sunflower.on_draw(camera, pos_animation_2P.x, pos_animation_2P.y);
		pos_img_2P_name.x = pos_img_2P_gravestone.x + (img_gravestone_left.getwidth() - textwidth(str_sunflower_name)) / 2;
		outtextxy_shaded(pos_img_2P_name, str_sunflower_name);
		break;
	}

	putimage_alpha(pos_img_1P_desc.x, pos_img_1P_desc.y, &img_1P_desc);
	putimage_alpha(pos_img_2P_desc.x, pos_img_2P_desc.y, &img_2P_desc);
	putimage_alpha(pos_img_tip.x, pos_img_tip.y, &img_selector_tip);
	
};

void SelectScene::on_update(int delta) {
	animation_peashooter.on_update(delta);
	animation_sunflower.on_update(delta);

	scan_line += 3;
	if (scan_line >= img_peashooter_selector_background_left.getwidth()) {
		scan_line = 0;
	}
}

void SelectScene::outtextxy_shaded(int x, int y, LPCTSTR str) {
	settextcolor(RGB(45, 45, 45));
	outtextxy(x + 3, y + 3, str);
	settextcolor(RGB(255, 255, 255));
	outtextxy(x, y, str);
};

void SelectScene::outtextxy_shaded(const POINT& pos, LPCTSTR str) {
	settextcolor(RGB(45, 45, 45));
	outtextxy(pos.x + 3, pos.y + 3, str);
	settextcolor(RGB(255, 255, 255));
	outtextxy(pos.x, pos.y, str);
};

void SelectScene::on_input(const ExMessage& msg) {
	if (msg.message == WM_KEYUP) {
		//A
		if (msg.vkcode == 0x41) {
			player_type_1 = SelectScene::PlayerType(((int)(player_type_1)+1) % (int)(SelectScene::PlayerType::Invalid));
		}
		//D
		if (msg.vkcode == 0x44) {
			player_type_1 = SelectScene::PlayerType(((int)(player_type_1)+1) % (int)(SelectScene::PlayerType::Invalid));
		}
		//<-
		if (msg.vkcode == 0x25) {
			player_type_2 = SelectScene::PlayerType(((int)(player_type_2)+1) % (int)(SelectScene::PlayerType::Invalid));
		}
		//->
		if (msg.vkcode == 0x27) {
			player_type_2 = SelectScene::PlayerType(((int)(player_type_2)+1) % (int)(SelectScene::PlayerType::Invalid));
		}
		if (msg.vkcode == VK_RETURN) {
			scene_manager.switch_to(SceneManager::SceneType::Game);
			mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
		}
	}
}

void SelectScene::on_exit() {
	switch (player_type_1) {
	case PlayerType::Peashooter:
		player_1 = new PeashooterPlayer();
		break;
	case PlayerType::SunFlower:
		player_1 = new SunFlowerPlayer();
	}
	player_1->set_id(PlayerID::P1);

	switch (player_type_2) {
	case PlayerType::Peashooter:
		player_2 = new PeashooterPlayer();
		break;
	case PlayerType::SunFlower:
		player_2 = new SunFlowerPlayer();
		break;
	}
	player_2->set_id(PlayerID::P2);

}