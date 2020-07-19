#pragma once

#include "Interface.h"
#include "Common.h"


class Player : public AttackInterface, public DefenseInterface, public ShootInterface{
private:
	const Rect _game_area;

	Point _pos;
	int _hit_point;
	int _atack_point;
	bool _is_shoot;
	shared_ptr<common::CoordinateTransform> _transform;
	shared_ptr<ControllerInterface> _controller;
	list<shared_ptr<BarrageProductInterface>> _products;

public:
	Player(shared_ptr<common::CoordinateTransform> transform, shared_ptr<ControllerInterface> controller, Point init_pos, const Rect game_area);
	~Player();

	list<shared_ptr<BarrageProductInterface>> GetBarrageProducts();
	Point GetPosition();
	bool GetIsShoot();
	
	int GetAttackPoint();
	void HitAttackPoint(int attack_point);

	void Run();
	void Draw();
};