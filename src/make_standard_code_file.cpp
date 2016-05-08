#pragma once
#ifndef _MAKE_STANDARD_CODE_FILE_H_

#include "build.h"


// standart code from "..\\standard_code_file\\main.cpp"
vector<string> code_buffer;

bool is_main_func(string code_line);

string get_freopen_stdin_line(Configuration &config);

string get_freopen_stdout_line(Configuration &config);

bool write_to_local_file();

bool compile_standard_code_file();


/*
find the first '{' int main() function.
In order to add redirect code to main() function later.
*/
bool make_standard_code_file(Configuration& config)
{
    code_buffer.clear();
    ifstream fin("..\\standard_code_file\\main.cpp");
//    ofstream fout("..\\bin\\main.cpp");
    string code_line;

    // in order to add define information later.
    code_buffer.push_back("#include <bits/stdc++.h>");
    code_buffer.push_back("using namespace std;");
    code_buffer.push_back("");


    while(getline(fin,code_line))
    {
        code_buffer.push_back(code_line);
    }
    fin.close();
    int code_length=code_buffer.size();
    bool f1=0,f2=0;
    int row=0,col=0;
    for(int i=0;i<code_length;++i)
    {
        if(is_main_func(code_buffer[i]))
        {
            string standard_main="int main(int argc, char const *argv[])";
            f1=1;
            bool exit_bracket=false;
            for(int j=0;j<code_buffer[i].length();++j)
            {
                if(code_buffer[i][j]=='{')
                {
                    standard_main+="{";
                    break;
                }
            }
            code_buffer[i]=standard_main;
        }
        if(f1)
        {
            for(int j=0;j<code_buffer[i].length();++j)
            {
                if(code_buffer[i][j]=='{')
                {
                    // According to argv[1] to structure freopen
                    int code_buffer_i_len=code_buffer[i].length();

                    string front_str=code_buffer[i].substr(0,j+1);
                    string back_str=code_buffer[i].substr(j+1,code_buffer_i_len);

                    string freopen_stdin=string("freopen(argv[1],\"r\",stdin);    ");
                    string freopen_stdout=string("freopen(argv[2],\"w\",stdout);   ");

                    front_str+=freopen_stdin;
                    front_str+=freopen_stdout;
                    front_str+=back_str;

                    code_buffer[i]=front_str;

                	row=i;
                	col=j;
                    f2=1;
                    break;
                }
            }
        }
        if(f2) break;
    }
    if(row==0 && col==0)
    {
    	puts("error : can't find main() function in standard code file, or \"..\\standard_code_file\\main.cpp\" not exist.");
    	exit(-1);
    }

    write_to_local_file();

    if(compile_standard_code_file()!=0)
    {
        puts("error : can't compile \"..\\bin\\main.cpp\" file .");
    	exit(-1);
    }
    else puts("successful compile standard code file .");

    return 1;
}


/*
matching the main() function by regex
*/
bool is_main_func(string code_line)
{
    const std::regex pattern_of_main(".*(\\ +)main(\\(|\\ *).*");
    return std::regex_match(code_line,pattern_of_main);
}


bool write_to_local_file()
{
    char local_file_name[]="..\\bin\\main.cpp";
    ofstream fout(local_file_name);
    for(int i=0;i<code_buffer.size();++i)
    {
        fout<<code_buffer[i]<<endl;
    }
    return 1;
}


bool compile_standard_code_file()
{
    return system("g++ -o ..\\bin\\main.exe    ..\\bin\\main.cpp");
}


#endif // _MAKE_STANDARD_CODE_FILE_H_
