#include "stdafx.h"
#include "NotesEnum.h"
#include "PaintHelper.h"


void CPaintHelper::Message(CPaintDC& dc, CRect *rect)
{
	dc.DrawText(_T("Hello, MFC"), -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

}

void CPaintHelper::Lines(CPaintDC& dc, CRect *rect, int count)
{
	CPen pen(PS_SOLID, 0, RGB(255, 255, 255));
	CPoint points[2];

	int line_offset = 0;

	for (int i = 1; i <= count; i++){
		points[0] = CPoint(rect->left, rect->Height() / (count + 1) * i - line_offset);
		points[1] = CPoint(rect->right, rect->Height() / (count +1) * i - line_offset);
		dc.Polyline(points, 2);

	}
}

	void CPaintHelper::Note(CPaintDC& dc, CRect *rect, Notes num)
	{
		int offset = (KEY_NUMBER - num) * 10;
//		offset += (num == Do) ? 30 : 36;

		switch (num){
		case Do:
			offset += DO_OFF;
			break;
		case Re:
			offset += RE_OFF;
			break;
		case Mi:
			offset += MI_OFF;
			break;
		case Fa:
			offset += FA_OFF;
			break;
		case Sol:
			offset += SOL_OFF;
			break;
		case La:
			offset += LA_OFF;
			break;
		case Si:
			offset += SI_OFF;
			break;
		default:
			offset += 40;
			break;
		case Do2:
			offset += DO2_OFF;
			break;
		case Re2:
			offset += RE2_OFF;
			break;
		case Mi2:
			offset += MI2_OFF;
			break;
		case Fa2:
			offset += FA2_OFF;
			break;
		case Sol2:
			offset += SOL2_OFF;
			break;
		case La2:
			offset += LA2_OFF;
			break;
		case Si2:
			offset += SI2_OFF;
			break;


		}
		
		auto brush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(dc, brush);


		dc.Ellipse(rect->left + 50, offset, rect->left + 50 + 10, offset + 10);

	}
	/*
	points[0] = CPoint(0, rect->bottom/5);
	points[1] = CPoint(150,rect->bottom/5);
	dc.Polyline(points, 2);
	points[0] = CPoint(0, rect->bottom / 5 *2);
	points[1] = CPoint(150, rect->bottom / 5 * 2);
	dc.Polyline(points, 2);
	points[0] = CPoint(0, rect->bottom / 5 * 3);
	points[1] = CPoint(150, rect->bottom / 5 * 3);
	dc.Polyline(points, 2);
	*/



