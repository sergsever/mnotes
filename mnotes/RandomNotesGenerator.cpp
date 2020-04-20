#include "stdafx.h"
#include "RandomNotesGenerator.h"

RandomNotesGenerator::RandomNotesGenerator(const int keyCount)
{
	m_KeyCount = keyCount;
}

Notes RandomNotesGenerator::getNote()
{
	Notes ret;
	int rnd = std::rand();
	TRACE1("std::rand:%d\n", rnd);
	//	Notes ret = static_cast<Notes>((int)(std::rand()% KEY_NUMBER + 1));//static_cast<Notes>((int)(7 * rand() / (RAND_MAX + 1.0)));
	ret = static_cast<Notes>(rnd % m_KeyCount + 1);
	TRACE1("Rand:%d\n", ret);

	if (ret > Si2 || ret < Do) {
		wchar_t message[200];
		wsprintf(message, _T("Note is not in diapasone:%d"), ret);
		MessageBox(NULL, (LPCTSTR)message, L"", MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);
	}
	return ret;

}
