#include "DxLibWrapper.h"

//----------------------------------------------------------------------------------------------------
// Point Begin
//----------------------------------------------------------------------------------------------------
Point::Point():x(0.0), y(0.0){};
Point::Point(double x, double y):x(x), y(y){};
//----------------------------------------------------------------------------------------------------
// Point End
//----------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------
// DxLibWrapperParameter Begin
//----------------------------------------------------------------------------------------------------
DxLibWrapperParameter::DxLibWrapperParameter(const Point window_size, const string window_text, const bool window_mode_flg):
	window_size({DEFAULT_SCREEN_SIZE_X, DEFAULT_SCREEN_SIZE_Y}),
	window_text(window_text),
	window_mode_flg(window_mode_flg)
{}

DxLibWrapperParameter::~DxLibWrapperParameter(){}
//----------------------------------------------------------------------------------------------------
// DxLibWrapperParameter End
//----------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------
// DxLibWrapper Begin
//----------------------------------------------------------------------------------------------------
DxLibWrapper::DxLibWrapper(DxLibWrapperParameter param)
{
	SetGraphMode(static_cast<int>(param.window_size.x), static_cast<int>(param.window_size.y), 16);
	ChangeWindowMode(param.window_mode_flg);
	SetWindowText(param.window_text.c_str());

	if(DxLib_Init()==-1){
		exit(EXIT_FAILURE);
	}

	SetDrawScreen(DX_SCREEN_BACK);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);

	memset(_key_states, 0, sizeof(_key_states));
}

DxLibWrapper::~DxLibWrapper()
{
	if(DxLib_End()==-1){
		exit(EXIT_FAILURE);
	}
}

bool DxLibWrapper::ProcessWindowMessage()
{
	if(ScreenFlip() == -1){
		return false;
	}
	if(ProcessMessage() == -1){
		return false;
	}
	if(ClearDrawScreen() == -1){
		return false;
	}
	if(GetHitKeyStateAll(_key_states) == -1){
		return false;
	}

	return true;
}

bool DxLibWrapper::ForcedTermination()
{
	list<int> key_states;

	key_states.push_back(_key_states[KEY_INPUT_LCONTROL]);
	key_states.push_back(_key_states[KEY_INPUT_LALT]);
	key_states.push_back(_key_states[KEY_INPUT_C]);

	if(accumulate(key_states.begin(), key_states.end(), 0) >= static_cast<int>(key_states.size())){
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------------------------------
// DxLibWrapper End
//----------------------------------------------------------------------------------------------------