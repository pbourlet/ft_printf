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

//	ftres = ft_printf("f :%li\n", 42);
//	vres = printf("v :%li\n", 42);
	ftres = ft_printf("lol %C %i %l %d %X %lu %p %x %lc %lp %lx %lX\n", 1850, "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss);
	    vres = printf("lol %C %i %l %d %X %lu %p %x %lc %lp %lx %lX\n", 1850, "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss);
	ft_printf("ftres: %d\n", ftres);
	printf("vres: %d\n", vres);
	return (0);
}
