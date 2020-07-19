#include "Controller.h"
#include "Common.h"

//----------------------------------------------------------------------------------------------------
// Controller_Keyinput Begin
//----------------------------------------------------------------------------------------------------
Controller_Keyinput::Controller_Keyinput(shared_ptr<KeyinputInterface> keyinput, const double speed_value):
	_speed_value(speed_value),
	_keyinput(keyinput),
	_frame_counter(0)
{}
Controller_Keyinput::~Controller_Keyinput(){}

Point Controller_Keyinput::UpdatePosition(Point &current_pos)
{
	bool is_input_up    = _keyinput->GetKeyDown(KEY_INPUT_UP);
	bool is_input_down  = _keyinput->GetKeyDown(KEY_INPUT_DOWN);
	bool is_input_left  = _keyinput->GetKeyDown(KEY_INPUT_LEFT);
	bool is_input_right = _keyinput->GetKeyDown(KEY_INPUT_RIGHT);
	bool is_input_lsift = _keyinput->GetKeyDown(KEY_INPUT_LSHIFT);

	bool is_input_lon = (is_input_up || is_input_down);
	bool is_input_lat = (is_input_left || is_input_right);

	double norm_value = 1.0;

	// Œ¸‘¬Žž‚ÌˆÚ“®—Êƒmƒ‹ƒ€ŒvŽZ
	if(is_input_lsift){
		norm_value /= 2.0;
	}
	// ŽÎ‚ßˆÚ“®Žž‚ÌˆÚ“®—Êƒmƒ‹ƒ€ŒvŽZ
	if(is_input_lon && is_input_lat){
		norm_value /= sqrt(2.0);
	}

	// ƒL[“ü—Í‚É‚æ‚éˆÚ“®
	Point next_pos = current_pos;
	if(is_input_up){
		next_pos.y += (_speed_value*norm_value);
	}
	if(is_input_down){
		next_pos.y -= (_speed_value*norm_value);
	}
	if(is_input_left){
		next_pos.x -= (_speed_value*norm_value);
	}
	if(is_input_right){
		next_pos.x += (_speed_value*norm_value);
	}

	return next_pos;
};

bool Controller_Keyinput::UpdateShoot()
{
	bool is_input_z = _keyinput->GetKeyDown(KEY_INPUT_Z);

	return is_input_z;
}

void Controller_Keyinput::UpdateCount()
{
	_frame_counter++;
	_frame_counter = common::Saturation(_frame_counter, 0, INT_MAX);
};
//----------------------------------------------------------------------------------------------------
// Controller_Keyinput End
//----------------------------------------------------------------------------------------------------