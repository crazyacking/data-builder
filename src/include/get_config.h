#pragma once

#include <bits/stdc++.h>
using namespace std;

/****************************************************************************
*   Objective: read the information of configuration files, deposit in the map<key,value>.
*   Requirements: config file format, with # as a comment line, configuration form is key = value, intermediate can have spaces or not.
*****************************************************************************/

#ifndef _GET_CONFIG_H_
#define _GET_CONFIG_H_
#include <string>
#include <map>
#define COMMENT_CHAR '#'

bool ReadConfig(const string & filename, map<string, string> & m);
void PrintConfig(const map<string, string> & m);
#endif

bool IsSpace(char c)
{
    if (' ' == c || '\t' == c)
        return true;
    return false;
}

bool IsCommentChar(char c)
{
    switch(c)
    {
    case COMMENT_CHAR:
        return true;
    default:
        return false;
    }
}



void Trim(string & str)
{
    if (str.empty())
    {
        return;
    }
    int i, start_pos, end_pos;
    for (i = 0; i < str.size(); ++i)
    {
        if (!IsSpace(str[i]))
        {
            break;
        }
    }
    if (i == str.size()) // all is black space
    {
        str = "";
        return;
    }

    start_pos = i;

    for (i = str.size() - 1; i >= 0; --i)
    {
        if (!IsSpace(str[i]))
        {
            break;
        }
    }
    end_pos = i;

    str = str.substr(start_pos, end_pos - start_pos + 1);
}


bool AnalyseLine(const string & line, string & key, string & value)
{
    if (line.empty())
        return false;
    int start_pos = 0, end_pos = line.size() - 1, pos;
    if ((pos = line.find(COMMENT_CHAR)) != -1)
    {
        if (0 == pos)  // The first character is the comment character in this line
        {
            return false;
        }
        end_pos = pos - 1;
    }
    string new_line = line.substr(start_pos, start_pos + 1 - end_pos); // Pretreatment, remove the comments section

    if ((pos = new_line.find('=')) == -1)
        return false;  // have't =

    key = new_line.substr(0, pos);
    value = new_line.substr(pos + 1, end_pos + 1- (pos + 1));

    Trim(key);
    if (key.empty())
    {
        return false;
    }
    Trim(value);
    return true;
}


bool ReadConfig(const string & filename, map<string, string> & m)
{
    m.clear();
    ifstream infile(filename.c_str());
    if (!infile)
    {
        cout << "file open error" << endl;
        return false;
    }
    string line, key, value;
    while (getline(infile, line))
    {
        if (AnalyseLine(line, key, value))
        {
            m[key] = value;
        }
    }
    infile.close();
    return true;
}

void PrintConfig(const map<string, string> & m)
{
    puts("-------------------------------  configuration  -----------------------------");

    map<string, string>::const_iterator mite = m.begin();
    for (; mite != m.end(); ++mite)
        cout << mite->first << "=" << mite->second << endl;

    puts("-----------------------------------------------------------------------------");
}
