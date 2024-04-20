#include "../include/commandline.h"
int welcome(void)
{
    int _return = 0;
    printf("欢迎使用命令行计算器！\n");
    printf("计算圆周率键入%d", PI);
    endl(1);
    printf("计算自然对数的底e键入%d", E);
    endl(1);
    printf("判断是否是指数键入%d    计算质数键入%d", IS_PRIME, PRIME);
    endl(1);
    printf("计算因数分解键入%d", FACTORIZATION);
    endl(1);
    _print("退出键入13", 50);
    do
    {
        if (_return == 0)
        {
            printf("请输入命令：");
            scanf("%d", &_return);
        }
        else
        {
            printf("输入错误，请重新输入：");
            scanf("%d", &_return);
        }
    } while (_return != PI && _return != E && _return != IS_PRIME && _return != PRIME && _return != FACTORIZATION && _return != 13);
    return _return;
}
void _print(const char *str, int ms)
{
    int count = 0; // 计数器
    while (*(str + count) != '\0')
    {
        printf("%c", *(str + count));
        count++;
        Sleep(ms);
    }
    return;
}
void endl(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n");
    }
}
void calculate_pi(void) // 计算圆周率
{
    int Mark = 1;
    double pi = 0.0;
    int count, end, ms; // 计数器，终止迭代次数，每次迭代间隔时间
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
    while (count <= end)
    {
        pi += 4.0 * (1.0 / (2.0 * (double)count + 1.0) * (double)Mark);
        if (GetKeyState(' ') < 0)
        {
            if (quite == false)
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
        if (quite == false)
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
        if (GetKeyState('L') < 0)
        {
            return;
        }
    }
}
double exp(double x, int y) // 计算x的y次方
{
    double _return = 1.0;
    while (y > 0)
    {
        _return *= x;
        y--;
    }
    return _return;
}
bool is_prime(int n) // 判断是否为素数
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void calculate_prime(void) // 计算素数
{
    int end, ms, count;
    bool quite = false; // 是否显示详细信息
    printf("请输入终止迭代次数：");
    scanf("%d", &end);
    printf("请输入每次迭代间隔时间(ms)：");
    scanf("%d", &ms);
    while (count <= end)
    {
        if (is_prime(count))
        {
            if (GetKeyState(' ') < 0)
            {
                if (quite == false)
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
            if (quite == false)
            {
                printf("%d\r", count); // 减少计算详细信息输出所用时间
            }
            else
            {
                printf("素数计算结果: %d   迭代次数：%d   计算进度: %lf %%  计算中...\r", count, count, (double)count / (double)end * 100.0);
            }
        }
        count++;
        Sleep(ms);
        if (GetKeyState('L') < 0)
        {
            return;
        }
    }
    printf("素数计算完成！\n");
}
void calculate_log(void) // 计算自然对数的底e
{
    double e;
    int end, ms, count;
    bool quite = false; // 是否显示详细信息
    printf("请输入终止迭代次数：");
    scanf("%d", &end);
    printf("请输入每次迭代间隔时间(ms)：");
    scanf("%d", &ms);
    while (count <= end)
    {
        e = exp(1.0 + 1.0 / (double)count, count);
        if (GetKeyState(' ') < 0)
        {
            if (quite == false)
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
        if (quite == false)
        {
            printf("%lf\r", e); // 减少计算详细信息输出所用时间
        }
        else
        {
            printf("e计算结果: %lf   迭代次数：%d   计算进度: %lf %%  计算中...\r", e, count, (double)count / (double)end * 100.0);
        }
        count++;
        Sleep(ms);
        if (GetKeyState('L') < 0)
        {
            return;
        }
    }
    printf("e计算完成！\n");
}
void calculate_factorization(void) // 计算因数分解
{
    int number, count = 1;
    int number2 = 1; // 有bug，因式分解最后一个数字没输出
    printf("请输入一个正整数：");
    scanf("%d", &number);
    endl(1);
    while (number >= count)
    {
        // printf("%d \n", count);
        if (is_prime(count))
        {
            while (number % count == 0 && count > 1)
            {
                printf("%d* ", count);
                number /= count;
                // count++;
                number2 *= count;
                // printf("%d \n", count);
            }
        }
        else
        {
            if (count > number)
            {
                printf(" *%d\n", number / number2);
                break;
            }
        }
        count++;
    }
    printf("因数分解完成！\n");
}