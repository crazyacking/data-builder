#include "build.h"
using namespace std;

map<string,string> config;

void init()
{
    ReadConfig(CONFIG_FILE,config);
    PrintConfig(config);
}

int main()
{
    srand((unsigned long long)time(0));
    init();
    work(config);
    return 0;
}
