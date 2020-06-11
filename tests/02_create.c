#include "class_list.h"
#include <stdio.h>

void	free_list_content(void *content)
{
	free(content);
}

int main(void)
{
	t_class_list	*p_list;
	t_list_element  *p_elem;
	
	p_elem = NULL;
	p_list = class_list_construct(sizeof(int), free_list_content);
	if (p_list != NULL)
	{
		int six = 6;
		p_elem = class_list_create_element(p_list, &six);
		if (p_elem == NULL)
			printf("Test \"02_create.c\": ERROR1\n");
		if (*(int *)(p_elem->p_content) != 6)
			printf("Test \"02_create.c\": ERROR2\n");
		printf("Test \"02_create.c\": p_elem->p_content %d \n", *(int *)(p_elem->p_content));
		class_list_destruct(&p_list);
		if (p_list == NULL)
			printf("Test \"02_construct.c\": OK\n");
		else
			printf("Test \"02_construct.c\": ERROR1\n");
	}
	else
		printf("Test \"01_construct.c\": ERROR2\n");
	return (0);
}