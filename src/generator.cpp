#pragma once

#ifndef _GENERATOR_H_
#define _GENERATOR_H_
#include "include/mingw.h"
#include "include/data_structure.h"
#include "include/factory.h"


/**<
* * 采用“值-结果”的传参方法，返回一个Test_case对象
* * Test_case对象中保存了三个vector<string>类型的数据缓冲区(input_file_buffer,output_file_buffer,slice_file_buffer)
* *
*/

/******************************************************************/
/******************************************************************/
/**
        修改create_one_test_case()函数，构造Test_case对象
**/
/******************************************************************/
/******************************************************************/

char buffer[500010];


void create_one_test_case(ofstream &cout)
{
    cout<<rand_number(0,0xffffff)<<" "<<rand_number(0,0xffffff)<<endl;
}


#endif
