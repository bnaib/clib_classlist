       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.07.10 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.07.10 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"

void	class_list_swap_elements(
	t_list_element *p_el1,
	t_list_element *p_el2)
{
	t_list_element *p_tmp;

	p_tmp = p_el1->p_next;
	p_el1->p_next = p_el2->p_next;
	p_el2->p_next = p_tmp;
	p_tmp = p_el1->p_last;
	p_el1->p_last = p_el2->p_last;
	p_el2->p_last = p_tmp;	
}

void	class_list_sort(
	t_class_list *p_list,
	int (*list_elements_cmp)(t_list_element *, t_list_element *),
	t_type_sort type_sort)
{
	size_t			i;
	t_list_element	*p_element;

	i = 0;
	while (++i < p_list->length)
	{
		p_element = class_list_get_root(p_list);
		if (type_sort == ASC &&
			list_elements_cmp(p_element, p_element->p_next) > 0)
			class_list_swap_elements(p_element, p_element->p_next);
		else if (type_sort == DESC &&
			list_elements_cmp(p_element, p_element->p_next) < 0)
			class_list_swap_elements(p_element, p_element->p_next);
	}
}
