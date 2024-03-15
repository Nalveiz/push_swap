/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:17:09 by musozer           #+#    #+#             */
/*   Updated: 2023/10/30 17:43:08 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	sayi;

	sayi = (long)n;
	if (sayi == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (sayi < 0)
	{
		ft_putchar_fd('-', fd);
		sayi *= -1;
	}
	if (sayi > 9)
	{
		ft_putnbr_fd(sayi / 10, fd);
		ft_putnbr_fd(sayi % 10, fd);
	}
	else
		ft_putchar_fd(sayi + 48, fd);
}
