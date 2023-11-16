#pragma once
#include "Product.h"

class Speaker : public Product {
	static int speakerNum;
	string type;			// PC�����, �ϼн���Ŀ, ��Ʋ����Ʈ����Ŀ,,,
	int size;				// inch
	bool wired;				// ������ ����
public:
	static int getSpeakerNum();
	Speaker(string name, string type, int size, bool wired);
};