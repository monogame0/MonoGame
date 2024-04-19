#include <stdio.h>
#include <Windows.h>
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
int main() {
    _print("Hello, world!\n", 200);
    endl(2);
    _print("This is a test program.\n", 300);
    return 0;
}