#include<stdio.h>
#include<Stdlib.h>

/**
 * �������߷ֱ�ͳ��xϵ��������ϵ��ֵ������x��ͳ�Ʒ�ʽ����ͨ���Ƚ��ַ�������=��֣�Ȼ�����+- ���Ų�֣����x����1(��ϵ��)���߿�(��ϵ��)
 * ���бȽϼ���
 * @param equation
 * @return
 */
char * solveEquation(char * equation)
{
    int sumx = 0;
    int sumn = 0;
    int i = 0;
    int leftrightFlag = 1;  // 1�Ⱥ����, -1�Ⱥ��ұ�
    int posnegFlag = 1;  // 1����ϵ��Ϊ��, -1����ϵ��Ϊ��
    int flag = 1;  // ���Ⱥ���������ĵ�һ���ַ�Ϊx����ϵ��Ϊ�ȼ���1
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
            nTemp = atoi(&equation[i]);  // atoi()��������ǵ�ַ
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
            flag = -1;  // ���Ⱥ��ұ������ĵ�һ���ַ�Ϊx����ϵ��Ϊ�ȼ���-1
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
        // sprintf_s(&ans[2], sizeof(ans), "%d", val);  // ʹ�ð�ȫ������leetcode��ʶ��
        sprintf(&ans[2], "%d", val);
        return ans;
    }
}
