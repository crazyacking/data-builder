#pragma once

#ifndef _GENERATOR_H_
#define _GENERATOR_H_
#include "include/mingw.h"
#include "include/data_structure.h"
#include "include/factory.h"


/**<
* * ���á�ֵ-������Ĵ��η���������һ��Test_case����
* * Test_case�����б���������vector<string>���͵����ݻ�����(input_file_buffer,output_file_buffer,slice_file_buffer)
* *
*/

/******************************************************************/
/******************************************************************/
/**
        �޸�create_one_test_case()����������Test_case����
**/
/******************************************************************/
/******************************************************************/

char buffer[500010];


void create_one_test_case(ofstream &cout)
{
    cout<<rand_number(0,0xffffff)<<" "<<rand_number(0,0xffffff)<<endl;
}


#endif
