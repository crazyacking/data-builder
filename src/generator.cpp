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

void create_one_test_case(Test_case& test_case,Configuration& conf)
{
    // flush test_case buffer
//    test_case.input_file_buffer.clear();
//    test_case.output_file_buffer.clear();
//    test_case.slice_file_buffer.clear();
//
//    // 以a+b为例
//    int a=rand_number(0,0xfffffff);
//    int b=rand_number(0,0xfffffff);
//    sprintf(buffer,"%d",a);
//    string input_str=string(buffer);
//    sprintf(buffer,"%d",b);
//    input_str+=string(" ");
//    input_str+=string(buffer);
//
//    test_case.input_file_buffer.push_back(input_str);
//    cout<<input_str<<endl;

}


#endif
