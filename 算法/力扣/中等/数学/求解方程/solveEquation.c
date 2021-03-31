#include<stdio.h>
#include<Stdlib.h>

/**
 * 左右两边分别统计x系数和其他系数值，其中x的统计方式可以通过先将字符串进行=拆分，然后进行+- 符号拆分，最后将x看成1(无系数)或者空(有系数)
 * 进行比较即可
 * @param equation
 * @return
 */
char * solveEquation(char * equation)
{
    int sumx = 0;
    int sumn = 0;
    int i = 0;
    int leftrightFlag = 1;  // 1等号左边, -1等号右边
    int posnegFlag = 1;  // 1代表系数为正, -1代表系数为负
    int flag = 1;  // 若等号左边遇到的第一个字符为x，其系数为等价于1
    int nTemp;
    int val;

    while (equation[i] != '\0') {
        if (equation[i] == '+') {
            posnegFlag = 1;
            flag = leftrightFlag * posnegFlag;
            i++;
        } else if (equation[i] == '-') {
            posnegFlag = -1;
            flag = leftrightFlag * posnegFlag;
            i++;
        } else if (equation[i] == 'x') {
            sumx += flag * 1;
            i++;
        } else if ((equation[i] >= '0') && (equation[i] <= '9')) {
            nTemp = atoi(&equation[i]);  // atoi()函数入参是地址
            while ((equation[i] >= '0') && (equation[i] <= '9')) {
                i++;
            }
            if (equation[i] == 'x') {
                sumx += flag * nTemp;
                i++;
            } else {
                sumn += flag * nTemp;
            }
        } else if (equation[i] == '=') {
            flag = -1;  // 若等号右边遇到的第一个字符为x，其系数为等价于-1
            leftrightFlag = -1;
            i++;
        } else {
            i++;
        }
    }

    if (sumx == 0) {
        char *ans;
        if (sumn == 0) {
            ans = "Infinite solutions";
        } else {
            ans = "No solution";
        }
        return ans;
    } else {
        char *ans = (char *)malloc(sizeof(char) * sizeof(equation) + 1);
        ans[0] = 'x';
        ans[1] = '=';
        val = (-1 * sumn) / sumx;
        // sprintf_s(&ans[2], sizeof(ans), "%d", val);  // 使用安全函数，leetcode不识别
        sprintf(&ans[2], "%d", val);
        return ans;
    }
}
