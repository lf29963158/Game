#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "CEraser.h"
#include <math.h>
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CEraser::CEraser()
	{
		Initialize();
	}

	int CEraser::GetX1()
	{
		return x;
	}

	int CEraser::GetY1()
	{
		return y;
	}

	int CEraser::GetX2()
	{
		return x + working_right.Width();
	}

	int CEraser::GetY2()
	{
		return y + working_right.Height();
	}

	void CEraser::Initialize()
	{
		const int X_POS = 150;
		const int Y_POS = 50;
		x = X_POS;
		y = Y_POS;
		bulletY = NULL;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void CEraser::LoadBitmap()
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
	void CEraser::OnMove()
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
		
		if (isMovingUp) {
			if (canJump)
			{
				jumpState = true;
				canJump = false;
			}
		}
		else if (isMovingDown)
			y += STEP_SIZE;
	}

	void CEraser::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CEraser::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CEraser::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CEraser::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CEraser::SetShot(bool flag)
	{
		attackState = flag;
		bulletX = new int;
		bulletY = new int;
		*bulletX = x;
		*bulletY = y;
	}

	void CEraser::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	bool CEraser::isTouchRoad(CGameMap &map, int MAPX)
	{
		int setX = (GetX2() + MAPX + 5) / 20;
		int setY = (GetY2() + 53) / 20;
		TRACE("mapvalue: %d y = %d x = %d\n", map.map[setY][setX], setY, setX);
		return (map.map[setY][setX] == 1);
	}

	/*bool CEraser::isTouchWall(CGameMap &map, int MAPX)
	{
		int setX = (GetX2() + MAPX + 5) / 20;
		int setY = (GetY2() + 53) / 20;
		TRACE("mapvalue: %d y = %d x = %d\n", map.map[setY][setX], setY, setX);
		return (map.map[setY][setX] == 1);
	}*/
	void CEraser::OnShow()
	{
		if (jumpState) {			//¸õÅD
			cTa += 3;
			if (workingState) {
				y = y - int(sin(cTa) * 200);
				leg_right.SetTopLeft(x+11, y+53);
				working_right.SetTopLeft(x, y);
				leg_right.OnShow();
				working_right.OnShow();
			}
			else {
				y = y - int(sin(cTa) * 200);
				leg_left.SetTopLeft(x+11, y+53);
				working_left.SetTopLeft(x, y);
				leg_left.OnShow();
				working_left.OnShow();
			}
			if (cTa >= 80) {			//µ²§ô¸õÅD
				jumpState = false;
				cTa = 10;
			}
		}
		else {
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
				bulletX = NULL;
				bulletY = NULL;
				delete bulletX;
				delete bulletY;
				flytime = 0;
			}
		}
		
	}

}