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
void calculate_pi(void)  //����Բ����
{
    int Mark = 1;
    double pi = 0.0;
    int count, end, ms;  //����������ֹ����������ÿ�ε������ʱ��
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
         printf("PI������: %lf   ����������%d   �������: %lf %%  ������...\r", pi, count, (double)count / (double)end * 100.0);
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
double exp(double x, int y) //����x��y�η�
{
    double _return = 1.0;
    while(y > 0)
    {
        _return *= x;
        y--;
    }
    return _return;
}
void calculate_log(void)   //������Ȼ�����ĵ�e
{
    double e;
    int end, ms, count;
    bool quite = false;  //�Ƿ���ʾ��ϸ��Ϣ
    printf("��������ֹ����������");
    scanf("%d", &end);
    printf("������ÿ�ε������ʱ��(ms)��");
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
            printf("%lf\r", e);   //���ټ�����ϸ��Ϣ�������ʱ��
        }
        else
        {
            printf("e������: %lf   ����������%d   �������: %lf %%  ������...\r", e, count, (double)count / (double)end * 100.0);
        }
        count++;
        Sleep(ms);
        if(GetKeyState('L') < 0)
        {
            return;
        }
    }
    printf("e������ɣ�\n");
}
    
int main() {
    calculate_log();
    endl(1);
    _print("Hello, world!\n", 200);
    endl(2);
    _print("This is a test program.\n", 300);
    return 0;
}