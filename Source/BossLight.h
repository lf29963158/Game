namespace game_framework {
	class BossLight
	{
	public:
		BossLight();
		int GetX();
		int GetY();
		void SetXY(int dx, int dy);
		void SetDirection(bool shootDirection);
		int GetPower();
		int GetFlytime();
		void OnShow();
		bool GetDirection();
		void AddFlytime();
		CAnimation bosslight;

	private:
		int x, y;		//座標
		int power;		//威力
		int flytime;	//飛行計算
		bool direction;	//方向
		//static vector<Bullet> _bullet;
	};
}

