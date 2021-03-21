## 输入 & 输出
### scanf("%s%s", s1, s2);
#### 输入两个字符串，每个字符串换行结束

## 类型
### bool类型使用
#### ```#include<stdbool.h>```

## 经典位运算
### 1. 获取数x的二进制数中1的个数
```
int countBitOne(int x) {

    int result = 0;
    while(x != 0) {
        result++;
        x &= (x-1);
    }
    return result;
}
```
### 2. 数x奇偶性判断
```x&1 == 0```

## 数组初始化
### 1. 赋值形式
````
int matrix[] = {1,2,3,4,5};
````
### 2. 使用memset
```
#include<string.h>

int matrix[];
memset(matrix, 0, sizeof(int) * 5);
```
