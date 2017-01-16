#include "ft_printf.h"
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	long int li = -42;
	char *p;
	p = malloc(100);
	int lu = -42;
	char ss[]="saluté";
	wchar_t *ss2;
	wchar_t a = L'文';
	int	ftres;
	int	vres;

//	ftres = ft_printf("f :%llp\n", p);
//	vres = printf("v :%llp\n", p);
	ftres = ft_printf("lol %C %i %l %d %X %lu %p %x %lc %lp %lx %lX %hc %hi %hd %hX %hu %hp %hx %jc %ji %jd %jX %ju %jp %jx %zc %zi %zd %zX %zu %zp %zx %llc %lli %lld %llX %llu %llp %llx %hhc %hhi %hhd %hhX %hhu %hhp %hhx\n", 1850, "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42);
	vres = printf("lol %C %i %l %d %X %lu %p %x %lc %lp %lx %lX %hc %hi %hd %hX %hu %hp %hx %jc %ji %jd %jX %ju %jp %jx %zc %zi %zd %zX %zu %zp %zx %llc %lli %lld %llX %llu %llp %llx %hhc %hhi %hhd %hhX %hhu %hhp %hhx\n", 1850, "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42);
	ft_printf("ftres: %d\n\n", ftres);
	printf("vtres: %d\n\n", vres);
	return (0);
}
