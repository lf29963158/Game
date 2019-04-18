#ifndef CHERO_H
#define CHERO_H


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	class CGameMap;
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
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow();					// �N���l�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetShot(bool flag);
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
		void SetX(int nx);
		void SetY(int ny);
		bool isTouchRoad(CGameMap &map, int HEROX);
		bool isTouchLeftWall(CGameMap &map, int HEROX);
		bool isTouchRightWall(CGameMap &map, int HEROX);
		//---test
		bool rising = false;
		//---
		bool jumpState = false;		//�H�����D(�w�]false)
		bool canJump = false;
		int cTa = 10;				//���D�p���
		int flytime = 0;
		int velocity;
		int initial_velocity;
	protected:
		//CAnimation animation;		// ���l���ʵe
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool workingState = true;	//�H���V��(false)�V�k(true,�w�])
		bool attackState = false;
		CAnimation working_left, working_right, leg_left, leg_right;		// �H�����ʵe
		CAnimation bullet;
		int x, y;					// ���l���W���y��
		int *bulletX, *bulletY;
		
	};
}
#endif // !CHERO_H