#pragma once

#ifndef _MIDDLEWARE_H_
#include "build.h"
#include <windows.h>

bool create_tmp_out()
{
    return system("..\\bin\\standard_code_file.exe   ..\\bin\\tmp.in   ..\\bin\\tmp.out");
}



#endif // _MIDDLEWARE_H_
