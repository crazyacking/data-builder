#pragma once

#ifndef _MIDDLEWARE_H_
#include <windows.h>

bool create_tmp_out()
{
    return system("..\\bin\\compiled_standard_code.exe   ..\\bin\\tmp.in   ..\\bin\\tmp.out");
}



#endif // _MIDDLEWARE_H_
