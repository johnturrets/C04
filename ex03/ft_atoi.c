#include <stdio.h>

int ft_atoi(char *str)
{   // 1 : + , -1 : -
    int sign = 1; 
    int nb = 0;
    if (str)
    {
        while (!(*str <= '9' && *str >= '0'))
        {
            if (*str == '-')
                sign *= -1;
            str++;
        }       // exits this on first digit in string, then start adding after it isnt a '0'
        
        while (*str <= '9' && *str >= '0')
        {
            nb *= 10;
            nb += (*str - '0') * sign;
            str++;
        }
    }
    return nb;
}


int main(void)
{
    char *str = "opakds-+-+-+-00001230987";
    printf("nb: %d\n", ft_atoi(str));
    return 0;
}

