/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 22:53:47 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/24 16:54:32 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ft_check_isdigit(void)
{
	int		i;

	i = -5;
	while (++i < 15)
		printf("Value: %d, Ret: %d, char: %c\n", i + 48, ft_isdigit(i + 48), i + 48);
}

static void		ft_check_isalpha(void)
{
	int		i;

	i = -1;
	while (++i < 128)
		printf("Value: %d, Ret: %d, char: %c\n", i, ft_isalpha(i), i);
}

static void		ft_check_isascii(void)
{
	int		i;

	i = -10;
	while (++i < 135)
		printf("Value: %d, Ret: %d\n", i, ft_isascii(i));
}

static void		ft_check_isprint(void)
{
	int		i;

	i = -1;
	while (++i < 128)
		printf("Value: %d, Ret: %d, char: %c\n", i, ft_isprint(i), i);
}

static void		ft_check_isalnum(void)
{
	int		i;

	i = -1;
	while (++i < 128)
		printf("Value: %d, Ret: %d, char: %c\n", i, ft_isalnum(i), i);
}

static void		ft_check_toupper(void)
{
	int		i;

	i = -1;
	while (++i < 128)
		printf("Value: %d, Ret: %d, char: %c, toupper: %c\n", i, ft_toupper(i), i, ft_toupper(i));
}

static void		ft_check_tolower(void)
{
	int		i;

	i = -1;
	while (++i < 128)
		printf("Value: %d, Ret: %d, char: %c, tolower: %c\n", i, ft_tolower(i), i, ft_tolower(i));
}

static void		ft_check_bzero(void)
{
	int		i;
	char	str[] = "salut";

	printf("String is: %s\n\nBefore:\n", str);
	i = -1;
	while (++i < 6)
		printf("Value: %d\n", str[i]);
	ft_bzero(str, 6);
	printf("\nAfter:\n");
	i = -1;
	while (++i < 6)
		printf("Value: %d\n", str[i]);
}

static void		ft_check_strcat(void)
{
	char	str[15];
	char	s1[] = "salut";
	char	s2[] = " toi.";

	printf("String 1: %s\n", s1);
	printf("String 2: %s\n", s2);
	strcpy(str, s1);
	ft_strcat(str, s2);
	printf("ft_strcat: %s\n", str);
}

static void		ft_check_strlen(void)
{
	printf("String: %s, strlen: %lu, ft_strlen: %lu\n", "Salut", strlen("Salut."), ft_strlen("Salut."));
	printf("String: %s, strlen: %lu, ft_strlen: %lu\n", "1", strlen("1"), ft_strlen("1"));
	printf("String: %s, strlen: %lu, ft_strlen: %lu\n", "", strlen(""), ft_strlen(""));
	printf("String: %s, strlen: %lu, ft_strlen: %lu\n", "ddddddddddddddddddddddddd", strlen("ddddddddddddddddddddddddd"), ft_strlen("ddddddddddddddddddddddddd"));
}

static void		ft_check_puts()
{
	printf("ft_puts:\n\n");
	ft_puts("qwertyuiop");
	ft_puts("");
	ft_puts(NULL);
	ft_puts("salut.");
}

static void		ft_check_memset()
{
	char	str[] = "salut.";
	char	*test;

	printf("Memset:\n\n");
	printf("test: %s\n", str);
	test = ft_memset(str, 'i', 1);
	
	printf("test: %s\n", str);
	test = ft_memset(str, '0', 5);
	printf("test: %s\n", test);
}

static void		ft_check_memcpy()
{
	char	*test;
	char	str[15];

	printf("Memcpy:\n\n");
	bzero(str, 15);
	strcpy(str, "coucou ");
	printf("test: %s\n", str);
	test = ft_memcpy(str, "qwertyuiop", 4);
	printf("test: %s\n", test);
}

static void		ft_check_strdup()
{
	char	*str;
	char	s[] = "mdrlol";

	printf("Strdup:\n\n");
	printf("Original: %s\n", s);
	str = ft_strdup(s);
	if (!str)
		printf("NULL\n");
	else
	{
		printf("ft_strdup: %s\n", str);
		printf("adress: ft_strdup: %p, original: %p\n", str, s);
		free(str);
	}
}

static void		ft_check_cat()
{
	printf("ft_strcat:\n\n");
	ft_cat(0);
}

static void		ft_check_isspace()
{
	int		i;

	printf("ft_isspace:\n\n");
	i = -1;
	while (++i < 127)
		printf("Value: %d, Ret: %d, char: %c\n", i, ft_isspace(i), i);
}

static void		ft_check_swap()
{
	long		a;
	long		b;

	printf("ft_swap:\n\n");
	a = 10;
	b = 5;
	printf("a: %ld, pa: %p, b: %ld, pb: %p\n", a, &a, b, &b);
	ft_swap(&a, &b);
	printf("a: %ld, pa: %p, b: %ld, pb: %p\n", a, &a, b, &b);
	a = 8;
	b = 8;
	printf("a: %ld, pa: %p, b: %ld, pb: %p\n", a, &a, b, &b);
	ft_swap(&a, &b);
	printf("a: %ld, pa: %p, b: %ld, pb: %p\n", a, &a, b, &b);
	a = 0;
	b = 999;
	printf("a: %ld, pa: %p, b: %ld, pb: %p\n", a, &a, b, &b);
	ft_swap(&a, &b);
	printf("a: %ld, pa: %p, b: %ld, pb: %p\n", a, &a, b, &b);
	a = -1;
	b = -121999;
	printf("a: %ld, pa: %p, b: %ld, pb: %p\n", a, &a, b, &b);
	ft_swap(&a, &b);
	printf("a: %ld, pa: %p, b: %ld, pb: %p\n", a, &a, b, &b);
}

static void		ft_check_strcpy()
{
	char	str[15];
	char	*s;

	printf("ft_strcpy:\n\n");
	printf("string: \"salut mdr !\"\n");
	s = ft_strcpy(str, "salut mdr !");
	printf("test: %s\n", s);
	printf("string: \"\"\n");
	s = ft_strcpy(str, "");
	printf("test: %s\n", s);
}

static void		ft_check_putnbr()
{
	printf("ft_putnbr:\n\n");
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(1);
	write(1, "\n", 1);
	ft_putnbr(-1);
	write(1, "\n", 1);
	ft_putnbr(12);
	write(1, "\n", 1);
	ft_putnbr(-12);
	write(1, "\n", 1);
	ft_putnbr(123456789);
	write(1, "\n", 1);
	ft_putnbr(-123456789);

}

static void		ft_check_strcmp()
{
	printf("strcmp: %d\n", strcmp("", ""));
	printf("ft_strcmp: %d\n", ft_strcmp("", ""));
	printf("strcmp: %d\n", strcmp("salut", "saluo"));
	printf("ft_strcmp: %d\n", ft_strcmp("salut", "saluo"));
	printf("strcmp: %d\n", strcmp("sal", "sal"));
	printf("ft_strcmp: %d\n", ft_strcmp("sal", "sal"));
	printf("strcmp: %d\n", strcmp("aaaa", "bbbb"));
	printf("ft_strcmp: %d\n", ft_strcmp("aaaa", "bbbb"));
	printf("strcmp: %d\n", strcmp("bb", "bbbb"));
	printf("ft_strcmp: %d\n", ft_strcmp("bb", "bbbb"));
}

int				main(int argc, char **argv)
{
	if (argc == 2)
	{
		++argv;
		switch (atoi(*argv))
		{
			case 1:		ft_check_isdigit();	break;
			case 2:		ft_check_isascii();	break;
			case 3:		ft_check_isalpha();	break;
			case 4:		ft_check_isprint();	break;
			case 5:		ft_check_isalnum();	break;
			case 6:		ft_check_toupper();	break;
			case 7:		ft_check_tolower();	break;
			case 8:		ft_check_bzero();	break;
			case 9:		ft_check_strcat();	break;
			case 10:	ft_check_strlen();	break;
			case 11:	ft_check_puts();	break;
			case 12:	ft_check_memset();	break;
			case 13:	ft_check_memcpy();	break;
			case 14:	ft_check_strdup();	break;
			case 15:	ft_check_cat();		break;
			case 16:	ft_check_isspace();	break;
			case 17:	ft_check_swap();	break;
			case 18:	ft_check_strcpy();	break;
			case 19:	ft_check_putnbr();	break;
			case 20:	ft_check_strcmp();	break;
		}
	}
	return (0);
}
