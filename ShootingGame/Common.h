#pragma once

#include "DxLibWrapper.h"


namespace common
{
	// ‰æ–Ê‰E‰ºŒ´“_À•WŒn‚©‚ç‰æ–Ê¶ãŒ´“_À•WŒn‚É•ÏŠ·
	class CoordinateTransform{
	private:
		const Rect _game_area;
	public:
		CoordinateTransform(const Rect game_area);
		~CoordinateTransform();
		Point Translation(Point position);
	};

	// –O˜a‰‰ZŠÖ”
	int Saturation(const int src, const int low, const int high);
	double Saturation(const double src, const double low, const double high);
}