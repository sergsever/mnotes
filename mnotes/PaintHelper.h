#pragma once

const int DO_OFF = 0;//70;
const int RE_OFF = 0;//70;
const int MI_OFF = 5;//75;
const int FA_OFF = 2;//72;
const int SOL_OFF = 1;//71;
const int LA_OFF = 0;//70;
const int SI_OFF = -3;//67;
const int DO2_OFF = -3;
const int RE2_OFF = -6;
const int MI2_OFF = -7;
const int FA2_OFF = -10;
const int SOL2_OFF = -5;
const int LA2_OFF = 0;
const int SI2_OFF = 0;


class CPaintHelper
{
public:
	static void CPaintHelper::Message(CPaintDC& dc, CRect *rect);
	static void CPaintHelper::Lines(CPaintDC& dc, CRect *rect, int count);
	static void CPaintHelper::Note(CPaintDC& dc, CRect *rect, Notes num);
};

