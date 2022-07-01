int SPARE_CAPACITY = 16;
#include "Vector.h"
#include <iostream>
#include <ctime>

int main(int argc,char* argv[])
{
    clock_t startTime,endTime;
    int N; // 测试次数
    std::cin >> N;
    std::cin >> SPARE_CAPACITY ;
    startTime = clock(); // 开始计时
    for (  int i  = 0 ; i < N ; i++ )
    {   
        Vector<int> a(0);
        for(int j = 1 ; j < i + 1 ; j++ )
        {
            a.push_back(1);
        }
    }
    endTime = clock(); // 结束计时
    std::cout <<"When SPARE_CAPACITY is : "<< SPARE_CAPACITY <<", the time is : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds. " << std::endl;
    return 0;
};
