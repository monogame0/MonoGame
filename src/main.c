#include "../include/commandline.h"
int main(int argc, char *argv[]) 
{
    int ret = 0;
    //SDL_Window *window;
    while(true)
    {
        ret = welcome();
        switch(ret)
        {
        case PI:
            calculate_pi();
            break;
        case E:
            calculate_log();
            break;
        case IS_PRIME:
            printf("����������:");
            int num;
            scanf("%d", &num);
            if(is_prime(num))
            {
                printf("%d������\n", num);
            }
            else
            {
                printf("%d��������\n", num);
            }
        case PRIME:
                calculate_prime();
                break;
        case FACTORIZATION:
                calculate_factorization();
                break;
        case 13:
                return 0;
        }
        endl(1);
    }
}