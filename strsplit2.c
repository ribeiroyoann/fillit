#include <stdio.h>
#include <stdlib.h>


static int        ft_countletter(char const *s, int c, int i)
{
    int count_letter;

    count_letter = 0;
    while (s[i] != c && s[i])
    {
        i++;
        count_letter++;
    }
    return (count_letter);
}

char        **ft_strsplit(char const *s, char c)
{
    int        i;
    int        j;
    int        k;
    char    **dest;

    i = 0;
    j = 0;
    if (!(dest = (char **)malloc(sizeof(dest) * (ft_countword(s, c) + 1))))
        return (NULL);
    while (s[i] && j < ft_countword(s, c))
    {
        k = 0;
        while (s[i] == c && s[i])
        {
            printf("A");
            i++;
        }
        dest[j] = (char *)malloc(sizeof(char)* (ft_countletter(s, c, i) + 1));
        while (s[i] != c && s[i])
        {
            printf("B");
            dest[j][k++] = s[i++];
        }
        dest[j][k++] = '\0';
        j++;
    }
    dest[j] = 0;
    return (dest);
}

int        main(void)
{
    char    *str = "split   ||this|for|me|||||teub||!|";
    int        i;
    char    **result = ft_strsplit(str, '|');

    i = 0;
    while (result[i])
    {
        printf("[%s]", result[i]);
        i++;
    }
    return (0);
}