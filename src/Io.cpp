#pragma once
#include "io.h"

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef VC_EXTRALEAN
#undef WIN32_LEAN_AND_MEAN
#define USE_CONIO 0

//#if USE_CONIO
//#else // USE_CONIO
//#endif // USE_CONIO

namespace
{
    COORD locToCoord(const Location& loc)
    {
        auto res = COORD{};
        res.X = loc.m_col+1;
        res.Y = loc.m_row+1;
        return res;
    }
}

void Screen::resetLocation()
{
    setLocation(Location{ 0, 0 });
}

void Screen::setLocation(const Location location)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), locToCoord(location));
}
void Screen::clearScreen()
{
    system("cls");
}

int MyRandom::leftOrRight_int()
{
        return ((rand() % 2 == 0) ? -1 : 1);
}

int MyRandom::RandomNumBetweenBorders(int start, int end)
{

    return ((rand()% end - start +1) +start);
}

Location MyRandom::leftOrRight_location()
{
    return Location{ 0, leftOrRight_int() };
}

Location MyRandom::upOrDown_location()
{
    return Location{leftOrRight_int() ,0};
}

Location MyRandom::slant_location()
{
    return Location{ leftOrRight_int() ,leftOrRight_int() };
}

Location MyRandom::RandomDirectionWDLR_location()
{
    switch (rand() % 4)
    {
    case (0):
        return Location{ 0 ,1 };
    case (1):
        return Location{ 0,-1 };
    case (2):
        return Location{ 1,0 };
    case (3):
        return Location{ -1 ,0 };
    }
}
