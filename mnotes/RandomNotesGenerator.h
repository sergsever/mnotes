#pragma once
#include "NotesGenerator.h"
class RandomNotesGenerator :
	public NotesGenerator
{
protected:
	int m_KeyCount;
public: 
	RandomNotesGenerator(const int keyCount);

	virtual Notes getNote();
};

