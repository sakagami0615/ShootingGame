#include "DxLibWrapper.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DxLibWrapperParameter dxlib_param;
	dxlib_param.window_size = Point(1280.0, 720.0);
	dxlib_param.window_text = "Barrage Product";

	DxLibWrapper dxlib(dxlib_param);


	while(dxlib.ProcessWindowMessage() && !dxlib.ForcedTermination()){

		int x = static_cast<int>(dxlib_param.window_size.x/2.0);
		int y = static_cast<int>(dxlib_param.window_size.y/2.0);
		int r = 10;
		DrawCircle(x, y, r, GetColor(255, 255, 255));
	}

	return 0;
}
