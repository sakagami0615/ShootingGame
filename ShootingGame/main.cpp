#include "DxLibWrapper.h"

#include "Interface.h"
#include "Keyinput.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DxLibWrapperParameter dxlib_param;
	dxlib_param.window_size = Point(1280.0, 720.0);
	dxlib_param.window_text = "Barrage Product";

	DxLibWrapper dxlib(dxlib_param);

	shared_ptr<KeyInput> key_input(new KeyInput());

	list<shared_ptr<RunnerInterface>> runner;
	runner.push_back(key_input);

	while(dxlib.ProcessWindowMessage() && !dxlib.ForcedTermination()){

		if(key_input->GetKeyDownEdge(KEY_INPUT_Z)){
			int x = static_cast<int>(dxlib_param.window_size.x/2.0);
			int y = static_cast<int>(dxlib_param.window_size.y/2.0);
			int r = 10;
			DrawCircle(x, y, r, GetColor(255, 255, 255));
		}

		for(auto &it : runner){
			it->Run();
		}
		for(auto &it : runner){
			it->Draw();
		}
	}

	return 0;
}
