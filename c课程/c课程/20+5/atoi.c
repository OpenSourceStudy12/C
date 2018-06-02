#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *str);

int main(int argc, char *argv[])
{
    char *ptr = " 1234 3455";
    int n;

    n = my_atoi(ptr);
    printf("myAtoi:%d/n", n);

    n = atoi(ptr);
    printf("atoi:%d/n", n);
    return 0;
}

int my_atoi(const char *str)
{
    int value = 0;
    int flag = 1; 

    while (*str == ' ')
    {
        str++;
    }

    if (*str == '-')
    {
        flag = 0;
        str++;
    }
    else if (*str == '+')
    {
        flag = 1;
        str++;
    }
    else if (*str >= '9' || *str <= '0') 
    {
        return 0;    
    }

   
    while (*str != '/0' && *str <= '9' && *str >= '0')
    {
        value = value * 10 + *str - '0'; 
        str++;
    }

    if (flag == 0)
    {
        value = -value;
    }

    return value;
}

