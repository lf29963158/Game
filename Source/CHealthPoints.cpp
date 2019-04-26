#include "stdafx.h"
#include "MainFrm.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CHealthPoints.h"


namespace game_framework {
	CHealthPoints::CHealthPoints()
	{
		bar_height = 15;
		bar_width  = 80;
	}
	void CHealthPoints::ShowHP(int x, int y, int percent)
	{
		const int x1 = x - 10;
		const int x2 = x1 + bar_width;
		const int y1 = y - 20;
		const int y2 = y1 + bar_height;
		const int pen_width = bar_height / 8;
		const int progress_x1 = x1 + pen_width;
		const int progress_x2 = progress_x1 + percent * (bar_width - 2 * pen_width) / 100;
		const int progress_x2_end = x2 - pen_width;
		const int progress_y1 = y1 + pen_width;
		const int progress_y2 = y2 - pen_width;
		CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 

		CBrush *pb, b(RGB(192, 192, 192));				// 畫灰色 progress框
		pb = pDC->SelectObject(&b);
		pDC->Rectangle(x1, y1, x2, y2);
		CBrush b1(BACKBROUND);				// 畫紅色 progrss中心
		pDC->SelectObject(&b1);
		pDC->Rectangle(progress_x1, progress_y1, progress_x2_end, progress_y2);

		CBrush b2(BLOOD);					// 畫綠色 progrss進度
		pDC->SelectObject(&b2);
		pDC->Rectangle(progress_x1, progress_y1, progress_x2, progress_y2);

		pDC->SelectObject(pb);						// 釋放 brush
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
		
	}


}

