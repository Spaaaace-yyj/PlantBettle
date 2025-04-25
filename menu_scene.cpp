#include "menu_scene.h"

void MenuScene::on_enter() {
	mciSendString(_T("play bgm_menu repeat from 0"), NULL, 0, NULL);
}
void MenuScene::on_update(int delta) {

}
void MenuScene::on_draw(const Camera& camera) {
	putimage(0, 0, &img_menu_background);
}

void MenuScene::on_input(const ExMessage& msg) {
	if (msg.message == WM_KEYUP) {
		mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
		scene_manager.switch_to(SceneManager::SceneType::Select);
	}
}
void MenuScene::on_exit() {

}