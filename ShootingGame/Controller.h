#pragma once

#include "Interface.h"


class Controller_Keyinput :public ControllerInterface{
private:
	const double _speed_value;
	
	shared_ptr<KeyinputInterface> _keyinput;
	int _frame_counter;

public:
	Controller_Keyinput(shared_ptr<KeyinputInterface> keyinput, const double speed_value);
	~Controller_Keyinput();

	Point UpdatePosition(Point &current_pos);
	bool UpdateShoot();
	void UpdateCount();
};