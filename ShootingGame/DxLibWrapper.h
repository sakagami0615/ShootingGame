#pragma once

#include <DxLib.h>
#include <string>
#include <list>
#include <numeric>
using namespace std;


class Point{
public:
	double x;
	double y;

	Point();
	Point(double x, double y);
};


class DxLibWrapperParameter{
public:
	Point window_size;
	string window_text;
	bool window_mode_flg;

	DxLibWrapperParameter(const Point window_size = Point(DEFAULT_SCREEN_SIZE_X, DEFAULT_SCREEN_SIZE_Y), const string window_text = "DxLib Windows", const bool window_mode_flg = true);
	~DxLibWrapperParameter();
};


class DxLibWrapper{
private:
	char _key_states[256];

public:
	DxLibWrapper(DxLibWrapperParameter param = DxLibWrapperParameter());
	~DxLibWrapper();

	bool ProcessWindowMessage();
	bool ForcedTermination();
};