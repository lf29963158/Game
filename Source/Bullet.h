namespace game_framework {
	class Bullet
	{
	public:
		Bullet();
		int GetX();
		int GetY();
		void SetXY(int dx, int dy);
		void SetDirection(bool shootDirection);
		int GetPower();
		int GetFlytime();
		void OnShow();
		bool GetDirection();
		void AddFlytime();
		CAnimation bullet;

	private:
		int x, y;		//�y��
		int power;		//�¤O
		int flytime;	//����p��
		bool direction;	//��V
		//static vector<Bullet> _bullet;
	};
}

