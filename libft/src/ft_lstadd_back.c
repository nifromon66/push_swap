/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_lstadd_back.c   :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <marvin@42.fr>+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/11 12:53:15 by nifromon  #+##+# */
/*   Updated: 2024/11/12 14:01:37 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../headers/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

//END
