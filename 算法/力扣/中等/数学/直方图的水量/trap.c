#include<stdio.h>
#include<math.h>
#include<string.h>

/**
 * ��ѧ˼�룺עˮ�� = ����� - �������
 * �ӵ�һ�㿪ʼ��ͳ��ÿ��ˮ����
 * @param height
 * @param heightSize
 * @return
 */
int trap(int *height, int heightSize) {
    int volume = 0;  // �������ʼ��
    int Sum = 0;  // ���������ʼ��
    int left = 0;  // ��ָ��
    int right = heightSize - 1; // ��ָ��
    int high = 0; // �߶�
    while (left <= right) {
        high++;
        while ((left <= right) && (height[left] < high)) {
            Sum += height[left]; // ��һ�δ�����У��õ��������
            left++;
        }
        while ((left <= right) && (height[right] < high)) {
            Sum += height[right];
            right--;
        }
        volume += right - left + 1; // ÿһ���������������
    }
    return volume - Sum; // �������ȥ�����������ˮ������
}


/**
 * dp˼�룺��i��עˮ�� = min(i��ǰ����ߣ�i��������) - height[i]
 * @param height
 * @param heightSize
 * @return
 */
int trap2(int *height, int heightSize) {

    int n = heightSize;
    if (n == 0) {
        return 0;
    }
    int leftMax[n];
    memset(leftMax, 0, n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = fmax(leftMax[i - 1], height[i]);
    }

    int rightMax[n];
    memset(rightMax, 0, n);
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = fmax(rightMax[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += fmin(leftMax[i], rightMax[i]) - height[i];
    }
    return ans;
}

int main() {

    return 0;
}