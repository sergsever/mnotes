#pragma once

#include "NotesEnum.h"

class CPlayer
{
public:
	CPlayer(){}
	virtual void Play(Notes note) = 0;
	virtual ~CPlayer() {}
};
