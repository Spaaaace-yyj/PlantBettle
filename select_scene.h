#ifndef _SELECT_SCENE_H_
#define _SELECT_SCENE_H_

#include "scene.h"
#include "atlas.h"

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

class SelectScene : public Scene {
public:
	SelectScene() = default;
	~SelectScene() = default;
private:

};

#endif
