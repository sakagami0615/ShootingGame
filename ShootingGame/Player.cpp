#include "Player.h"

//----------------------------------------------------------------------------------------------------
// Player Begin
//----------------------------------------------------------------------------------------------------
Player::Player(shared_ptr<common::CoordinateTransform> transform, shared_ptr<ControllerInterface> controller, Point init_pos, const Rect game_area):
	_game_area(game_area),
	_transform(transform),
	_controller(controller),
	_pos(init_pos),
	_hit_point(1),
	_atack_point(1),
	_is_shoot(false)
{}
Player::~Player(){}

Point Player::GetPosition()
{
	return _pos;
}

bool Player::GetIsShoot()
{
	return _is_shoot;
}

list<shared_ptr<BarrageProductInterface>> Player::GetBarrageProducts()
{
	return _products;
}

int Player::GetAttackPoint()
{
	return _atack_point;
}
void Player::HitAttackPoint(int attack_point)
{
	_hit_point -= attack_point;
}

void Player::Run()
{
	// 位置情報更新
	Point update_pos = _controller->UpdatePosition(_pos);
	// はみ出し防止処理
	update_pos.x = common::Saturation(update_pos.x, 0.0, _game_area.w);
	update_pos.y = common::Saturation(update_pos.y, 0.0, _game_area.h);
	_pos = update_pos;
	
	// 弾射出
	bool update_shoot = _controller->UpdateShoot();
	_is_shoot = update_shoot;

	// コントローラ更新処理
	_controller->UpdateCount();
}

void Player::Draw()
{
	Point trans_pos = _transform->Translation(_pos);
	// test Draw

	int cx = (int)trans_pos.x;
	int cy = (int)trans_pos.y;
	int w = 20;
	DrawBox(cx - w/2, cy - w/2, cx + w/2, cy + w/2, GetColor(255, 255, 255), false);
}
//----------------------------------------------------------------------------------------------------
// Player End
//----------------------------------------------------------------------------------------------------