#include<stdio.h>
#include<math.h>
#include<string.h>

/**
 * 数学思想：注水树 = 总体积 - 柱子体积
 * 从第一层开始，统计每层水柱数
 * @param height
 * @param heightSize
 * @return
 */
int trap(int *height, int heightSize) {
    int volume = 0;  // 总体积初始化
    int Sum = 0;  // 柱子体积初始化
    int left = 0;  // 左指针
    int right = heightSize - 1; // 右指针
    int high = 0; // 高度
    while (left <= right) {
        high++;
        while ((left <= right) && (height[left] < high)) {
            Sum += height[left]; // 在一次次相加中，得到柱子体积
            left++;
        }
        while ((left <= right) && (height[right] < high)) {
            Sum += height[right];
            right--;
        }
        volume += right - left + 1; // 每一层的容量都加起来
    }
    return volume - Sum; // 总体积减去柱子体积就是水的容量
}


/**
 * dp思想：第i层注水数 = min(i层前面最高，i层后面最高) - height[i]
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