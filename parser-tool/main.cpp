#include <bits/stdc++.h>
#include "parser.h"
using namespace std;


int main()
{
    /**< 1. 解析从topcoder上爬取的原始输入文件 */
    parser_topcoder_input_file();

    /**< 2. 解析从topcoder上爬取的原始输出文件 */
    parser_topcoder_output_file();

    /**< 3. 生成.slice文件 */
    generate_slice_file();

    return 0;
}
