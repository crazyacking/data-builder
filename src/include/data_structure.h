#pragma once

#ifndef _DATA_STRUCTURE_H_
#define _DATA_STRUCTURE_H_

class Test_case
{
public:
    vector<string> input_file_buffer;
    vector<string> output_file_buffer;
    vector<string> slice_file_buffer;
};

class Configuration
{
public:
    int TEST_CASE_NUM;
    int CAPACITY_NUM;
    bool CREATE_SLICE;
    string OUTPUT_PATH;
};



#endif
