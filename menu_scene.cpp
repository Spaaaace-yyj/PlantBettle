#include "menu_scene.h"

void MenuScene::on_enter() {
	std::cout << "进入主菜单" << std::endl;
}
void MenuScene::on_update() {
	std::cout << "主菜单正在运行" << std::endl;
}
void MenuScene::on_draw() {
	outtextxy(10, 10, _T("渲染主菜单"));
}
void MenuScene::on_input(const ExMessage& msg) {
	if (msg.message == WM_KEYDOWN) {
		scene_manager.switch_to(SceneManager::SceneType::Game);
	}
}
void MenuScene::on_exit() {
	std::cout << "退出主菜单" << std::endl;
}