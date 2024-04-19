#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#define Secoud_pi 1
void _print(const char* str, int ms) {
   int count = 0;
   while(*(str + count) != '\0')
   {
    printf("%c", *(str + count));
    count++;
    Sleep(ms);
   }
   return;
}
void endl(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\n");
    }
}
void calculate_pi(void)  //计算圆周率
{
    int Mark = 1;
    double pi = 0.0;
    int count, end, ms;  //计数器，终止迭代次数，每次迭代间隔时间
    bool quite = false;
    endl(1);
    printf("请输入终止迭代次数：");     
    scanf("%d", &end);
    endl(1);
    printf("请输入每次迭代间隔时间(ms)：");
    scanf("%d", &ms);
    endl(1);
    count = 0;
    printf("PI计算中...  按L可退出   按空格可显示详细信息\n");
    endl(1);
    while(count <= end)
    {
        pi += 4.0 * (1.0 / (2.0 * (double)count + 1.0) * (double)Mark);
        if(GetKeyState(' ') < 0)
        {
            if(quite == false)
            {
                quite = true;
            }
            else
            {
                quite = false;
            }
            Sleep(10);
            endl(1);
        }
      if(quite == false)
      {
        printf("%lf\r", pi);
      }
      else
      {
         printf("PI计算结果: %lf   迭代次数：%d   计算进度: %lf %%  计算中...\r", pi, count, (double)count / (double)end * 100.0);
      }
      count++;
       Mark *= -1;
       Sleep(ms);
       if(GetKeyState('L') < 0)
       {
        return;
       }
    }
}
double exp(double x, int y) //计算x的y次方
{
    double _return = 1.0;
    while(y > 0)
    {
        _return *= x;
        y--;
    }
    return _return;
}
void calculate_log(void)   //计算自然对数的底e
{
    double e;
    int end, ms, count;
    bool quite = false;  //是否显示详细信息
    printf("请输入终止迭代次数：");
    scanf("%d", &end);
    printf("请输入每次迭代间隔时间(ms)：");
    scanf("%d", &ms);
    while(count <= end)
    {
        e = exp(1.0 + 1.0 / (double)count, count);
        if(GetKeyState(' ') < 0)
        {
            if(quite == false)
            {
                quite = true;
            }
            else
            {
                quite = false;
            }
            Sleep(10);
            endl(1);
        }
        if(quite == false)
        {
            printf("%lf\r", e);   //减少计算详细信息输出所用时间
        }
        else
        {
            printf("e计算结果: %lf   迭代次数：%d   计算进度: %lf %%  计算中...\r", e, count, (double)count / (double)end * 100.0);
        }
        count++;
        Sleep(ms);
        if(GetKeyState('L') < 0)
        {
            return;
        }
    }
    printf("e计算完成！\n");
}
    
int main() {
    calculate_log();
    endl(1);
    _print("Hello, world!\n", 200);
    endl(2);
    _print("This is a test program.\n", 300);
    return 0;
}