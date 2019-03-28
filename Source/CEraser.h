#ifndef CERASER_H
#define CERASER_H


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	class CGameMap;
	class CEraser
	{
	public:
		CEraser();
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
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
		bool isTouchRoad(CGameMap &map, int MAPX);
		bool isTouchWall(CGameMap &map, int MAPX);
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool jumpState = false;		//�H�����D(�w�]false)
		bool canJump = false;
		int cTa = 10;				//���D�p���
		int flytime = 0;
	protected:
		//CAnimation animation;		// ���l���ʵe
		bool workingState = true;	//�H���V��(false)�V�k(true,�w�])
		bool attackState = false;
		CAnimation working_left, working_right, leg_left, leg_right;		// �H�����ʵe
		CAnimation bullet;
		int x, y;					// ���l���W���y��
		int *bulletX, *bulletY;
	};
}
#endif // !CERASER_H