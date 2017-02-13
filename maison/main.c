#include "ft_printf.h"
#include <locale.h>
#include <limits.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	long int li = -42;
	char *p;
	int lu = -42;
	char	*ss = L"salut";  
	wchar_t	*ls = L"我是฀Ꮺ猫。";
	wchar_t *ss2 = L"文é";
	wchar_t a = L'文';
	wchar_t b = L'é';
	int	ftres;
	int	vres;

 ft_printf("%");
 ft_printf("% ");
 ft_printf("% h");
 ft_printf("%Z");
 ft_printf("% hZ");
 ft_printf("%05%");
 ft_printf("%-05%");
 ft_printf("% hZ%");
 ft_printf("% Z", "test");
 ft_printf("% Z ", "test");
 ft_printf("% Z%s", "test");
 ft_printf("%000   %", "test");
 ft_printf("%%%", "test");
 ft_printf("%%   %", "test");
 ft_printf("%ll#x", 9223372036854775807);
 ft_printf("%010s is a string", "this");
 ft_printf("%-010s is a string", "this");
 ft_printf("%05c", 42);
 ft_printf("% Z", 42);
 ft_printf("%0 d", 42);
 ft_printf("%0 d", -42);
 ft_printf("% 0d", 42);
 ft_printf("% 0d", -42);
 ft_printf("%5+d", 42);
 ft_printf("%5+d", -42);
 ft_printf("%-5+d", 42);
 ft_printf("%-0+5d", 42);
 ft_printf("%-5+d", -42);
 ft_printf("%-0+5d", -42);
 ft_printf("%zhd", "4294967296");
ft_putendl("\n\n-----------------------------------\n");
 printf("%");
 printf("% ");
 printf("% h");
 printf("%Z");
printf("% hZ");
 printf("%05%");
 printf("%-05%");
 printf("% hZ%");
 printf("% Z", "test");
 printf("% Z ", "test");
 printf("% Z%s", "test");
 printf("%000   %", "test");
 printf("%%%", "test");
 printf("%%   %", "test");
 printf("%ll#x", 9223372036854775807);
 printf("%010s is a string", "this");
 printf("%-010s is a string", "this");
 printf("%05c", 42);
 printf("% Z", 42);
 printf("%0 d", 42);
 printf("%0 d", -42);
 printf("% 0d", 42);
 printf("% 0d", -42);
 printf("%5+d", 42);
 printf("%5+d", -42);
 printf("%-5+d", 42);
 printf("%-0+5d", 42);
 printf("%-5+d", -42);
 printf("%-0+5d", -42);
 printf("%zhd", "4294967296");
//	vres = printf("@main_vtprintf: %####0000 33..1..#00d\n", 256);
//	ftres = ft_printf("lol %C %i %li %d %X %lu %p %x %lc %lp %lx %lX %hc %hi %hd %hX %hu %hp %hx %jc %ji %jd %jX %ju %jp %jx %zc %zi %zd %zX %zu %zp %zx %llc %lli %lld %llX %llu %llp %llx %hhc %hhi %hhd %hhX %hhu %hhp %hhx\n\n", 1850, "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42);
//	vres = printf("lol %C %i %li %d %X %lu %p %x %lc %lp %lx %lX %hc %hi %hd %hX %hu %hp %hx %jc %ji %jd %jX %ju %jp %jx %zc %zi %zd %zX %zu %zp %zx %llc %lli %lld %llX %llu %llp %llx %hhc %hhi %hhd %hhX %hhu %hhp %hhx\n\n", 1850, "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42);
//	ft_printf("ftres :%d\n", ftres);
//	printf("vtres :%d\n", vres);
	return (0);
}
