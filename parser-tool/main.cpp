#include <bits/stdc++.h>
#include "parser.h"
using namespace std;


int main()
{
    /**< 1. ������topcoder����ȡ��ԭʼ�����ļ� */
    parser_topcoder_input_file();

    /**< 2. ������topcoder����ȡ��ԭʼ����ļ� */
    parser_topcoder_output_file();

    /**< 3. ����.slice�ļ� */
    generate_slice_file();

    return 0;
}
