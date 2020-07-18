#pragma once

#include <algorithm>
using namespace std;


namespace common
{
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