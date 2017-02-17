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

	ftres = ft_printf("f :%.6S \n", ls);
	vres = printf("f :%.6S \n", ls);
/*	ftres = ft_printf("lol %C %i %li %d %X %lu %p %x %lc %lp %lx %lX %hc %hi\
	 %hd %hX %hu %hp %hx %jc %ji %jd %jX %ju %jp %jx %zc %zi %zd %zX %zu %zp\
	 %zx %llc %lli %lld %llX %llu %llp %llx %hhc %hhi %hhd %hhX %hhu %hhp %hhx\
	 %S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n\n", 1850, "salut",
	 19, li, lu, p, 42, 42, 30, p, ss, ss, 1850, "salut", 19, li, lu, p, 42,
	 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850,
	 "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, L"Α α",
	 L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι",
	 L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ",
	 L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	vres = printf("lol %C %i %li %d %X %lu %p %x %lc %lp %lx %lX %hc %hi\
	 %hd %hX %hu %hp %hx %jc %ji %jd %jX %ju %jp %jx %zc %zi %zd %zX %zu %zp\
	 %zx %llc %lli %lld %llX %llu %llp %llx %hhc %hhi %hhd %hhX %hhu %hhp %hhx\
	 %S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n\n", 1850, "salut",
	 19, li, lu, p, 42, 42, 30, p, ss, ss, 1850, "salut", 19, li, lu, p, 42,
	 1850, "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, 1850,
	 "salut", 19, li, lu, p, 42, 1850, "salut", 19, li, lu, p, 42, L"Α α",
	 L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι",
	 L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ",
	 L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
*/	
	ft_printf("ftres :%d\n", ftres);
	printf("vtres :%d\n", vres);
	return (0);
}
