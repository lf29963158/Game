#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CHero.h"
#include "CEnemy.h"
#include <math.h>
namespace game_framework {
	CEnemy::CEnemy() {
		power = 10;
	}
	int CEnemy::GetX1()
	{
		return x;
	}

	int CEnemy::GetY1()
	{
		return y;
	}

	int CEnemy::GetX2()
	{
		return x + enemy_stand.Width();
	}

	int CEnemy::GetY2()
	{
		return y + enemy_stand.Height();
	}

	bool  CEnemy::GetAniBmp()
	{
		TRACE("aniBmp %d  %d\n", enemy_attack.GetCurrentBitmapNumber(), enemy_attack.IsFinalBitmap());
		return enemy_attack.IsFinalBitmap();
	}

	void CEnemy::Initialize()
	{
		const int X_POS = 700;
		const int Y_POS = 260;
		x = X_POS;
		y = Y_POS;
		isrun = isSeeHero = isAttack = isDeath = isCD = false;
	}

	void CEnemy::LoadBitmap()
	{
		enemy_stand.AddBitmap(IDB_ENEMY_LEFT, RGB(255, 255, 255));
		enemy_stand.AddBitmap(IDB_ENEMY_LEFT2, RGB(255, 255, 255));
		enemy_stand.AddBitmap(IDB_ENEMY_LEFT3, RGB(255, 255, 255));
		enemy_stand.AddBitmap(IDB_ENEMY_LEFT4, RGB(255, 255, 255));
		enemy_stand.AddBitmap(IDB_ENEMY_LEFT5, RGB(255, 255, 255));
		enemy_stand.AddBitmap(IDB_ENEMY_LEFT6, RGB(255, 255, 255));
		enemy_run.AddBitmap(IDB_ENEMY_RUN, RGB(255, 255, 255));
		enemy_run.AddBitmap(IDB_ENEMY_RUN2, RGB(255, 255, 255));
		enemy_run.AddBitmap(IDB_ENEMY_RUN3, RGB(255, 255, 255));
		enemy_run.AddBitmap(IDB_ENEMY_RUN4, RGB(255, 255, 255));
		enemy_run.AddBitmap(IDB_ENEMY_RUN5, RGB(255, 255, 255));
		enemy_run.AddBitmap(IDB_ENEMY_RUN6, RGB(255, 255, 255));
		enemy_attack.AddBitmap(IDB_ENEMY_ATTACK, RGB(255, 255, 255));
		enemy_attack.AddBitmap(IDB_ENEMY_ATTACK2, RGB(255, 255, 255));
		enemy_attack.AddBitmap(IDB_ENEMY_ATTACK3, RGB(255, 255, 255));
		enemy_attack.AddBitmap(IDB_ENEMY_ATTACK4, RGB(255, 255, 255));
		enemy_death.AddBitmap(IDB_ENEMY_DEATH, RGB(255, 255, 255));
		enemy_death.AddBitmap(IDB_ENEMY_DEATH2, RGB(255, 255, 255));
		enemy_death.AddBitmap(IDB_ENEMY_DEATH3, RGB(255, 255, 255));
		enemy_death.AddBitmap(IDB_ENEMY_DEATH4, RGB(255, 255, 255));
		enemy_death.AddBitmap(IDB_ENEMY_DEATH5, RGB(255, 255, 255));
		enemy_death.AddBitmap(IDB_ENEMY_DEATH6, RGB(255, 255, 255));
		enemy_death.AddBitmap(IDB_ENEMY_DEATH7, RGB(255, 255, 255));
		enemy_death.AddBitmap(IDB_ENEMY_DEATH8, RGB(255, 255, 255));
		enemy_death.AddBitmap(IDB_ENEMY_DEATH9, RGB(255, 255, 255));
		enemy_run.SetDelayCount(5);
		enemy_attack.SetDelayCount(6);
	}

	void CEnemy::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CEnemy::IsHeroInRange(CHero &hero)
	{
		if ((GetX1() - hero.GetX1() < 300) && (GetX1() > hero.GetX1() + 40))
		{
			isSeeHero = true;
		}
		else
		{
			isSeeHero = false;
			if ((GetX1() - hero.GetX1() <= 40) && GetX1() > hero.GetX1())
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

	void CEnemy::SetDeath(bool flag)
	{
		isDeath = flag;
	}

	void CEnemy::SetAttack(bool flag)
	{
		isAttack = flag && !isCD;
	}

	void CEnemy::ResetAttack()
	{
		enemy_attack.Reset();
	}

	void CEnemy::IsAttackRange(CHero &hero)
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

	void CEnemy::AttackCD()
	{
		int static count = 0;
		if (count < 30) count += 1;
		else
		{
			count = 0;
			isCD = false;
			enemy_attack.Reset();
		}
	}

	void CEnemy::OnMove()
	{
		if (isDeath)
		{
			enemy_death.OnMove();
		}
		else
		{
			if (x > 500 || isSeeHero)
			{
				x -= 3;
				isrun = true;
				enemy_run.OnMove();
				ResetAttack();
			}
			else
			{
				isrun = false;
				enemy_stand.OnMove();
			}
			if (isAttack)
			{
				enemy_attack.OnMove();
			}
		}
		TRACE("enemy %d %d\n", x, y);
	}

	void CEnemy::OnShow()
	{
		if (isDeath)
		{
			enemy_death.SetTopLeft(x, y);
			enemy_death.OnShow();
		}
		else
		{
			if (isrun)
			{
				enemy_run.SetTopLeft(x, y);
				enemy_run.OnShow();
			}
			else if (isAttack)
			{
				enemy_attack.SetTopLeft(x, y - 50);
				enemy_attack.OnShow();
			}
			else
			{
				enemy_stand.SetTopLeft(x, y);
				enemy_stand.OnShow();
			}
		}
	}

}