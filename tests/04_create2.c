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
	t_class_list	*p_list;
	t_list_element  *p_elem;
	t_list_element  *p_elem2;
	t_list_element  *p_elem3;
	int six;

	six = 6;
	int seven = 7;
	int eight = 8;
	p_elem = NULL;
	p_list = class_list_construct(copy_list_content, free_list_content, NULL);
	if (p_list != NULL)
	{
		if ((p_elem = class_list_create_element_to_end(p_list, &six)) == NULL)
			printf("Test \"04_create.c\": ERROR1\n");
		if (*(int *)(p_elem->p_content) != 6)
			printf("Test \"04_create.c\": ERROR2\n");

		if (p_list->length != 1)
			printf("Test \"04_add.c\": ERROR5  %lu \n", p_list->length);
		if (*(int *)(p_list->p_element->p_content) != 6)
			printf("Test \"04_add.c\": ERROR2.1\n");

		if ((p_elem2 = class_list_create_element_to_end(p_list, &seven)) == NULL)
			printf("Test \"04_create.c\": ERROR1.2\n");
		if (p_list->length != 2)
			printf("Test \"04_add.c\": ERROR5  %lu \n", p_list->length);
		if (*(int *)(p_list->p_element->p_content) != 6)
			printf("Test \"04_add.c\": ERROR2.2 %d \n", *(int *)(p_list->p_element->p_content));
		if (*(int *)(p_list->p_element->p_next->p_content) != 7)
			printf("Test \"04_add.c\": ERROR2.3 %d \n", *(int *)(p_list->p_element->p_next->p_content));
		if (*(int *)(p_list->p_element->p_last->p_content) != 7)
			printf("Test \"04_add.c\": ERROR2.4 %d \n", *(int *)(p_list->p_element->p_last->p_content));

		if ((p_elem3 = class_list_create_element_to_start(p_list, &eight)) == NULL)
			printf("Test \"04_create.c\": ERROR1.3\n");
		if (p_list->length != 3)
			printf("Test \"04_add.c\": ERROR5  %lu \n", p_list->length);
		if (*(int *)(p_list->p_element->p_content) != 8)
			printf("Test \"04_add.c\": ERROR2.5 %d \n", *(int *)(p_list->p_element->p_content));
		if (*(int *)(p_list->p_element->p_next->p_content) != 6)
			printf("Test \"04_add.c\": ERROR2.6 %d \n", *(int *)(p_list->p_element->p_next->p_content));
		if (*(int *)(p_list->p_element->p_last->p_content) != 7)
			printf("Test \"04_add.c\": ERROR2.7 %d \n", *(int *)(p_list->p_element->p_last->p_content));

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