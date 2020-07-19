#include "Common.h"
#include <algorithm>
using namespace std;


namespace common
{
	CoordinateTransform::CoordinateTransform(const Rect game_area):_game_area(game_area){};
	CoordinateTransform::~CoordinateTransform(){};

	Point CoordinateTransform::Translation(Point position)
	{
		Point trans_position;
		trans_position.x = _game_area.x + position.x;
		trans_position.y = (_game_area.y + _game_area.h) - position.y;
		return trans_position;
	}


	int Saturation(const int src, const int low, const int high)
	{
		int dst = src;
		dst = max(dst, low);
		dst = min(dst, high);
		return dst;
	}

	double Saturation(const double src, const double low, const double high)
	{
		double dst = src;
		dst = max(dst, low);
		dst = min(dst, high);
		return dst;
	}
}