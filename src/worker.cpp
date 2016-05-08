#pragma once

#ifndef _WORKER_H_
#define _WORKER_H_

#include "include/mingw.h"
#include "generator.cpp"
#include "include/data_structure.h"

#endif

int get_num(string s);
bool get_bool(string s);
int get_num(string s);


void init_conf(map<string,string>& config,Configuration& conf);


void generate_input_file(Configuration &conf)
{
    // init conf
//    Configuration conf;
//    init_conf(config,conf);

    Test_case test_case;

    for(int i=0; i<conf.TEST_CASE_NUM; ++i)
    {
        create_one_test_case(test_case,conf);
    }
}


void init_conf(map<string,string>& config,Configuration& conf)
{
    conf.TEST_CASE_NUM=get_num(config["TEST_CASE_NUM"]);
    conf.CAPACITY_NUM=get_num(config["CAPACITY_NUM"]);
    conf.CREATE_SLICE=get_bool(config["CREATE_SLICE"]);
    conf.OUTPUT_PATH=config["OUTPUT_PATH"];
//    cout<<conf.TEST_CASE_NUM<<endl;
//    cout<<conf.CAPACITY_NUM<<endl;
//    cout<<conf.CREATE_SLICE<<endl;
//    cout<<conf.OUTPUT_PATH<<endl;
}

int get_num(string s)
{
    int ret=0;
    int idx=0,c=0,len=s.length();
    c=s[idx++];
    while(!(c>='0' && c<='9'  || c=='-') && idx<len)
    {
        c=s[idx++];
    }
    bool flag=1;
    if(c=='-')
    {
        flag=0;
        c=s[idx++];
    }
    while(c>='0' && c<='9' && idx<=len)
    {
        ret=ret*10 + c-'0';
        c=s[idx++];
    }
    if(!flag) ret=-ret;
    return ret;
}

bool get_bool(string s)
{
    if(!s.compare("true"))
        return true;
    else return false;
}
