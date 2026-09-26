/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:04:09 by joamunoz          #+#    #+#             */
/*   Updated: 2026/09/21 13:39:09 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	len;
	int	i;

	len = 0;
	while (s1[len])
		len++;
	i = 0;
	while (i <= len)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(int argc, char *argv[])
{
	int	i;
	int	unsorted;

	i = 2;
	unsorted = 1;
	while (unsorted)
	{
		unsorted = 0;
		i = 2;
		while (i < argc)
		{
			if (ft_strcmp(argv[i - 1], argv[i]) > 0)
			{
				ft_swap(&argv[i - 1], &argv[i]);
				unsorted = 1;
			}
			i++;
		}
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
}
