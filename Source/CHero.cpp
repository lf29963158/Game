#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "CHero.h"
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

	void CHero::Initialize()
	{
		const int X_POS = 150;
		const int Y_POS = 50;
		initial_velocity = 10;
		velocity = initial_velocity;
		x = X_POS;
		y = Y_POS;
		bulletY = NULL;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
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
		bullet.AddBitmap(IDB_BULLET,RGB(255,255,255));
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

		/*else if (isMovingDown)
			y += STEP_SIZE;*/
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
			rising = true;
			canJump = false;
		}
	}

	bool CHero::GetIsMovingUp()
	{
		return isMovingUp;
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

	void CHero::SetShot(bool flag)
	{
		attackState = flag;
		bulletX = new int;
		bulletY = new int;
		*bulletX = x;
		*bulletY = y;
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
		if (workingState) {
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
		
		if (attackState)
		{
			
			flytime += 10;
			if (workingState)
			{
				bullet.SetTopLeft(*bulletX + 33 + flytime, *bulletY + 33);
				bullet.OnShow();
			}
			else
			{
				bullet.SetTopLeft(*bulletX + 33 - flytime, *bulletY + 33);
				bullet.OnShow();
			}
			if (flytime >= 250)
			{
				attackState = false;
				delete bulletX;
				delete bulletY;
				bulletX = NULL;
				bulletY = NULL;
				flytime = 0;
			}
		}
		
	}

}