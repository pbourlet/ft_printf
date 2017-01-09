#include "ft_printf.h"
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	long int li = -42;
	char *p;
	p = malloc(100);
	int lu = -42;
	char ss[]="salut";
	wchar_t *ss2;

	wchar_t a = L'文';
//	ft_printf("ft: lol %C\n", L'文');
	printf("ret: %d:", printf("%C", L'文'));
//	ft_printf("lol %c %i %d %X %lu %p %x %lc %lp %lx %lX\n", 'a', "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss);
//	printf("lol %c %i %d %X %lu %p %x %lc %lp %lx %lX\n", 'a', "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss);
	return (0);
}
