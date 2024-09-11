#include <unistd.h>

void      ft_putchar(char c)
{
       write(1, &c, 1);   
}

int       ft_is_valid(char c, char *base)
{
          while (*base)
          {
                    if(c == *base++)
                              return (1);
          }
          return (0);
}

void      ft_print(unsigned int n, char *base, unsigned int basesize)
{
          if (n > basesize - 1)
          {
                    ft_print(n / basesize, base, basesize);
                    n = n % basesize;
          }
          ft_putchar(base[n]);
}

void      ft_putnbr_base(int nbr, char *base)
{
          int       i;

          i = 0;
          while (base[i])
          {
                 if (base[i] == '+' || base[i] == '-' || base[i] == ' ' 
                    || ft_is_valid(base[i], base + i + 1) 
                    || (base[i] >= 9 && base[i] <= 13))
                 {
                    return;
                 }
                    i++;
          } 
          if(i < 2)
                    return;
          if (nbr < 0)
          {
                    ft_putchar('-');
                    ft_print(-nbr, base, i);
          }
          else
          {
                    ft_print(nbr, base, i);
          }
}

int main(void)
{
          ft_putnbr_base(250, "0123456789ABCDEF");
          return 0;
}