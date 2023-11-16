#pragma once
#include "Product.h"

class Monitor : public Product {
	static int monitorNum;
	int size;				// inch
	string ratio;			// 16:9, 16:10, 21:9,,,
	string resolution;		// FHD, QHD,,,
	int refreshRate;		// HZ
public:
	static int getmonitorNum();
	Monitor(string name, int size, string ratio, string resolution, int refreshRate);
};
