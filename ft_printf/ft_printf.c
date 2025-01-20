/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:03:38 by tboulogn          #+#    #+#             */
/*   Updated: 2024/11/22 18:07:40 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(char c, va_list *args, int *lenght)
{
	if (c == 'c')
		ft_putchar_len(va_arg(*args, int), lenght);
	else if (c == 's')
		ft_putstr_len(va_arg(*args, char *), lenght);
	else if (c == 'd')
		ft_putnbr(va_arg(*args, int), lenght);
	else if (c == 'p')
		ft_pointer(va_arg(*args, size_t), lenght);
	else if (c == 'i')
		ft_putnbr(va_arg(*args, int), lenght);
	else if (c == 'u')
		ft_unsigned_int(va_arg(*args, int), lenght);
	else if (c == 'x')
		ft_hexdec(va_arg(*args, int), lenght, 'x');
	else if (c == 'X')
		ft_hexdec(va_arg(*args, int), lenght, 'X');
	else if (c == '%')
		ft_putchar_len('%', lenght);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		lenght;
	int		i;

	i = 0;
	lenght = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_check(format[i], &args, &lenght);
			i++;
		}
		else
		{
			ft_putchar_len((char)format[i], &lenght);
			i++;
		}
	}
	va_end(args);
	return (lenght);
}

/* #include <stdio.h>

int main(void) 
{
    char test_char = 'A';                   // Pour %c
    char *test_string = "Hello, world!";    // Pour %s
    int test_int = 42;                      // Pour %d et %i
    unsigned int test_unsigned = 123456;    // Pour %u
    void *test_pointer = (void *)0x1234abcd; // Pour %p
    int test_negative = -42;                // Pour vérifier les entiers négatifs
    unsigned int test_hex = 3735928559;     // Pour %x et %X (0xDEADBEEF)

    // Test des spécificateurs avec le vrai printf
    printf("=== Test avec le vrai printf ===\n");
    int vrai_retour = printf(
        "Caractère : %c\n"
        "Chaîne : %s\n"
        "Entier signé (d) : %d\n"
        "Entier signé (i) : %i\n"
        "Entier non signé : %u\n"
        "Pointeur : %p\n"
        "Hexadécimal minuscule : %x\n"
        "Hexadécimal majuscule : %X\n"
        "Pourcentage : %%\n",
        test_char, test_string, test_int, test_negative, 
		test_unsigned, test_pointer,
        test_hex, test_hex
    );

    printf("\n=== Test avec ton ft_printf ===\n");
    // Test des spécificateurs avec ft_printf
    int ft_retour = ft_printf(
        "Caractère : %c\n"
        "Chaîne : %s\n"
        "Entier signé (d) : %d\n"
        "Entier signé (i) : %i\n"
        "Entier non signé : %u\n"
        "Pointeur : %p\n"
        "Hexadécimal minuscule : %x\n"
        "Hexadécimal majuscule : %X\n"
        "Pourcentage : %%\n",
        test_char, test_string, test_int, test_negative, 
		test_unsigned, test_pointer,
        test_hex, test_hex
    );

    // Comparaison des résultats
    printf("\n=== Résultats ===\n");
    if (vrai_retour == ft_retour) {
        printf("Les deux fonctions renvoient le même nombre de caractères.\n");
    } else {
        printf("Différence dans le retour : printf = %d, ft_printf = %d\n", 
		vrai_retour, ft_retour);
    }
} */