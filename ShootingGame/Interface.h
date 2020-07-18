#pragma once

#include "DxLibWrapper.h"
#include <memory>
using namespace std;


class RunnerInterface{
public:
	virtual ~RunnerInterface(){}
	virtual void Run() = 0;
	virtual void Draw() = 0;
};

class KeyinputInterface{
public:
	virtual ~KeyinputInterface(){}
	virtual bool GetKeyUp(const int key_code) = 0;
	virtual bool GetKeyDown(const int key_code) = 0;
	virtual bool GetKeyUpEdge(const int key_code) = 0;
	virtual bool GetKeyDownEdge(const int key_code) = 0;
};

class ControllerInterface{
public:
	virtual ~ControllerInterface(){}
	virtual Point UpdatePosition(Point &current_pos) = 0;
	virtual bool UpdateShoot() = 0;
	virtual void UpdateCount() = 0;
};

class BarrageCreateInterface{
public:
	virtual ~BarrageCreateInterface(){}
	virtual void CreateBullet(shared_ptr<ControllerInterface> controller, Point init_pos) = 0;
};

class PositionInterface{
public:
	virtual ~PositionInterface(){}
	virtual Point GetPosition() = 0;
};

class BarrageProductInterface{
public:
	virtual ~BarrageProductInterface(){}
	virtual void Shoot(shared_ptr<BarrageCreateInterface> barrage, Point source_position, shared_ptr<PositionInterface> target_object) = 0;
};


class ShootInterface{
public:
	virtual ~ShootInterface(){}
	virtual Point GetPosition() = 0;
	virtual bool GetIsShoot() = 0;
	virtual list<shared_ptr<BarrageProductInterface>> GetBarrageProducts() = 0;
};

class AttackInterface{
public:
	virtual ~AttackInterface(){}
	virtual Point GetPosition() = 0;
	virtual int GetAttackPoint() = 0;
};

class DefenseInterface{
public:
	virtual ~DefenseInterface(){}
	virtual Point GetPosition() = 0;
	virtual void HitAttackPoint(int attack_point) = 0;
};