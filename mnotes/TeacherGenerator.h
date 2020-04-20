#pragma once
#include "NotesGenerator.h"
class TeacherGenerator :
	public NotesGenerator
{
public:
	TeacherGenerator(const int keyNumber);
	Notes getNote();
protected:
	int m_KeyNumber;
	Notes m_State;
};

inline Notes& operator ++(Notes& operand)
{
	switch (operand)
	{
	case No: return operand = Do;
	case Do: return operand = Re;
	case Re: return operand = Mi;
	case Mi: return operand = Fa;
	case Fa: return operand = Sol;
	case Sol: return operand = La;
	case La:	return operand = Si;
	case Si:	return operand = Do2;
	case Do2:	return operand = Re2;
	case Re2:	return operand = Mi2;
	case Mi2:	return operand = Fa2;
	case Fa2:	return operand = Sol2;
	case Sol2:	return operand = La2;
	case La2:	return operand = Si2;

	}
	return operand = No;
}

