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
	const char 		*name_test = "Test \"02_create.c\": ";
	t_class_list	*p_list;
	t_list_element  *p_elem;
	int six;

	six = 6;
	p_elem = NULL;
	p_list = class_list_construct(copy_list_content, free_list_content);
	if (p_list != NULL)
	{
		if ((p_elem = class_list_create_element(p_list, &six)) == NULL)
			printf("%s%s\n", name_test, "ERROR1");
		if (*(int *)(p_elem->p_content) != 6)
			printf("%s%s\n", name_test, "ERROR2");
		class_list_destruct(&p_list);
		if (p_list == NULL)
			printf("%s%s\n", name_test, "OK");
		else
			printf("%s%s\n", name_test, "ERROR3");
	}
	else
		printf("%s%s\n", name_test, "ERROR4");
	return (0);
}