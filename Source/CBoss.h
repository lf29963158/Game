#ifndef CBOSS_H
#define CBOSS_H

namespace game_framework {
	class CHero;
	class BossLight;
	class CBoss
	{
	public:
		CBoss();
		int  GetX1();					// 擦子左上角 x 座標
		int  GetY1();					// 擦子左上角 y 座標
		int  GetX2();					// 擦子右下角 x 座標
		int  GetY2();					// 擦子右下角 y 座標
		bool GetAniBmp();
		void Initialize();
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow();					// 將擦子圖形貼到畫面
		void SetXY(int nx, int ny);		// 設定擦子左上角座標
		void SetDeath(bool flag);
		void SetAttack(bool flag);
		void AddLight();
		void SetLight();
		void ResetAttack();
		void IsHeroInRange(CHero &hero);
		void IsAttackRange(CHero &hero);
		void AttackCD();
	protected:
		bool isrun, isSeeHero, isAttack, isDeath, isCD, isAttactDone;
		CAnimation boss_stand, boss_attack;		// 人物的動畫
		BossLight* _light;
		clock_t start, finish;
		int x, y;					// 擦子左上角座標
		int power;
	};
}
#endif // !CENEMY_H