#ifndef CBOSS_H
#define CBOSS_H

namespace game_framework {
	class CHero;
	class BossLight;
	class CBoss
	{
	public:
		CBoss();
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		bool GetAniBmp();
		void Initialize();
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow();					// �N���l�ϧζK��e��
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
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
		CAnimation boss_stand, boss_attack;		// �H�����ʵe
		BossLight* _light;
		clock_t start, finish;
		int x, y;					// ���l���W���y��
		int power;
	};
}
#endif // !CENEMY_H