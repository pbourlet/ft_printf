#include "ft_printf.h"
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	long int li = -42;
	char *p;
	p = malloc(100);
	int lu = -42;
	char	*ss = L"salut";  
	wchar_t	*ls = L"我是฀Ꮺ猫。";
	wchar_t *ss2 = L"文é";
	wchar_t a = L'文';
	wchar_t b = L'é';
	int	ftres;
	int	vres;

//	ft_printf("%S%S%S%S\n", ss, L"我", L"猫", ls);
	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");

//	vres = printf("a%Sb%sc%S\n", L"我", "42", L"猫");
//	ftres = ft_printf("f :%10ls % %5t %+-d %.4s\t%#2.5+10x\n", ls + 1, 42, NULL, 50);
//	vres = printf("v :%10ls % %5t %+-d %.4s\t%#2.5+10x\n", ls + 1, 42, NULL, 50);
//	ftres = ft_printf("lol %C %i %li %d %X %lu %p %x %lc %lp %lx %lX %hc %hi %hd %hX %hu %hp %hx %jc %ji %jd %jX %ju %jp %jx %zc %zi %zd %zX %zu %zp %zx %llc %lli %lld %llX %llu %llp %llx %hhc %hhi %hhd %hhX %hhu %hhp %hhx\n\n", 1850, "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42);
//	vres = printf("lol %C %i %li %d %X %lu %p %x %lc %lp %lx %lX %hc %hi %hd %hX %hu %hp %hx %jc %ji %jd %jX %ju %jp %jx %zc %zi %zd %zX %zu %zp %zx %llc %lli %lld %llX %llu %llp %llx %hhc %hhi %hhd %hhX %hhu %hhp %hhx\n\n", 1850, "salut", 19, li, lu, p, 42, 42, 30, p, ss, ss, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42);
//	ft_printf("ftres :%d\n", ftres);
//	printf("vtres :%d\n", vres);
	return (0);
}
