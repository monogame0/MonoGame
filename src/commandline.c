#include "../include/commandline.h"
int welcome(void)
{
    int _return = 0;
    printf("��ӭʹ�������м�������\n");
    printf("����Բ���ʼ���%d", PI);
    endl(1);
    printf("������Ȼ�����ĵ�e����%d", E);
    endl(1);
    printf("�ж��Ƿ���ָ������%d    ������������%d", IS_PRIME, PRIME);
    endl(1);
    printf("���������ֽ����%d", FACTORIZATION);
    endl(1);
    _print("�˳�����13", 50);
    do
    {
        if (_return == 0)
        {
            printf("���������");
            scanf("%d", &_return);
        }
        else
        {
            printf("����������������룺");
            scanf("%d", &_return);
        }
    } while (_return != PI && _return != E && _return != IS_PRIME && _return != PRIME && _return != FACTORIZATION && _return != 13);
    return _return;
}
void _print(const char *str, int ms)
{
    int count = 0; // ������
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
void calculate_pi(void) // ����Բ����
{
    int Mark = 1;
    double pi = 0.0;
    int count, end, ms; // ����������ֹ����������ÿ�ε������ʱ��
    bool quite = false;
    endl(1);
    printf("��������ֹ����������");
    scanf("%d", &end);
    endl(1);
    printf("������ÿ�ε������ʱ��(ms)��");
    scanf("%d", &ms);
    endl(1);
    count = 0;
    printf("PI������...  ��L���˳�   ���ո����ʾ��ϸ��Ϣ\n");
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
            printf("PI������: %lf   ����������%d   �������: %lf %%  ������...\r", pi, count, (double)count / (double)end * 100.0);
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
double exp(double x, int y) // ����x��y�η�
{
    double _return = 1.0;
    while (y > 0)
    {
        _return *= x;
        y--;
    }
    return _return;
}
bool is_prime(int n) // �ж��Ƿ�Ϊ����
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
void calculate_prime(void) // ��������
{
    int end, ms, count;
    bool quite = false; // �Ƿ���ʾ��ϸ��Ϣ
    printf("��������ֹ����������");
    scanf("%d", &end);
    printf("������ÿ�ε������ʱ��(ms)��");
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
                printf("%d\r", count); // ���ټ�����ϸ��Ϣ�������ʱ��
            }
            else
            {
                printf("����������: %d   ����������%d   �������: %lf %%  ������...\r", count, count, (double)count / (double)end * 100.0);
            }
        }
        count++;
        Sleep(ms);
        if (GetKeyState('L') < 0)
        {
            return;
        }
    }
    printf("����������ɣ�\n");
}
void calculate_log(void) // ������Ȼ�����ĵ�e
{
    double e;
    int end, ms, count;
    bool quite = false; // �Ƿ���ʾ��ϸ��Ϣ
    printf("��������ֹ����������");
    scanf("%d", &end);
    printf("������ÿ�ε������ʱ��(ms)��");
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
            printf("%lf\r", e); // ���ټ�����ϸ��Ϣ�������ʱ��
        }
        else
        {
            printf("e������: %lf   ����������%d   �������: %lf %%  ������...\r", e, count, (double)count / (double)end * 100.0);
        }
        count++;
        Sleep(ms);
        if (GetKeyState('L') < 0)
        {
            return;
        }
    }
    printf("e������ɣ�\n");
}
void calculate_factorization(void) // ���������ֽ�
{
    int number, count = 1;
    int number2 = 1; // ��bug����ʽ�ֽ����һ������û���
    printf("������һ����������");
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
    printf("�����ֽ���ɣ�\n");
}