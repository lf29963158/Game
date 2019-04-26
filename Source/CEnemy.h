#ifndef CENEMY_H
#define CENEMY_H

namespace game_framework {
	class CHero;
	class CEnemy
	{
	public:
		CEnemy();
		int  GetX1();					// 擦子左上角 x 座標
		int  GetY1();					// 擦子左上角 y 座標
		int  GetX2();					// 擦子右下角 x 座標
		int  GetY2();					// 擦子右下角 y 座標
		bool  GetAniBmp();
		void Initialize();
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow();					// 將擦子圖形貼到畫面
		void SetXY(int nx, int ny);		// 設定擦子左上角座標
		void SetDeath(bool flag);
		void SetAttack(bool flag);
		void ResetAttack();
		void IsHeroInRange(CHero &hero);
		void IsAttackRange(CHero &hero);
		void AttackCD();
	protected:
		bool isrun, isSeeHero, isAttack, isDeath, isCD;
		CAnimation enemy_stand, enemy_run, enemy_attack, enemy_death;		// 人物的動畫
		clock_t start, finish;
		int x, y;					// 擦子左上角座標
		int power;
	};
}
#endif // !CENEMY_H