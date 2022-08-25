#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}


int basecheck(char *base)
{       
	char	*pbase;
    int size;
    
	if (!base || !(base + 1))
		return (0);
	pbase = base;
	size = 0;
	while (base[size] != '\0')
	{
		if (base[size] == '+' || base[size] == '-')
			return (0);
		pbase = (base + size) + 1;
		while (*pbase != '\0')
		{
			if (*pbase == base[size])
				return (0);
			pbase++;
		}
	size++;
	}
    return size;
}


void ft_putnbrbased(int nb, int basse, char *base)
{   
    char    *digits;
    int   i;
    int   mul;

    digits = (char *) malloc (32);
    i = 0;
    mul = 1;
    if (nb < 0)
    {
        mul = -1;
        ft_putchar('-');
    }
    while (nb)
    {
        digits[i] = base[(nb % basse) * mul];
        nb /= basse;
        i++;
    }
    while (--i >= 0)
        ft_putchar(digits[i]);
    ft_putchar('\n');
    free(digits);
}

void ft_putnbr_base(int nbr, char *base)
{
    int basse = basecheck(base);
    if (basse == 0)
        return;
    else
        ft_putnbrbased(nbr, basse, base);
}

int main()
{
	ft_putnbr_base(-4095, "poneyvif");
	return 0;
}
