#ifndef CERASER_H
#define CERASER_H


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
	class CGameMap;
	class CEraser
	{
	public:
		CEraser();
		int  GetX1();					// 擦子左上角 x 座標
		int  GetY1();					// 擦子左上角 y 座標
		int  GetX2();					// 擦子右下角 x 座標
		int  GetY2();					// 擦子右下角 y 座標
		void Initialize();				// 設定擦子為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow();					// 將擦子圖形貼到畫面
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetShot(bool flag);
		void SetXY(int nx, int ny);		// 設定擦子左上角座標
		bool isTouchRoad(CGameMap &map, int MAPX);
		bool isTouchWall(CGameMap &map, int MAPX);
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool jumpState = false;		//人物跳躍(預設false)
		bool canJump = false;
		int cTa = 10;				//跳躍計算用
		int flytime = 0;
	protected:
		//CAnimation animation;		// 擦子的動畫
		bool workingState = true;	//人物向左(false)向右(true,預設)
		bool attackState = false;
		CAnimation working_left, working_right, leg_left, leg_right;		// 人物的動畫
		CAnimation bullet;
		int x, y;					// 擦子左上角座標
		int *bulletX, *bulletY;
	};
}
#endif // !CERASER_H