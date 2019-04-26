#ifndef CENEMY_H
#define CENEMY_H

namespace game_framework {
	class CHero;
	class CEnemy
	{
	public:
		CEnemy();
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		bool  GetAniBmp();
		void Initialize();
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow();					// �N���l�ϧζK��e��
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
		void SetDeath(bool flag);
		void SetAttack(bool flag);
		void ResetAttack();
		void IsHeroInRange(CHero &hero);
		void IsAttackRange(CHero &hero);
		void AttackCD();
	protected:
		bool isrun, isSeeHero, isAttack, isDeath, isCD;
		CAnimation enemy_stand, enemy_run, enemy_attack, enemy_death;		// �H�����ʵe
		clock_t start, finish;
		int x, y;					// ���l���W���y��
		int power;
	};
}
#endif // !CENEMY_H