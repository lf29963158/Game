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
		int x, y;		//�y��
		int power;		//�¤O
		int flytime;	//����p��
		bool direction;	//��V
		//static vector<Bullet> _bullet;
	};
}

