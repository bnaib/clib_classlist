       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.05.07 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.06.11 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"

t_class_list					*class_list_construct(
	void *(*copy_list_content)(const void *),
	void (*free_list_content)(void *))
{
	t_class_list	*p_list;

	if ((p_list = malloc(sizeof(*p_list))) == NULL)
		return (NULL);
	p_list->free_list_content = free_list_content;
	p_list->copy_list_content = copy_list_content;
	p_list->length = 0;
	p_list->p_element = NULL;
	return (p_list);
}

void							class_list_destruct(
	t_class_list **pp_list)
{
	t_list_element	*p_current;
	t_list_element	*p_next;
	size_t			i;

	p_next = (*pp_list)->p_element;
	i = 0;
	while (i++ < (*pp_list)->length)
	{
		p_current = p_next;
		p_next = p_current->p_next;
		if (p_current->p_content != NULL)
			(*pp_list)->free_list_content(p_current->p_content);
		free(p_current);
	}
	free(*pp_list);
	*pp_list = NULL;
}
