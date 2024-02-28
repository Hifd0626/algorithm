#include<iostream>
//辗转相除法求最大公约数
#if 0
int gcd(int a,int b)
{
    int t,max,min;
    if(a>b)
    {
        max=a;
        min=b;
    }
    else
    {
        max=b;
        min=a;
    }
    while(min!=0)
    {
        t=min;
        min=max%min;
        max=t;
    }
    return max;

}
#endif