#pragma once

#include "Location.h"

void Location::operator+=(const Location& loc)
{
	m_row += loc.m_row;
	m_col += loc.m_col;
}

void Location::operator*=(const Location& loc)
{
	m_row *= loc.m_row;
	m_col *= loc.m_col;
}

bool Location::operator==(const Location& loc)
{
	return m_col == loc.m_col && m_row == loc.m_row;
}

bool Location::operator!=(const Location& loc)
{
	return !(*this==loc);
}

Location operator*(const Location& a, const int b)
{
	return Location{ a.m_row * b,a.m_col * b };
}

Location operator+(const Location& a, const Location& b)
{
	return Location{ a.m_row + b.m_row, a.m_col + b.m_col };
}


ostream& operator<<(ostream& os, const Location& loc)
{
	return (os<<"loc:{"<<loc.m_row<<"," << loc.m_col<<"}");
}
