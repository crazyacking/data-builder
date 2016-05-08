#pragma once

#ifndef _WORKER_H_
#define _WORKER_H_

#include "include/mingw.h"
#include "generator.cpp"
#include "include/data_structure.h"
#include "middleware.cpp"



int get_num(string s);
bool get_bool(string s);
int get_num(string s);


void init_conf(map<string,string>& config,Configuration& conf);


void generate_input_file(Configuration &conf)
{
    // init conf
//    Configuration conf;
//    init_conf(config,conf);



    for(int i=0; i<conf.TEST_CASE_NUM; ++i)
    {
        ofstream fout("..\\bin\\tmp.in");
        create_one_test_case(fout);
        fout.close();
        create_tmp_out();
    }
}


void init_conf(map<string,string>& config,Configuration& conf)
{
    conf.TEST_CASE_NUM=get_num(config["TEST_CASE_NUM"]);
    conf.CAPACITY_NUM=get_num(config["CAPACITY_NUM"]);
    conf.CREATE_SLICE=get_bool(config["CREATE_SLICE"]);
    conf.OUTPUT_PATH=config["OUTPUT_PATH"];
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

#endif
