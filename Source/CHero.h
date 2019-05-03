#ifndef CHERO_H
#define CHERO_H

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
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
		int  GetX1();					// 擦子左上角 x 座標
		int  GetY1();					// 擦子左上角 y 座標
		int  GetX2();					// 擦子右下角 x 座標
		int  GetY2();					// 擦子右下角 y 座標
		bool GetIsMovingUp();
		bool GetIsMovingDown();
		bool GetIsMovingLeft();
		bool GetIsMovingRight();
		bool GetJumpState();
		int  GetVelocity();
		void Initialize();				// 設定擦子為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow();					// 將擦子圖形貼到畫面
		void SetAttack(bool flag);
		void SetOriginVelocity();
		void SetVelocity(int num);
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetJumpState(bool flag);
		void SetIsHurt(bool flag);
		void SetXY(int nx, int ny);		// 設定擦子左上角座標
		void SetX(int nx);
		void SetY(int ny);
		void AddBullet();
		void SetBullet();
		void isAttackEnemy(int mapX, CEnemy &enemy);
		bool isTouchRoad(CGameMap &map, int HEROX);
		bool isTouchLeftWall(CGameMap &map, int HEROX);
		bool isTouchRightWall(CGameMap &map, int HEROX);
		
		
	protected:
		//CAnimation animation;		// 擦子的動畫
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool isHurt;
		bool workingState = true;	//人物向左(false)向右(true,預設)
		bool attackState = false;
		bool jumpState = false;		//人物跳躍(預設false)
		bool canJump = false;
		CAnimation working_left, working_right, leg_left, leg_right;		// 人物的動畫
		vector<Bullet*> _bullet;
		clock_t start, finish;
		CHealthPoints *HP;
		int x, y;					// 擦子左上角座標
		int blood, hurt;
		int velocity;
		int initial_velocity;
		int cTa;				//跳躍計算用
		int flytime;
		
	};
}
#endif // !CHERO_H