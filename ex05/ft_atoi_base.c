#include <unistd.h>
#include<stdio.h>

int       ft_in_base(char c, char *base)
{
          int       i;

          i = 1;
          while (base[i])
          {
                    if (c == base[i])
                    {
                              return (i);
                    }         
                    i++;
          }
          
          return (-1);
}

int       ft_get_len(char *base)
{
          int       i;

          i = 0;
          while (base[i])
          {
                 if (base[i] == '+' || base[i] == '-' || base[i] == ' ' 
                    || ft_in_base(base[i], base + i + 1) >= 0
                    || (base[i] >= 9 && base[i] <= 13))
                 {
                    
                    return (0);
                 }
                    i++;
          }
          return (i);
}

int       ft_check_negative(char *str)
{
          int       neg;

          neg = 0;
          while (*str)
          {
                    if(*str == '-')
                    {
                              neg++;
                    }
                    str++;
          }
          return (neg);
}

int ft_atoi_base(char *str, char *base)
{
          int       size;
          int       neg;
          int       num;
          int       i;

          // Checks validity of the base & size
          size = ft_get_len(base);
          
          if(size < 2)
                    return (0);
          // Checks total no. of Negative signs
          
          neg = ft_check_negative(str);
          
          
          num = 0;
          while ((i = ft_in_base(*str, base)) >= 0)
          {
                    num = num * size + i;
                    str++;
          }
          
          
          if(neg % 2 == 1)
                    return (num * -1);
          printf("%d",num);
          return (num);
}

int main(void)
{
          ft_atoi_base("1A3F", "0123456789ABCDEF");
          return (0);
}