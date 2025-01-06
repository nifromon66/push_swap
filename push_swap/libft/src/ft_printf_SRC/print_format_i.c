/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   print_format_i.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 19:41:06 by nifromon  #+##+# */
/*   Updated: 2024/11/15 22:19:29 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../../headers/ft_printf_H/ft_printf.h"

static int	print_n_10_fd(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd(INT_MIN_S, FD);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', FD);
		i++;
	}
	if (n > 9)
		i += print_n_10_fd(n / LEN_BASE_10);
	ft_putchar_fd(n % LEN_BASE_10 + 48, FD);
	i++;
	return (i);
}

void	print_format_i(t_format *format, va_list arg)
{
	int	i;

	i = va_arg(arg, int);
	if (i > 0)
		format->printed += print_n_10_fd((unsigned int) i);
	else
		format->printed += print_n_10_fd(i);
}

//END