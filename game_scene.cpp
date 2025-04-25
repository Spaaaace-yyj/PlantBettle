#include "game_scene.h"
#include <iostream>

void GameScene::on_enter() {
	std::cout << "������Ϸ�����е��ڽ���" << std::endl;
}

void GameScene::on_draw(const Camera& camera) {
	outtextxy(10, 10, _T("��Ⱦ��Ϸ�ڽ���"));
}

void GameScene::on_input(const ExMessage& msg) {
	if (msg.message == WM_KEYDOWN) {
		scene_manager.switch_to(SceneManager::SceneType::Menu);
	}
}

void GameScene::on_update(int delta) {
	std::cout << "��Ϸ������" << std::endl;
}

void GameScene::on_exit() {
	std::cout << "��Ϸ�����˳�" << std::endl;
}