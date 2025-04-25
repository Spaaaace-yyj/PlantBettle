#ifndef _TIMER_H_
#define _TIMER_H_

#include <functional>

class Timer {
public:
	Timer() = default;
	~Timer() = default;

	void restart();

	void set_wait_time(int val);

	void set_trigger_once(bool val);

	void set_callback(std::function<void()> callback);

	void pause();

	void resume();

	void on_update(int delta);

private:
	int pass_time = 0;	//已过时间
	int wait_time = 0;	//等待时间
	bool paused = false;	//是否暂停
	bool shotted = false;	//是否触发
	bool trigger_once = false;	//是否单词触发
	std::function<void()> callback;
};

#endif
