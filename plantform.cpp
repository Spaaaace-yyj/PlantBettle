#include "plantform.h"

void Plantform::on_draw(const Camera &camera) const{
	putimage_alpha(camera, render_position, img);
}