#ifndef _SELECT_SCENE_H_
#define _SELECT_SCENE_H_

#include "scene.h"
#include "scene_manager.h"
#include "animation.h"
#include "util.h"
#include <easyx.h>

#include <iostream>

extern IMAGE img_VS;									
extern IMAGE img_1P;									
extern IMAGE img_2P;									
extern IMAGE img_1P_desc;								
extern IMAGE img_2P_desc;								
extern IMAGE img_gravestone_left;						
extern IMAGE img_gravestone_right;						
extern IMAGE img_selector_tip;							
extern IMAGE img_selector_background;					
extern IMAGE img_1P_selector_btn_idle_left;			
extern IMAGE img_1P_selector_btn_idle_right;			
extern IMAGE img_1P_selector_btn_down_left;			
extern IMAGE img_1P_selector_btn_down_right;			
extern IMAGE img_2P_selector_btn_idle_left;			
extern IMAGE img_2P_selector_btn_idle_right;			
extern IMAGE img_2P_selector_btn_down_left;	
extern IMAGE img_2P_selector_btn_down_right;			
extern IMAGE img_peashooter_selector_background_left;	
extern IMAGE img_peashooter_selector_background_right;	
extern IMAGE img_sunflower_selector_background_left;	
extern IMAGE img_sunflower_selector_background_right;

extern Atlas atlas_peashooter_idle_right;
extern Atlas atlas_sunflower_idle_right;

extern IMAGE img_avatar_peashooter;					
extern IMAGE img_avatar_sunflower;		

extern SceneManager scene_manager;

class SelectScene : public Scene {
public:
	SelectScene() = default;
	~SelectScene() = default;

	void on_enter();

	void on_draw(const Camera& camera);

	void on_update(int delta);

	void on_input(const ExMessage& msg);

	void outtextxy_shaded(int x, int y, LPCTSTR str);

	void outtextxy_shaded(const POINT& pos, LPCTSTR str);

private:
	enum class PlayerType {
		Peashooter = 0,
		SunFlower,
		Invalid
	};

private:

	int scan_line = 0;

	POINT pos_img_vs = { 0 };					//vsͼƬλ��
	POINT pos_img_tip = { 0 };					//tips��Ϣ�ı���λ��
	POINT pos_img_1P = { 0 };					//1P �ı�ͼƬ��λ��
	POINT pos_img_2P = { 0 };					//2P �ı�ͼƬλ��
	POINT pos_img_1P_desc = { 0 };				//1P ��λ����ͼƬλ��
	POINT pos_img_2P_desc = { 0 };				//2P ��λ����ͼƬλ��
	POINT pos_img_1P_name = { 0 };				//1P ��ɫ�����ı�λ��
	POINT pos_img_2P_name = { 0 };				//2P ��ɫ�����ı�λ��
	POINT pos_animation_1P = { 0 };			//1P ��ɫ����λ��
	POINT pos_animation_2P = { 0 };			//2P ��ɫ����λ��
	POINT pos_img_1P_gravestone = { 0 };		//1P ��ɫĹ��
	POINT pos_img_2P_gravestone = { 0 };		//2P ��ɫĹ��
	POINT pos_1P_selector_btn_left = { 0 };	//1P �����л���ťλ��
	POINT pos_1P_selector_btn_right = { 0 };	//1P �����л���ťλ��
	POINT pos_2P_selector_btn_left = { 0 };	//2P �����л���ťλ��
	POINT pos_2P_selector_btn_right = { 0 };	//2P �����л���ťλ��

	Animation animation_peashooter;
	Animation animation_sunflower;

	PlayerType player_type_1 = PlayerType::Peashooter;
	PlayerType player_type_2 = PlayerType::Peashooter;

	LPCTSTR str_peashooter_name = _T("������");
	LPCTSTR str_sunflower_name = _T("���տ�");

private:
	IMAGE img_peashooter_selector_background_left_extern;
	IMAGE img_peashooter_selector_background_right_extern;
	IMAGE img_sunflower_selector_background_left_extern;
	IMAGE img_sunflower_selector_background_right_extern;
};

#endif
