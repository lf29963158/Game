#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "CHealthPoints.h"
#include "CEnemy.h"
#include "CHero.h"
#include "Bullet.h"
#include <math.h>
#define pi 0.017456
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CHero::CHero()
	{
		Initialize();
	}

	int CHero::GetX1()
	{
		return x;
	}

	int CHero::GetY1()
	{
		return y;
	}

	int CHero::GetX2()
	{
		//return x + working_right.Width();
		return x + 70;
	}

	int CHero::GetY2()
	{
		//return y + working_right.Height();
		return y + 70;
	}

	bool CHero::GetJumpState()
	{
		return jumpState;
	}

	void CHero::Initialize()
	{
		const int X_POS = 150;
		const int Y_POS = 50;
		initial_velocity = 10;
		velocity = initial_velocity;
		x = X_POS;
		y = Y_POS;
		blood = 100;
		hurt = 16;
		cTa = 10;
		flytime = 0;
		HP = new CHealthPoints;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isHurt = false;
	}

	void CHero::LoadBitmap()
	{
		working_right.AddBitmap(IDB_ManRight1, RGB(255, 255, 255));
		working_right.AddBitmap(IDB_ManRight2, RGB(255, 255, 255));
		working_left.AddBitmap(IDB_ManLeft1, RGB(255, 255, 255));
		working_left.AddBitmap(IDB_ManLeft2, RGB(255, 255, 255));
		leg_right.AddBitmap(IDB_LegRight1, RGB(255, 255, 255));
		leg_right.AddBitmap(IDB_LegRight2, RGB(255, 255, 255));
		leg_right.AddBitmap(IDB_LegRight3, RGB(255, 255, 255));
		leg_right.AddBitmap(IDB_LegRight4, RGB(255, 255, 255));
		leg_right.AddBitmap(IDB_LegRight5, RGB(255, 255, 255));
		leg_left.AddBitmap(IDB_LegLeft1, RGB(255, 255, 255));
		leg_left.AddBitmap(IDB_LegLeft2, RGB(255, 255, 255));
		leg_left.AddBitmap(IDB_LegLeft3, RGB(255, 255, 255));
		leg_left.AddBitmap(IDB_LegLeft4, RGB(255, 255, 255));
		leg_left.AddBitmap(IDB_LegLeft5, RGB(255, 255, 255));
		working_left.SetDelayCount(2);
		working_right.SetDelayCount(2);
		leg_left.SetDelayCount(2);
		leg_right.SetDelayCount(2);
	}
	void CHero::OnMove()
	{
		const int STEP_SIZE = 5;
		//animation.OnMove();
		if (isMovingRight) {
			x += STEP_SIZE;
			working_right.OnMove();
			leg_right.OnMove();
			workingState = true;
		}
		if (isMovingLeft) {
			x -= STEP_SIZE;
			working_left.OnMove();
			leg_left.OnMove();
			workingState = false;
		}
		
		if (jumpState) {			//¸õÅD
			cTa += 9;
			y = y - int(sin(cTa * pi) * 20);
			if (cTa >= 90) {			//µ²§ô¸õÅD
				jumpState = false;
				cTa = 10;
			}
		}

		if (attackState) {
			if (start == 0) {
				start = clock();
			}
		}

	}

	void CHero::SetAttack(bool flag)
	{
		attackState = flag;
	}

	void CHero::SetOriginVelocity()
	{
		velocity = initial_velocity;
	}

	void CHero::SetVelocity(int num)
	{
		velocity += num;
	}

	int  CHero::GetVelocity()
	{
		return velocity;
	}

	void CHero::SetIsHurt(bool flag)
	{
		isHurt = flag;
	}

	void CHero::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CHero::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CHero::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CHero::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
		if (canJump)
		{
			jumpState = true;
			canJump = false;
		}
	}

	bool CHero::GetIsMovingUp()
	{
		return isMovingUp;
	}

	void CHero::SetJumpState(bool flag)
	{
		canJump = flag;
	}

	bool CHero::GetIsMovingDown()
	{
		return isMovingDown;
	}

	bool CHero::GetIsMovingLeft()
	{
		return isMovingLeft;
	}

	bool CHero::GetIsMovingRight()
	{
		return isMovingRight;
	}

	void CHero::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CHero::SetX(int nx)
	{
		x = nx;
	}

	void CHero::SetY(int ny)
	{
		y = ny;
	}

	void CHero::isAttackEnemy(int mapX, CEnemy &enemy)
	{
		int bulletx;
		for (unsigned int i = 0; i < _bullet.size(); i++)
		{
			bulletx =_bullet[i]->GetX();
			TRACE("eeen %d %d , en %d %d %d %d\n", bulletx, _bullet[i]->GetY(), enemy.GetX1(), enemy.GetX2(), enemy.GetY1(), enemy.GetY2());
			if (bulletx > enemy.GetX1() - 10 && bulletx < enemy.GetX2() && _bullet[i]->GetY() <= enemy.GetY2() && _bullet[i]->GetY() >= enemy.GetY1())
			{
				enemy.SetDeath(true);
				Bullet* temp;
				temp = _bullet[i];
				_bullet.erase(_bullet.begin() + i);
				delete temp;
			}
		}
	}

	void CHero::AddBullet()
	{
		Bullet* temp = new Bullet;
		temp->SetXY(GetX1(), GetY1());
		temp->SetDirection(workingState);
		_bullet.push_back(temp);
		TRACE("%d\n", _bullet.size());
	}

	void CHero::SetBullet()
	{
		for (unsigned int i = 0; i < _bullet.size(); i++)
		{
			if (!(_bullet[i]->GetFlytime() >= 300)) {
				_bullet[i]->AddFlytime();
				if (_bullet[i]->GetDirection()) {
					_bullet[i]->SetXY(_bullet[i]->GetX() + 10, _bullet[i]->GetY());
				}
				else {
					_bullet[i]->SetXY(_bullet[i]->GetX() - 10, _bullet[i]->GetY());
				}
				_bullet[i]->OnShow();
			}
			else {
				Bullet* temp;
				temp = _bullet[i];
				_bullet.erase(_bullet.begin());
				delete temp;
			}
		}
	}

	bool CHero::isTouchRoad(CGameMap &map, int HEROX)
	{
		int setX = (HEROX) / 20;
		int setY = (GetY2() + 53) / 20;
		TRACE("mapvalue: %d y = %d x = %d\n", map.map[setY][setX], setY, setX);
		return (map.map[setY][setX] == 1);
	}

	bool CHero::isTouchLeftWall(CGameMap &map, int HEROX)
	{
		int setX = (HEROX) / 20;
		int setY = (GetY2()) / 20;
		TRACE("Lwall:mapvalue: %d y = %d x = %d\n", map.map[setY][setX], setY, setX);
		return (map.map[setY][setX] == 1);
	}

	bool CHero::isTouchRightWall(CGameMap &map, int HEROX)
	{
		int setX = (GetX2() - GetX1() + HEROX) / 20;
		int setY = (GetY2()) / 20;
		TRACE("Rwall:mapvalue: %d y = %d x = %d\n", map.map[setY][setX], setY, setX);
		return (map.map[setY][setX] == 1);
	}

	void CHero::OnShow()
	{
		if (isHurt && blood > 10)
		{
			blood -= hurt;
			isHurt = false;
		}
		//HP->ShowHP(x, y, blood);
		if (workingState) { //hero direction left
			leg_right.SetTopLeft(x+11, y + 53);
			working_right.SetTopLeft(x, y);
			leg_right.OnShow();
			working_right.OnShow();
		}
		else {
			leg_left.SetTopLeft(x+11, y + 53);
			working_left.SetTopLeft(x, y);
			leg_left.OnShow();
			working_left.OnShow();
		}
		
		if (attackState && finish - start >= 100) {
			start = 0;
			finish = 0;
			AddBullet();
			attackState = false;
		}
		else {
			finish = clock();
		}
		SetBullet();	
	}
}