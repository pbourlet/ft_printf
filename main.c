#include "ft_printf.h"

int	main(void)
{
	long int li = -42;
	char *p;
	p = malloc(100);
	int lu = -42;
	char ss[]="salut";
	wchar_t *test;

	test = ss;
//	ft_printf("ft: lol %S\n", test);
//	printf("V : lol %ls\n", "t");
      ft_printf("lol %c %i %d %ld %X %lu %p %x\n", 'a', "salut", 19, li, lu, p, 42, 42);
      printf("lol %c %i %d %ld %X %lu %p %x\n", 'a', "salut", 19, li, lu, p, 42, 42);
	return (0);
}
