#pragma once
#define BACKBROUND	RGB(255, 0, 0)
#define BLOOD		RGB(0, 255, 0)
namespace game_framework {
	class CHealthPoints {
	public:
		CHealthPoints();
		void ShowHP(int x,int y,int percent);
	private:
		int bar_width;
		int bar_height;
		int percent;
		int frame;
		int background;
		int blood;
	};
}
