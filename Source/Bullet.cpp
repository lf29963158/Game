#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Bullet.h"

namespace game_framework {
	Bullet::Bullet()
	{
		bullet.AddBitmap(IDB_BULLET, RGB(255, 255, 255));
		power = 10;
		flytime = 0;
	}
	int Bullet::GetX()
	{
		return x;
	}
	int Bullet::GetY()
	{
		return y;
	}
	bool Bullet::GetDirection()
	{
		return direction;
	}
	void Bullet::SetXY(int dx, int dy)
	{
		x = dx;
		y = dy;
	}

	void Bullet::SetDirection(bool shootDirection)
	{
		direction = shootDirection;
	}

	int Bullet::GetPower()
	{
		return power;
	}
	int Bullet::GetFlytime()
	{
		return flytime;
	}
	void Bullet::AddFlytime()
	{
		flytime += 10;
	}

	void Bullet::OnShow()
	{
		if (direction)	bullet.SetTopLeft(x + 22, y + 33);
		else bullet.SetTopLeft(x - 11, y + 33);
		bullet.OnShow();
	}
}