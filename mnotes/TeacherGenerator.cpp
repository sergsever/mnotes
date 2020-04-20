#include "stdafx.h"
#include "TeacherGenerator.h"
#include "NotesEnum.h"

TeacherGenerator::TeacherGenerator(const int keyNumber)
{
	m_KeyNumber = keyNumber;
	m_State = Do;
}

Notes TeacherGenerator::getNote()
{
	if (m_State < m_KeyNumber)
		return ++m_State;
}
