       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.06.12 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.06.12 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"
#include <stdio.h>
#include <string.h>

void	*copy_list_content(const void *p_content_from)
{
	char		*p_content_to;
	size_t		len;

	len = strlen(p_content_from);
	if ((p_content_to = malloc(sizeof(*p_content_to) * len)) == NULL)
		return (NULL);
	return (strcpy(p_content_to, p_content_from));
}

void	free_list_content(void *content)
{
	free(content);
}

void	show_list(t_class_list *p_list)
{
	t_list_element	*el;

	printf("=========================================================\n");
	printf("t_class_list.free_list_content: %p\n", p_list->free_list_content);
	printf("t_class_list.copy_list_content: %p\n", p_list->copy_list_content);
	printf("t_class_list.length: %lu\n", p_list->length);
	printf("t_class_list.p_element: %p\n", p_list->p_element);
	printf("=========================================================\n");

	if (p_list->p_element == NULL)
		return ;
	el = p_list->p_element;
	while (1)
	{
		printf("Адрес элемента: %p\n\n", el);
		printf("t_list_element.p_content: %1$p value: %1$s\n", (char *)(el->p_content));
		printf("t_list_element.p_last: %p\n", el->p_last);
		printf("t_list_element.p_next: %p\n", el->p_next);
		printf("=========================================================\n");
		el = el->p_next;
		if (el == p_list->p_element)
			break;
	}
}

int main(void)
{
	const char 		*name_test = "Test \"05_list_copy.c\": ";
	const char		show_lists = 0; //0 - false; 1 - true
	t_class_list	*p_list[2];

	p_list[0] = class_list_construct(copy_list_content, free_list_content, NULL);
	if (p_list[0] == NULL)
	{
		printf("%s%s\n", name_test, "ERROR class_list_construct");
		return (0);
	}

	if (class_list_create_element_to_end(p_list[0],
		"Тект первого элемента списка") == NULL)
	{
		printf("%s%s\n", name_test, "ERROR class_list_create_element_to_end");
		class_list_destruct(&p_list[0]);
		return (0);
	}

	if (class_list_create_element_to_end(p_list[0],
		"Тект второго элемента списка") == NULL)
	{
		printf("%s%s\n", name_test, "ERROR class_list_create_element_to_end");
		class_list_destruct(&p_list[0]);
		return (0);
	}

	if (class_list_create_element_to_end(p_list[0],
		"Тект третьего элемента списка") == NULL)
	{
		printf("%s%s\n", name_test, "ERROR class_list_create_element_to_end");
		class_list_destruct(&p_list[0]);
		return (0);
	}

	if ((p_list[1] = class_list_copy(p_list[0])) == NULL)
	{
		printf("%s%s\n", name_test, "ERROR class_list_copy");
		class_list_destruct(&p_list[0]);
		return (0);
	}

	if (show_lists)
	{
		printf("=========================================================\n");
		printf("*********************************************************\n");
		printf("Начальный список:\n");
		printf("*********************************************************\n");
		show_list(p_list[0]);
		printf("=========================================================\n");
		printf("*********************************************************\n");
		printf("Скопированный список:\n");
		printf("*********************************************************\n");
		show_list(p_list[1]);
	}

	class_list_destruct(&p_list[0]);
	if (p_list[0] == NULL)
	{
		class_list_destruct(&p_list[1]);
		if (p_list[0] == NULL)
			printf("%s%s\n", name_test, "OK");
		else
			printf("%s%s\n", name_test, "ERROR class_list_destruct");
	}
	else
		printf("%s%s\n", name_test, "ERROR class_list_destruct");
	return (0);
}