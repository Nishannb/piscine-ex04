#include <unistd.h>
#include <stdio.h>

int       ft_atoi(char *str)
{
          int       neg;
          int       i;
          int       num;

          i = 0;
          neg = 0;
          num = 0;
          while (str[i] && (str[i] < 48 || str[i] > 57))
          {
                    if(str[i] == '-')
                    {
                              neg++;
                    }
                    i++;
          }

          while (str[i] && (str[i] >= 48 && str[i] <= 57))
          {
                    num = num * 10 + str[i] - '0';
                    i++;
          }

          if(neg % 2 == 1)
                    return (num * -1);
          return (num);
}

int       main(void)
{
          char	*str;
	str = "   ---+--+1234ab567";
	printf("%d \n", ft_atoi(str));
	return (0);
}