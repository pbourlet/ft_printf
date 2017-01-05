#include "ft_printf.h"

int	main(void)
{
	long int li = -42;
	char *p;
	p = malloc(100);
	int lu = -42;
	char ss[]="salut";
	wchar_t *ss2;

	ft_printf("ft: lol %lx\n", 42000000000000000000000);
	printf("V : lol %lx\n", 42000000000000000000000);
//	ft_printf("lol %c %i %d %l %X %lu %p %x %lc %lp %lx %lX\n", 'a', "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss);
//	printf("lol %c %i %d %l %X %lu %p %x %lc %lp %lx %lX\n", 'a', "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss);
	return (0);
}
