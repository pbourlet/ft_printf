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
	int	ftres;
	int	vres;

	ftres = ft_printf("f :%ji\n", 42000000000000000);
	vres = printf("v :%ji\n", 420000000000000000);
//	ftres = ft_printf("lol %C %i %l %d %X %lu %p %x %lc %lp %lx %lX %hc %hi %hd %hX %hu %hp %hx\n", 1850, "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss, 1850, "salut", 19, li, lu, p, 42);
//	vres = printf("lol %C %i %l %d %X %lu %p %x %lc %lp %lx %lX %hc %hi %hd %hX %hu %hp %hx\n", 1850, "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss, 1850, "salut", 19, li, lu, p, 42);
	ft_printf("ftres: %d\n", ftres);
	printf("vres: %d\n", vres);
	return (0);
}
