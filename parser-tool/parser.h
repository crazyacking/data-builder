#include <bits/stdc++.h>
using namespace std;


//  缓冲区
class my_buffer : public streambuf
{
public:
    my_buffer() {}
};


// 判断是否为垃圾字符
bool is_garbage(char ch)
{
    char garbage_set[]="\",{} ";

    for(int i=0;i<strlen(garbage_set);++i)
    {
        if(ch==garbage_set[i])
            return true;
    }
    return false;
}


// 去除首尾空格
string trim(string &s)
{
    if (s.empty()) return s;
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

//int cnt_doit=0;
string parsing_input_line(string line)
{
    string ret;

    int len=line.length();
    int argument_start_idx=-1;
    int argument_len=0;

//    cnt_doit=0;
//    for(int i=0;i<len;++i)
//        if(line[i]==',')
//            ++cnt_doit;

    for(int i=0;i<len;++i)
    {
        if(is_garbage(line[i]))
        {
            if(argument_len>0 && argument_start_idx>=0)
            {
                ret+=line.substr(argument_start_idx,argument_len)+" ";
            }
            argument_start_idx=-1;
            argument_len=0;
        }
        else
        {
            if(argument_start_idx<0)
                argument_start_idx=i;
            ++argument_len;
        }
    }
    if(argument_len>0 && argument_start_idx>=0)
        ret+=line.substr(argument_start_idx,argument_len)+" ";
    return ret;
}
int calc_argument_num(string parsed_line)
{
    stringstream sstr(parsed_line);
    string one_argument;
    vector<string> arguments_set;
    while(getline(sstr, one_argument,' '))
    {
        if(one_argument.length()==0)
            continue;
        arguments_set.push_back(one_argument);
    }
    return arguments_set.size();
}

//void add_T(string s,vector<int> & ve)
//{
//    istringstream iss(s);
//    int a;
//    while(iss>>a)
//    {
//        ve.push_back(a);
//        if(ve.size()==1)
//            ve.push_back(cnt_doit);
//    }
//    for(auto p:ve)
//    {
//        cout<<p<<" ";
//    }
//    cout<<endl;
//}

bool parser_topcoder_input_file()
{
    char input_file_name[100]="input\\1.in";
    char output_file_name[100]="output\\1.in";

    ifstream fin(input_file_name);
    ofstream fout(output_file_name);

    string one_input_line;

    while(getline(fin,one_input_line))
    {
        cout<<one_input_line<<endl;
        string parsed_line=parsing_input_line(one_input_line);
        cout<<parsed_line<<endl;
        trim(parsed_line);
//        vector<int> nums;

        int argument_num=calc_argument_num(parsed_line); /**< 计算一行中参数的数量 */
//        fout<<argument_num<<endl;
        fout<<parsed_line<<endl;

    }
    fin.close();
    fout.close();
}


void parser_topcoder_output_file()
{
    /**<  复用了上面的代码 */
    char input_file_name[100]="input\\1.out";
    char output_file_name[100]="output\\1.out";

    ifstream fin(input_file_name);
    ofstream fout(output_file_name);

    string one_input_line;

    while(getline(fin,one_input_line))
    {
        string parsed_line=parsing_input_line(one_input_line);
        trim(parsed_line);
        fout<<parsed_line<<endl;
    }
    fin.close();
    fout.close();
}



void generate_slice_file()
{
    char input_file_name[100]="output\\1.in";
    char output_file_name[100]="output\\1.slice";

    ifstream fin(input_file_name);
    ofstream fout(output_file_name);
    string s;

    int input_one_test_case_lines=1;
    int output_one_test_case_lines=1;



    int in_start=1,in_end=input_one_test_case_lines;
    int out_start=1,out_end=output_one_test_case_lines;

    while(getline(fin,s))
    {
        fout<<in_start<<" "<<in_end<<" "<<out_start<<" "<<out_end<<endl;
        in_end+=input_one_test_case_lines;
        in_start+=input_one_test_case_lines;
        out_start+=output_one_test_case_lines;
        out_end+=output_one_test_case_lines;
    }
}
