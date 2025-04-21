#ifndef _ATLAS_H_
#define _ATLAS_H_

#include <graphics.h>
#include <vector>

class Atlas {
public:
	Atlas() = default;
	~Atlas() = default;

	void load_from_file(LPCTSTR path_template, int num);

	void clear();
	int get_size();
	IMAGE* get_image(int idx);
	void add_image(const IMAGE& img);

private:
	std::vector<IMAGE> img_list;
};

#endif // !_ATLAS_H_
