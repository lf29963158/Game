#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CHero.h"
#include "BossLight.h"
#include "CBoss.h"
#include <math.h>
namespace game_framework {
	CBoss::CBoss() {
		power = 10;
	}
	int CBoss::GetX1()
	{
		return x;
	}

	int CBoss::GetY1()
	{
		return y;
	}

	int CBoss::GetX2()
	{
		return x + boss_stand.Width();
	}

	int CBoss::GetY2()
	{
		return y + boss_stand.Height();
	}

	bool  CBoss::GetAniBmp()
	{
		TRACE("aniBmp %d  %d\n", boss_attack.GetCurrentBitmapNumber(), boss_attack.IsFinalBitmap());
		return boss_attack.IsFinalBitmap();
	}

	void CBoss::Initialize()
	{
		const int X_POS = 300;
		const int Y_POS = 130;
		x = X_POS;
		y = Y_POS;
		isrun = isSeeHero = isAttack = isAttactDone = isDeath = isCD = false;
		_light = NULL;
	}

	void CBoss::LoadBitmap()
	{
		boss_stand.AddBitmap(IDB_Boss_Left, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left2, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left3, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left4, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left5, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left6, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left7, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left8, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left9, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left10, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left11, RGB(255, 255, 255));
		boss_attack.AddBitmap(IDB_Boss_Left12, RGB(255, 255, 255));
		boss_attack.SetDelayCount(6);
	}

	void CBoss::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CBoss::IsHeroInRange(CHero &hero)
	{
		if ((GetX1() - hero.GetX1() < 100) && (GetX1() > hero.GetX1() + 40))
		{
			isSeeHero = true;
		}
		else
		{
			isSeeHero = false;
			if ((GetX1() - hero.GetX1() <= 100) && GetX1() > hero.GetX1())
			{
				SetAttack(true);
			}
			else
			{
				SetAttack(false);
				ResetAttack();
			}
		}
	}

	void CBoss::SetDeath(bool flag)
	{
		isDeath = flag;
	}

	void CBoss::SetAttack(bool flag)
	{
		isAttack = flag && !isCD;
	}

	void CBoss::ResetAttack()
	{
		boss_attack.Reset();
	}

	void CBoss::AddLight()
	{
		_light = new BossLight;
		_light->SetXY(GetX1(), GetY1());
		_light->SetDirection(false);
	}

	void CBoss::SetLight()
	{
		if (!(_light->GetFlytime() >= 300)) {
			_light->AddFlytime();
			if (_light->GetDirection()) {
				_light->SetXY(_light->GetX() + 10, _light->GetY());
			}
			else {
				_light->SetXY(_light->GetX() - 10, _light->GetY());
			}
			_light->OnShow();
		}
		else {
			delete _light;
			_light = NULL;
		}

	}

	void CBoss::IsAttackRange(CHero &hero)
	{
		if (GetX1() - hero.GetX1() <= 40 && GetX1() > hero.GetX1() && !isCD)
		{
			if (GetAniBmp())
			{
				hero.SetIsHurt(true);
				isCD = true;
			}
		}
		if (isCD)
		{
			AttackCD();
		}
	}

	void CBoss::AttackCD()
	{
		int static count = 0;
		if (count < 30) count += 1;
		else
		{
			count = 0;
			isCD = false;
			boss_attack.Reset();
		}
	}

	void CBoss::OnMove()
	{
		if (isDeath)
		{
			boss_stand.OnMove();
		}
		else
		{
			/*if (x > 500 || isSeeHero)
			{
				x -= 3;
				isrun = true;
				boss_stand.OnMove();
				ResetAttack();
			}
			else
			{
				isrun = false;
				boss_stand.OnMove();
			}*/
			if (isAttack)
			{
				boss_attack.OnMove();
			}
		}
		TRACE("boss %d %d\n", x, y);
	}

	void CBoss::OnShow()
	{
		if (isDeath)
		{
			boss_stand.SetTopLeft(x, y);
			boss_stand.OnShow();
		}
		else
		{
			if (isrun)
			{
				boss_stand.SetTopLeft(x, y);
				boss_stand.OnShow();
			}
			else if (isAttack)
			{
				boss_attack.SetTopLeft(x, y);
				boss_attack.OnShow();
				
			}
			else
			{
				boss_stand.SetTopLeft(x, y);
				boss_stand.OnShow();
			}
		}
		if ((boss_attack.GetCurrentBitmapNumber() + 7) == 12)
		{
			isAttactDone = true;
			AddLight();
		}
		if (isAttactDone && _light != NULL ) SetLight();
		else isAttactDone = false;
	}

}