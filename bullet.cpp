#include "bullet.h"

void Bullet::set_size(float width, float height) {
	this->size.x = width;
	this->size.y = height;
}

const Vector2D& Bullet::get_size() {
	return size;
}

void Bullet::set_damage(int val) {
	this->damage = val;
}

int Bullet::get_damage() {
	return damage;
}

void Bullet::set_position(float x, float y) {
	this->position.x = x;
	this->position.y = y;
}

void Bullet::set_position(const Vector2D& position) {
	this->position = position;
}

const Vector2D& Bullet::get_position() {
	return position;
}

void Bullet::set_velocity(float x, float y) {
	velocity.x = x;
	velocity.y = y;
}

void Bullet::set_collide_target(PlayerID target) {
	target_id = target;
}

void Bullet::set_callback(std::function<void()> callback) {
	this->callback = callback;
}

void Bullet::set_valid(bool val) {
	this->valid = val;
}

bool Bullet::get_valid() const{
	return this->valid;
}

bool Bullet::check_can_remove() const{
	return this->can_remove;
}

void Bullet::on_collide() {
	if (callback) {
		callback();
	}
}

bool Bullet::check_collision(const Vector2D& position, const Vector2D& size) {
	return this->position.x + this->size.x / 2 >= position.x
		&& this->position.x + this->size.x / 2 <= position.x + size.x
		&& this->position.y + this->size.y / 2 >= position.y
		&& this->position.y + this->size.y / 2 <= position.y + size.y;
}

void Bullet::on_update(int delta) {

}
void Bullet::on_draw(const Camera& camera) const {

}

bool Bullet::check_if_out_screen() {
	return (position.x >= getwidth() || position.x <= 0)
		|| (position.y >= getheight() || position.y <= 0);
}