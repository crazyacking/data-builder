#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("..\\input\\1.in");
    ofstream fout("..\\output\\1.in");
    string s;
    while(getline(fin,s))
    {
        for(int i=0;i<s.length();++i)
        {
            if(s[i]==',')
                s[i]=' ';
        }
        fout<<s<<endl;
    }
    return 0;
}
