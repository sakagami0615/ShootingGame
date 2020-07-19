#include "DxLibWrapper.h"

#include "Interface.h"
#include "Keyinput.h"
#include "Controller.h"
#include "Player.h"

#include "Common.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DxLibWrapperParameter dxlib_param;
	dxlib_param.window_size = Point(1280.0, 720.0);
	dxlib_param.window_text = "Barrage Product";

	DxLibWrapper dxlib(dxlib_param);

	shared_ptr<KeyInput> key_input(new KeyInput());

	Rect game_area(20, 40, 1000, 600);
	double player_speed = 5.0;
	shared_ptr<common::CoordinateTransform> transform(new common::CoordinateTransform(game_area));
	shared_ptr<Controller_Keyinput> controller(new Controller_Keyinput(key_input, player_speed));
	shared_ptr<Player> player(new Player(transform, controller, Point(1280/2, 720*1/4), game_area));

	list<shared_ptr<RunnerInterface>> runner;
	runner.push_back(key_input);

	while(dxlib.ProcessWindowMessage() && !dxlib.ForcedTermination()){

		for(auto &it : runner){
			it->Run();
		}
		for(auto &it : runner){
			it->Draw();
		}
		
		player->Run();
		player->Draw();
		DrawBox((int)game_area.x, (int)game_area.y, (int)game_area.x + (int)game_area.w, (int)game_area.y + (int)game_area.h, GetColor(255,255,255), FALSE);
	}

	return 0;
}
