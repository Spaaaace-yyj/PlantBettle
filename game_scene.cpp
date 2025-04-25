#include "game_scene.h"
#include <iostream>

void GameScene::on_enter() {
	std::cout << "进入游戏进行中的内界面" << std::endl;
}

void GameScene::on_draw(const Camera& camera) {
	outtextxy(10, 10, _T("渲染游戏内界面"));
}

void GameScene::on_input(const ExMessage& msg) {
	if (msg.message == WM_KEYDOWN) {
		scene_manager.switch_to(SceneManager::SceneType::Menu);
	}
}

void GameScene::on_update(int delta) {
	std::cout << "游戏运行中" << std::endl;
}

void GameScene::on_exit() {
	std::cout << "游戏界面退出" << std::endl;
}