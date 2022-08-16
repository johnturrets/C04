int ft_strlen(char *str)
{
    int len = 0;
    if (!str)
        return 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}
