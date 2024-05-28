#include "libft.h"

void	print_list(t_list *mylist)
{
	t_list	*lst;

	lst = mylist;
	while (lst->next)
	{
		printf("%s --> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("%s\n", (char *)lst->content);
}
