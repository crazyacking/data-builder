#include "build.h"


void load_config_from_local(Configuration &config)
{
    map<string,string> conf_map;
    if(!ReadConfig(CONFIG_FILE,conf_map))
    {
        puts("error : load config from local file failed.");
        exit(-1);
    }
    init_conf(conf_map,config);
//    void init_conf(map<string,string>& config,Configuration& conf)
//    void generate_input_file(map<string,string>& config)
    PrintConfig(conf_map);
}

int main()
{
    cout<<"hehe2"<<endl;
    srand((unsigned long long)time(0));
    Configuration config;
    load_config_from_local(config);

    load_standard_code_file(config); // in make_standard_code_file.cpp

    generate_input_file(config);

//    work(config);
    return 0;
}
