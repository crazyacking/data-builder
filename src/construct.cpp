#pragma once

#ifndef _GENERATOR_H_
#define _GENERATOR_H_


/**<
* * ֻ����create_one_test_case()����һ������Ĳ�����������ʹ��cout�������
*/

/******************************************************************/
/******************************************************************/
/**
        �޸�create_one_test_case()����
**/
/******************************************************************/
/******************************************************************/


void create_one_test_case(ofstream &cout)
{
    // ��a+bΪ��,�������������cout���(ע��:�����cout�Ǿ������صģ��ú����е����������ֻ����cout)
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
