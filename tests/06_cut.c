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
		printf("t_list_element.p_content: %p value: %1$s\n", (char *)(el->p_content));
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
	const char		show_lists = 1; //0 - false; 1 - true
	t_class_list	*p_list;
	t_list_element  *p_elem;
	t_list_element  *p_elem2;
	t_list_element  *p_elem3;
	t_list_element  *p_elem4;
	t_list_element  *p_elem5;
	t_list_element  *p_elem6;
	int six;

	six = 6;
	int seven = 7;
	int eight = 8;
	p_elem = NULL;
	p_list = class_list_construct(copy_list_content, free_list_content);
	if (p_list != NULL)
	{
		if ((p_elem = class_list_create_element_to_end(p_list, &six)) == NULL)
			printf("Test \"04_create.c\": ERROR1\n");
		if (*(int *)(p_elem->p_content) != 6)
			printf("Test \"04_create.c\": ERROR2\n");
		if (show_lists)
		{
			printf("=========================================================\n");
			printf("*********************************************************\n");
			printf("1:\n");
			printf("*********************************************************\n");
			show_list(p_list[0]);
		}

		if (p_list->length != 1)
			printf("Test \"04_add.c\": ERROR5  %lu \n", p_list->length);
		if (*(int *)(p_list->p_element->p_content) != 6)
			printf("Test \"04_add.c\": ERROR2.1\n");

		if ((p_elem2 = class_list_create_element_to_end(p_list, &seven)) == NULL)
			printf("Test \"04_create.c\": ERROR1.2\n");
		if (show_lists)
		{
			printf("=========================================================\n");
			printf("*********************************************************\n");
			printf("2:\n");
			printf("*********************************************************\n");
			show_list(p_list[0]);
		}

		if ((p_elem3 = class_list_create_element_to_start(p_list, &eight)) == NULL)
			printf("Test \"04_create.c\": ERROR1.3\n");
		if (show_lists)
		{
			printf("=========================================================\n");
			printf("*********************************************************\n");
			printf("3:\n");
			printf("*********************************************************\n");
			show_list(p_list[0]);
		}

		if ((p_elem4 = class_list_create_element_to_end(p_list, &six)) == NULL)
			printf("Test \"04_create.c\": ERROR1\n");
		if (*(int *)(p_elem->p_content) != 6)
			printf("Test \"04_create.c\": ERROR2\n");
		if (show_lists)
		{
			printf("=========================================================\n");
			printf("*********************************************************\n");
			printf("4:\n");
			printf("*********************************************************\n");
			show_list(p_list[0]);
		}

		if (p_list->length != 1)
			printf("Test \"04_add.c\": ERROR5  %lu \n", p_list->length);
		if (*(int *)(p_list->p_element->p_content) != 6)
			printf("Test \"04_add.c\": ERROR2.1\n");

		if ((p_elem5 = class_list_create_element_to_end(p_list, &seven)) == NULL)
			printf("Test \"04_create.c\": ERROR1.2\n");
		if (show_lists)
		{
			printf("=========================================================\n");
			printf("*********************************************************\n");
			printf("5:\n");
			printf("*********************************************************\n");
			show_list(p_list[0]);
		}

		if ((p_elem6 = class_list_create_element_to_start(p_list, &eight)) == NULL)
			printf("Test \"04_create.c\": ERROR1.3\n");
		if (show_lists)
		{
			printf("=========================================================\n");
			printf("*********************************************************\n");
			printf("6:\n");
			printf("*********************************************************\n");
			show_list(p_list[0]);
		}

		

		class_list_destruct(&p_list);
		if (p_list == NULL)
			printf("Test \"04_construct.c\": OK\n");
		else
			printf("Test \"04_construct.c\": ERROR3\n");
	}
	else
		printf("Test \"04_construct.c\": ERROR4\n");
	return (0);
}