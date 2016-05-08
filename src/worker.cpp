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
bool init_output_folder(Configuration &conf);

void init_conf(map<string,string>& config,Configuration& conf);


void generate_input_file(Configuration &conf)
{
    init_output_folder(conf);

    int in_start_line=1,in_end_line=1;
    int out_start_line=1,out_end_line=1;

    int current_file_number=1;

    ofstream in_fout;
    ofstream out_fout;
    ofstream slice_fout;

    char current_in_file_name[100];
    char current_out_file_name[100];
    char current_slice_file_name[100];

    sprintf(current_in_file_name,"..\\output\\%d.in",current_file_number);
    sprintf(current_out_file_name,"..\\output\\%d.out",current_file_number);
    sprintf(current_slice_file_name,"..\\output\\%d.slice",current_file_number);

    in_fout.open(current_in_file_name);
    out_fout.open(current_out_file_name);
    slice_fout.open(current_slice_file_name);

    string data_line;
    puts("------------------------------  Generating Data  ----------------------------");

    for(int i=0; i<conf.TEST_CASE_NUM; ++i)
    {
        ofstream tmp_in_fout("..\\bin\\tmp.in");
        create_one_test_case(tmp_in_fout);
        tmp_in_fout.close();
        create_tmp_out();

        if(i!=0 && i%conf.CAPACITY_NUM==0) // change to next file
        {
            printf("successful generate data : %2d\n",current_file_number);
            // close current file
            in_fout.close();
            out_fout.close();
            slice_fout.close();

            current_file_number++;
            in_start_line=1,in_end_line=1;
            out_start_line=1,out_start_line=1;

            sprintf(current_in_file_name,"..\\output\\%d.in",current_file_number);
            sprintf(current_out_file_name,"..\\output\\%d.out",current_file_number);
            sprintf(current_slice_file_name,"..\\output\\%d.slice",current_file_number);

            in_fout.open(current_in_file_name);
            out_fout.open(current_out_file_name);
            slice_fout.open(current_slice_file_name);
        }

        // write data to *.in , *.out , *.slice

        ifstream tmp_in("..\\bin\\tmp.in");
        ifstream tmp_out("..\\bin\\tmp.out");

        int cnt_tmp_in=0;
        int cnt_tmp_out=0;

        while(getline(tmp_in,data_line))
        {
            in_fout<<data_line<<endl;;
            ++cnt_tmp_in;
        }

        while(getline(tmp_out,data_line))
        {
            out_fout<<data_line<<endl;
            ++cnt_tmp_out;
        }

        in_end_line=in_start_line+cnt_tmp_in-1;
        out_end_line=out_start_line+cnt_tmp_out-1;

        slice_fout<<in_start_line<<" "<<in_end_line<<" "<<out_start_line<<" "<<out_end_line<<endl;

        in_start_line=in_end_line+1;
        out_start_line=out_end_line+1;

        tmp_in.close();
        tmp_out.close();
    }
    printf("successful generate data : %2d\n",current_file_number);
    in_fout.close();
    out_fout.close();
    slice_fout.close();
    puts("-----------------------------------------------------------------------------");
}


bool init_output_folder(Configuration &conf)
{
    if(system("del/f/a/q ..\\output\\")!=0)
        puts("error 20: delete output\* failed.");
    int number_of_group=conf.TEST_CASE_NUM/conf.CAPACITY_NUM;
    if(conf.TEST_CASE_NUM%conf.CAPACITY_NUM!=0)
        number_of_group++;
    char cmd[200];
    for(int i=1;i<=number_of_group;++i)
    {
        sprintf(cmd,"cd .> ..\\output\\%d.in",i);
        if(system(cmd)!=0)
            puts("error 21: can't create file to output.");

        sprintf(cmd,"cd .> ..\\output\\%d.out",i);
        if(system(cmd)!=0)
            puts("error 22: can't create file to output.");

        sprintf(cmd,"cd .> ..\\output\\%d.slice",i);
        if(system(cmd)!=0)
            puts("error 23: can't create file to output.");

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
