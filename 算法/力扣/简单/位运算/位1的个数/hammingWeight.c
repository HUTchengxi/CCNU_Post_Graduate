#include<stdio.h>
#include <stdint.h>

/**
 * λ�����Ż���n & n-1 ÿ�ζ��Ὣ���һλ��������ת����0
 * @param n
 * @return
 */
int hammingWeight(uint32_t n) {

    int result = 0;
    while (n) {
        n &= n - 1;
        result++;
    }
    return result;
}

/**
 * �򵥵�ѭ��ÿλ�ж�
 * @param n
 * @return
 */
int hammingWeightOne(uint32_t n) {

    int i, result = 0;
    long long temp = 1;
    for (i = 0; i < 32; i++) {
        temp *= (i == 0 ? 1 : 2);
        if (n & temp) {
            result++;
        }
    }
    return result;
}