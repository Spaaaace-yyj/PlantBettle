#include "timer.h"

void Timer::set_callback(std::function<void()> callback) {
	this->callback = callback;
}

void Timer::restart() {
	pass_time = 0;
	shotted = false;
}

void Timer::set_wait_time(int val) {
	wait_time = val;
}

void Timer::set_trigger_once(bool val) {
	trigger_once = val;
}

void Timer::pause() {
	paused = true;
}

void Timer::resume() {
	paused = true;
}

void Timer::on_update(int delta) {
	if (paused) {
		return;
	}

	pass_time += delta;

	if (pass_time >= wait_time) {
		if ((!trigger_once || (trigger_once && !shotted)) && callback) {
			callback();
		}
		shotted = true;
		pass_time = 0;
	}
}