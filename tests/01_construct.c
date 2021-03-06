       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.05.07 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.06.12 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"
#include <stdio.h>

void	*copy_list_content(const void *p_content_from)
{
	int *p_content_to;

	if ((p_content_to = malloc(sizeof(int))) == NULL)
		return (NULL);
	*p_content_to = *(int *)p_content_from;
	return (p_content_to);
}

void	free_list_content(void *content)
{
	free(content);
}

int main(void)
{
	const char 		*name_test = "Test \"01_construct.c\": ";
	t_class_list	*p_list;
	
	p_list = class_list_construct(copy_list_content, free_list_content, NULL);
	if (p_list != NULL)
	{
		class_list_destruct(&p_list);
		if (p_list == NULL)
			printf("%s%s\n", name_test, "OK");
		else
			printf("%s%s\n", name_test, "ERROR1");
	}
	else
		printf("%s%s\n", name_test, "ERROR2");
	return (0);
}