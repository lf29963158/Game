#ifndef CHERO_H
#define CHERO_H

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	class CHealthPoints;
	class CGameMap;
	class CEnemy;
	class CBoss;
	class Bullet;
	class CHero
	{
	public:
		CHero();
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		bool GetIsMovingUp();
		bool GetIsMovingDown();
		bool GetIsMovingLeft();
		bool GetIsMovingRight();
		bool GetJumpState();
		int  GetVelocity();
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow();					// �N���l�ϧζK��e��
		void SetAttack(bool flag);
		void SetOriginVelocity();
		void SetVelocity(int num);
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetJumpState(bool flag);
		void SetIsHurt(bool flag);
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
		void SetX(int nx);
		void SetY(int ny);
		void AddBullet();
		void SetBullet();
		void isAttackEnemy(int mapX, CEnemy &enemy);
		bool isTouchRoad(CGameMap &map, int HEROX);
		bool isTouchLeftWall(CGameMap &map, int HEROX);
		bool isTouchRightWall(CGameMap &map, int HEROX);
		
		
	protected:
		//CAnimation animation;		// ���l���ʵe
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isHurt;
		bool workingState = true;	//�H���V��(false)�V�k(true,�w�])
		bool attackState = false;
		bool jumpState = false;		//�H�����D(�w�]false)
		bool canJump = false;
		CAnimation working_left, working_right, leg_left, leg_right;		// �H�����ʵe
		vector<Bullet*> _bullet;
		clock_t start, finish;
		CHealthPoints *HP;
		int x, y;					// ���l���W���y��
		int blood, hurt;
		int velocity;
		int initial_velocity;
		int cTa;				//���D�p���
		int flytime;
		
	};
}
#endif // !CHERO_H