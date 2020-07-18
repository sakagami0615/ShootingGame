#include "Keyinput.h"
#include "Common.h"

//----------------------------------------------------------------------------------------------------
// KeyInput Begin
//----------------------------------------------------------------------------------------------------
KeyInput::KeyInput()
{
	memset(_key_states, 0, sizeof(_key_states));
	memset(_key_states_count, 0, sizeof(_key_states_count));
}
KeyInput::~KeyInput(){}

bool KeyInput::GetKeyUp(const int key_code)
{
	int sat_key_code = common::Saturation(key_code, 0, KEY_BUF_SIZE);

	if(_key_states_count[sat_key_code] > 0){
		return true;
	}
	return false;
}

bool KeyInput::GetKeyDown(const int key_code)
{
	int sat_key_code = common::Saturation(key_code, 0, KEY_BUF_SIZE);

	if(_key_states_count[sat_key_code] <= 0){
		return true;
	}
	return false;
}

bool KeyInput::GetKeyUpEdge(const int key_code)
{
	int sat_key_code = common::Saturation(key_code, 0, KEY_BUF_SIZE);

	if(_key_states_count[sat_key_code] == -1){
		return true;
	}
	return false;
}

bool KeyInput::GetKeyDownEdge(const int key_code)
{
	int sat_key_code = common::Saturation(key_code, 0, KEY_BUF_SIZE);
	
	if(_key_states_count[sat_key_code] == 1){
		return true;
	}
	return false;
}

void KeyInput::Run()
{
	GetHitKeyStateAll(_key_states);

	for(int i = 0; i < KEY_BUF_SIZE; ++i){
		if(_key_states[i]){
			if(_key_states_count[i] < 0){
				_key_states_count[i] = 0;
			}
			_key_states_count[i]++;
		}
		else{
			if(_key_states_count[i] > 0){
				_key_states_count[i] = 0;
			}
			_key_states_count[i]--;
		}

		_key_states_count[i] = common::Saturation(_key_states_count[i], INT_MIN, INT_MAX);
	}
}

void KeyInput::Draw(){}
//----------------------------------------------------------------------------------------------------
// KeyInput End
//----------------------------------------------------------------------------------------------------