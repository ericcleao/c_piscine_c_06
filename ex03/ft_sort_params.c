/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecerquei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:47:08 by ecerquei          #+#    #+#             */
/*   Updated: 2019/12/07 00:00:00 by ecerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_swap(char **s1, char **s2);
void	ft_putstr(char *str);

int		main(int argc, char *argv[])
{
	int i;
	int j;

	if (argc > 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			j = i + 1;
			while (j < argc)
			{
				if (ft_strcmp(argv[i], argv[j]) > 0)
					ft_swap(&argv[i], &argv[j]);
				j++;
			}
			i++;
		}
		i = 1;
		while (i < argc)
		{
			ft_putstr(argv[i]);
			i++;
		}
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned char	left;
	unsigned char	right;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		left = (unsigned char)s1[i];
		right = (unsigned char)s2[i];
		if ((left < right) || (right < left))
		{
			return (left - right);
		}
		i++;
	}
	return (0);
}

void	ft_swap(char **s1, char **s2)
{
	char *aux;

	aux = *s1;
	*s1 = *s2;
	*s2 = aux;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
