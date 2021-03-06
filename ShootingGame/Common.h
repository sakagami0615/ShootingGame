#pragma once

#include "DxLibWrapper.h"


namespace common
{
	// 画面右下原点座標系から画面左上原点座標系に変換
	class CoordinateTransform{
	private:
		const Rect _game_area;
	public:
		CoordinateTransform(const Rect game_area);
		~CoordinateTransform();
		Point Translation(Point position);
	};

	// 飽和演算関数
	int Saturation(const int src, const int low, const int high);
	double Saturation(const double src, const double low, const double high);
}