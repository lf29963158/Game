#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "BossLight.h"

namespace game_framework {
	BossLight::BossLight()
	{
		bosslight.AddBitmap(IDB_Boss_Light, RGB(255, 255, 255));
		power = 10;
		flytime = 0;
	}
	int BossLight::GetX()
	{
		return x;
	}
	int BossLight::GetY()
	{
		return y;
	}
	bool BossLight::GetDirection()
	{
		return direction;
	}
	void BossLight::SetXY(int dx, int dy)
	{
		x = dx;
		y = dy;
	}

	void BossLight::SetDirection(bool shootDirection)
	{
		direction = shootDirection;
	}

	int BossLight::GetPower()
	{
		return power;
	}
	int BossLight::GetFlytime()
	{
		return flytime;
	}
	void BossLight::AddFlytime()
	{
		flytime += 10;
	}

	void BossLight::OnShow()
	{
		if (direction)	bosslight.SetTopLeft(x + 22, y + 33);
		else bosslight.SetTopLeft(x - 11, y + 33);
		bosslight.OnShow();
	}
}