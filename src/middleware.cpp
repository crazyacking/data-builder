#pragma once

#ifndef _MIDDLEWARE_H_
#include "build.h"
#include <windows.h>

void create_tmp_out()
{
    system("..\\bin\\main.exe ..\\bin\\tmp.in ..\\bin\\tmp.out");
}



#endif // _MIDDLEWARE_H_
