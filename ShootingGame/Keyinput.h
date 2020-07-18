#pragma once

#include "Interface.h"

class KeyInput : public RunnerInterface,public KeyinputInterface{
private:
	static const int KEY_BUF_SIZE = 256;
	char _key_states[KEY_BUF_SIZE];
	int _key_states_count[KEY_BUF_SIZE];

public:
	KeyInput();
	~KeyInput();

	bool GetKeyUp(const int key_code);
	bool GetKeyDown(const int key_code);
	bool GetKeyUpEdge(const int key_code);
	bool GetKeyDownEdge(const int key_code);
	
	void Run();
	void Draw();
};