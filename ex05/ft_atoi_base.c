/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rod <joao-rod@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:26:19 by joao-rod          #+#    #+#             */
/*   Updated: 2022/08/24 18:24:15 by joao-rod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int basecheck(char *base)
{       // checks base and returns 10 for decimal, 1 for bin, 8 octal, 16 hex, 0 for error
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


int in_base(char c, char *base)
{
    int i;
    
    i = 0;
    while (base[i] != '\0')
    {
        if (c == base[i])
            return i;
        i++;
    }
    return -1;
}


int	ft_atoibased(char *str, char *base, int basse)
{
	int	mul;
	int	nb;
    int digit;
    
	mul = 1;
	nb = 0;
	if (str)
	{
		while (in_base(*str, base) == -1)
		{
            if (*str == '\0')
                return (0);
			if (*str == '-')
				mul *= -1;
			str++;
		}
        digit = in_base(*str, base);
        while (digit >= 0)
        {
            nb *= basse;
            nb += digit * mul;
            str++;
            printf("str: in loop: %s | curr char: %c\n", str, *str);
            digit = in_base(*str, base);
        }
	}
	return (nb);
}

    
int ft_atoi_base(char *str, char *base)
{
	int nbr;
	int basse;

	basse = basecheck(base);
	if(basse == 0)
		return (0);
	nbr = ft_atoibased(str, base, basse);
	return nbr;
}


int main()
{
	int nb = ft_atoi_base("100010", "01");
    printf("nbr: %d\n", nb);
    nb = ft_atoi_base("ffff", "poneyvif");
    printf("nbr: %d\n", nb);
	return 0;
}