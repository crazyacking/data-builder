#include "build.h"

Configuration config;

void load_config_from_local(Configuration &config)
{
    map<string,string> conf_map;
    if(!ReadConfig(CONFIG_FILE,conf_map))
    {
        puts("error 01: load config from local file failed.");
        exit(-1);
    }
    init_conf(conf_map,config);
//    PrintConfig(conf_map);
}

int main()
{
    srand((unsigned long long)time(0));

    load_config_from_local(config);

    make_standard_code_file(config); // in make_standard_code_file.cpp

    generate_input_file(config);

    return 0;
}
