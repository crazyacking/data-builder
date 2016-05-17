#pragma once

#ifndef _GENERATOR_H_
#define _GENERATOR_H_


/**<
* * 只需在create_one_test_case()构造一个随机的测试用例，并使用cout输出即可
*/

/******************************************************************/
/******************************************************************/
/**
        修改create_one_test_case()函数
**/
/******************************************************************/
/******************************************************************/


void create_one_test_case(ofstream &cout)
{
    // 以a+b为例,随机两个数，用cout输出(注意:这儿的cout是经过重载的，该函数中的所有输出都只能用cout)
//    cout<<rand_number(1,0xfffff)<<" "<<rand_number(1,0xffffff)<<endl;
    int len=rand_number(1,10000);
    char ch=rand_char('a','z');
    char s[len+10];
    for(int i=0;i<len;++i)
    {
        s[i]=rand_char(0x21,0x7F);
        while(s[i]==ch)
        {
            s[i]=rand_char(0x21,0x7F);
        }

    }
    s[len-1]=ch;
    s[len]='\0';
    cout<<s<<endl;

}


#endif
