#include "ft_printf.h"

int	main(void)
{
	long int li = -42;
	char *p;
	p = malloc(100);
	int lu = -42;
	char ss[]="salut";

//	ft_printf("ft: lol %l %li\n", 42, 43);
//	printf("V : lol %l %li\n", 42, 43);
      ft_printf("lol %c %i %d %l %X %lu %p %x\n", 'a', "salut", 19, li, lu, p, 42, 42);
      printf("lol %c %i %d %l %X %lu %p %x\n", 'a', "salut", 19, li, lu, p, 42, 42);
	return (0);
}
