#pragma once

#include "DxLibWrapper.h"


namespace common
{
	// ��ʉE�����_���W�n�����ʍ��㌴�_���W�n�ɕϊ�
	class CoordinateTransform{
	private:
		const Rect _game_area;
	public:
		CoordinateTransform(const Rect game_area);
		~CoordinateTransform();
		Point Translation(Point position);
	};

	// �O�a���Z�֐�
	int Saturation(const int src, const int low, const int high);
	double Saturation(const double src, const double low, const double high);
}