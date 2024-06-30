#include "./inc/utility.h"
#include <utility>

/**
 * 计算两个正整数的循环节
 * @param a
 * @param b
 *
 * @return 如果返回0，说明a与b不是无限循环小数。
 *  如果返回-1，说明在指定的小数位数内没有发现循环节
 */
namespace MyC
{
    long get_xunhuan(long a, long b)
    {
        long q1 = -1, q2 = -1, q3 = -1;
        if (a < 0)
            a = -a;
        if (b < 0)
            b = -b;
        if (a % b == 0)
            return 0;
        int loop_count = 0;
        while (loop_count < LOOP_COUNT)
        {
            long temp = a % b;
            if (temp == 0)
                return 0;
            if (temp != q2)
            {
                std::swap(q1, q2);
                std::swap(q2, q3);
                q3 = temp;
                a = temp * 10;
            }
            else
            {
                break;
            }
            loop_count += 1;
        }
        return (q2 * 10 - q3) / b;
    }
}