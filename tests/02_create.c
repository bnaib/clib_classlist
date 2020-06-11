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
	int six;

	six = 6;
	p_elem = NULL;
	p_list = class_list_construct(copy_list_content, free_list_content);
	if (p_list != NULL)
	{
		if ((p_elem = class_list_create_element(p_list, &six)) == NULL)
			printf("Test \"02_create.c\": ERROR1\n");
		if (*(int *)(p_elem->p_content) != 6)
			printf("Test \"02_create.c\": ERROR2\n");
		class_list_destruct(&p_list);
		if (p_list == NULL)
			printf("Test \"02_construct.c\": OK\n");
		else
			printf("Test \"02_construct.c\": ERROR3\n");
	}
	else
		printf("Test \"01_construct.c\": ERROR4\n");
	return (0);
}