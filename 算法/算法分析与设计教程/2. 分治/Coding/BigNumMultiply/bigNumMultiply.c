#include<stdio.h>
#include<math.h>
#include<string.h>
#define M 10005
char s1[M],s2[M],s[M];
int a[M],b[M],c[M];
int main()
{
    int i,j,m,n,k;
    while(~scanf("%s%s",s1,s2))
    {
        memset(c,0,sizeof(c));
        n=strlen(s1);
        m=strlen(s2);
        k=n+m;//保证相乘后的位数不会大于k
        printf("s1的长度=%d s2的长度=%d\n",n,m);
 /*把字符串s1和s2逆序用数字排列*/
        for(i=0; i<n; i++)
            a[i]=s1[n-i-1]-'0';
        for(i=0; i<m; i++)
            b[i]=s2[m-i-1]-'0';
          /* 乘运算*/
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                c[i+j]+=a[i]*b[j];
        for(i=0; i<=k; i++)
        {
            if(c[i]>=10)
            {
                c[i+1]+=c[i]/10;
                c[i]%=10;
            }
        }
 /*去除前导0*/
        i=k;
        while(c[i]==0) i--;
 /*判断两个非负数之积是否为0，以及逆序打印c[]*/
        if(i<0) printf("0");
        else
        {
            for(; i>=0; i--)
                printf("%d",c[i]);
        }
        printf("\n");
    }
    return 0;
}

