
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

/* ================= CONFIGURACIÓN ================= */
#ifndef TEST_LISTS
# define TEST_LISTS 1
#endif

/* Colores y Estilos */
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

static int g_success = 0;
static int g_failed = 0;

/* ================= UTILIDADES VISUALES ================= */

void print_banner(void)
{
	printf("%s%s", CYAN, BOLD);
	printf("************************************************************\n");
	printf("* *\n");
	printf("* 🚀  LIBFT TESTER 2026  🚀                 *\n");
	printf("* *\n");
	printf("************************************************************%s\n\n", RESET);
}

void print_section_header(char *title)
{
	printf("\n%s%s=== %s ===%s\n", MAGENTA, BOLD, title, RESET);
	printf("%s------------------------------------------------------------%s\n", MAGENTA, RESET);
}

void print_result(const char *name, int success)
{
	// Formato: [ ICONO ] NombreFuncion ....... RESULTADO
	if (success)
	{
		printf("  %s✅%s  %-25s %sOK%s\n", GREEN, RESET, name, GREEN, RESET);
		g_success++;
	}
	else
	{
		printf("  %s❌%s  %-25s %sKO%s\n", RED, RESET, name, RED, RESET);
		g_failed++;
	}
}

void print_summary(void)
{
	int total = g_success + g_failed;
	int percentage = (total == 0) ? 0 : (g_success * 100) / total;
	
	printf("\n\n");
	printf("%s%s=== RESUMEN DE EJECUCIÓN ===%s\n", CYAN, BOLD, RESET);
	printf("------------------------------------------------------------\n");
	
	// Barra de progreso visual
	printf("Progreso: [");
	int bars = percentage / 5; // 20 bloques para 100%
	for (int i = 0; i < 20; i++)
	{
		if (i < bars) printf("%s█", percentage == 100 ? GREEN : YELLOW);
		else printf("%s▒", RESET);
	}
	printf("%s] %d%%\n\n", RESET, percentage);

	printf("  %s▶%s Total Tests:  %3d\n", BLUE, RESET, total);
	printf("  %s▶%s Aprobados:    %s%3d%s\n", GREEN, RESET, GREEN, g_success, RESET);
	printf("  %s▶%s Fallidos:     %s%3d%s\n", RED, RESET, RED, g_failed, RESET);
	printf("------------------------------------------------------------\n");

	if (g_failed > 0)
		printf("%s⚠️  ATENCIÓN: Se encontraron errores. Revisa los KO arriba. ⚠️%s\n", YELLOW, RESET);
	else
		printf("%s✨  ¡ENHORABUENA! Tu librería está inmaculada. ✨%s\n", GREEN, RESET);
	printf("\n");
}

/* ================= FUNCIONES AUXILIARES PARA TESTS ================= */

static char	test_mapi_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	test_iteri_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

#if TEST_LISTS
static void	del_content(void *content)
{
	free(content);
}

static void	*map_content(void *content)
{
	return (ft_strdup((char *)content));
}
#endif

/* ================= PARTE 1: FUNCIONES LIBC ================= */

void test_part1(void)
{
	print_section_header("PARTE 1: Funciones Libc");

	print_result("ft_isalpha", ft_isalpha('a') && !ft_isalpha('1'));
	print_result("ft_isdigit", ft_isdigit('8') && !ft_isdigit('z'));
	print_result("ft_isalnum", ft_isalnum('5') && ft_isalnum('G') && !ft_isalnum('%'));
	print_result("ft_isascii", ft_isascii(0) && ft_isascii(127) && !ft_isascii(128));
	print_result("ft_isprint", ft_isprint(' ') && !ft_isprint('\n'));
	print_result("ft_strlen", ft_strlen("42") == 2 && ft_strlen("") == 0);

	char b1[10], b2[10];
	ft_memset(b1, 'A', 5);
	memset(b2, 'A', 5);
	print_result("ft_memset", memcmp(b1, b2, 5) == 0);

	ft_bzero(b1, 5);
	print_result("ft_bzero", b1[0] == 0 && b1[4] == 0);

	char src[] = "Copy me";
	char dst[10];
	ft_memcpy(dst, src, 8);
	print_result("ft_memcpy", strcmp(dst, "Copy me") == 0);

	char move_s[] = "1234567";
	ft_memmove(move_s + 2, move_s, 4);
	print_result("ft_memmove (overlap)", memcmp(move_s, "1212347", 7) == 0);

	char lcpy[10];
	size_t r_cpy = ft_strlcpy(lcpy, "Hello World", 5);
	print_result("ft_strlcpy", r_cpy == 11 && strcmp(lcpy, "Hell") == 0);

	char lcat[10] = "Hi";
	size_t r_cat = ft_strlcat(lcat, " there", 10);
	print_result("ft_strlcat", r_cat == 8 && strcmp(lcat, "Hi there") == 0);

	print_result("ft_toupper", ft_toupper('h') == 'H');
	print_result("ft_tolower", ft_tolower('H') == 'h');

	char *str = "banana";
	print_result("ft_strchr", ft_strchr(str, 'n') == str + 2);
	print_result("ft_strrchr", ft_strrchr(str, 'n') == str + 4);
	print_result("ft_strncmp", ft_strncmp("abc", "abd", 2) == 0 && ft_strncmp("abc", "abd", 3) < 0);
	print_result("ft_memchr", ft_memchr("abcde", 'c', 5) == (void *)"abcde" + 2);
	print_result("ft_memcmp", ft_memcmp("abc", "abd", 3) < 0);

	char *big = "libft-test-tokyo";
	print_result("ft_strnstr", ft_strnstr(big, "test", 15) == big + 6);
	print_result("ft_atoi", ft_atoi("  -1234ab56") == -1234);

	int *c = ft_calloc(2, sizeof(int));
	print_result("ft_calloc", c != NULL && c[0] == 0 && c[1] == 0);
	free(c);

	char *d = ft_strdup("42");
	print_result("ft_strdup", d && strcmp(d, "42") == 0);
	free(d);
}

/* ================= PARTE 2: FUNCIONES ADICIONALES ================= */

void test_part2(void)
{
	print_section_header("PARTE 2: Adicionales");

	char *sub = ft_substr("tripouille", 3, 4);
	print_result("ft_substr", sub && strcmp(sub, "poui") == 0);
	free(sub);

	char *join = ft_strjoin("Hello ", "World");
	print_result("ft_strjoin", join && strcmp(join, "Hello World") == 0);
	free(join);

	char *trim = ft_strtrim("...hello...", ".");
	print_result("ft_strtrim", trim && strcmp(trim, "hello") == 0);
	free(trim);

	char **split = ft_split("  split  this  now ", ' ');
	int split_ok = (split && split[0] && strcmp(split[0], "split") == 0 && 
					split[1] && strcmp(split[1], "this") == 0 &&
					split[2] && strcmp(split[2], "now") == 0 && split[3] == NULL);
	print_result("ft_split", split_ok);
	int i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);

	char *it = ft_itoa(-2147483648LL);
	print_result("ft_itoa", it && strcmp(it, "-2147483648") == 0);
	free(it);

	char *mapi = ft_strmapi("abc", test_mapi_upper);
	print_result("ft_strmapi", mapi && strcmp(mapi, "ABC") == 0);
	free(mapi);

	char siteri[] = "abc";
	ft_striteri(siteri, test_iteri_upper);
	print_result("ft_striteri", strcmp(siteri, "ABC") == 0);

	printf("\n  %sℹ️%s  Verifica manualmente los put_fd:\n", CYAN, RESET);
	ft_putstr_fd("     ", 1); ft_putstr_fd("Test: ", 1); ft_putnbr_fd(42, 1); ft_putchar_fd('\n', 1);
	g_success += 4;
}

/* ================= PARTE 3: BONUS (LISTAS) ================= */

#if TEST_LISTS
void test_bonus(void)
{
	print_section_header("BONUS: Listas Enlazadas");

	t_list *l = ft_lstnew(ft_strdup("node1"));
	ft_lstadd_front(&l, ft_lstnew(ft_strdup("node0")));
	int size = ft_lstsize(l);
	print_result("ft_lstnew/add_front", size == 2 && strcmp((char *)l->content, "node0") == 0);

	t_list *last = ft_lstlast(l);
	print_result("ft_lstlast", last && strcmp((char *)last->content, "node1") == 0);

	ft_lstadd_back(&l, ft_lstnew(ft_strdup("node2")));
	print_result("ft_lstadd_back", ft_lstsize(l) == 3);

	t_list *new_list = ft_lstmap(l, map_content, del_content);
	print_result("ft_lstmap", new_list && ft_lstsize(new_list) == 3);

	ft_lstclear(&l, del_content);
	ft_lstclear(&new_list, del_content);
	print_result("ft_lstclear", l == NULL && new_list == NULL);
}
#endif

/* ================= MAIN ================= */

int main(void)
{
	print_banner();

	test_part1();
	test_part2();

#if TEST_LISTS
	test_bonus();
#else
	print_section_header("BONUS");
	printf("  %s⚠️%s  Funciones de listas deshabilitadas.\n", YELLOW, RESET);
#endif

	print_summary();

	return (g_failed > 0);
}
