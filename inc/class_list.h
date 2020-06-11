       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.05.07 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.06.11 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __CLASS_LIST_H
# define __CLASS_LIST_H

# include <stdlib.h>

typedef struct					s_list_element
{
	void						*p_content;
	struct s_list_element		*p_last;
	struct s_list_element		*p_next;
}								t_list_element;

typedef struct					s_class_list
{
	void						(*free_list_content)(void *);      
	size_t						length;
	size_t						content_size;
	t_list_element				*p_element;
}								t_class_list;

t_class_list					*class_list_construct(
	size_t content_size,
	void (*free_list_content)(void *));
void							class_list_destruct(
	t_class_list **pp_list);

void							class_list_add_to_end(
	t_class_list *p_list,
	t_list_element *p_element);
void							class_list_add_to_start(
	t_class_list *p_list,
	t_list_element *p_element);

t_list_element					*class_list_create_element(
	const t_class_list *p_list,
	const void *p_content);
t_list_element					*class_list_create_element_to_end(
	t_class_list *p_list,
	const void *p_content);
t_list_element					*class_list_create_element_to_start(
	t_class_list *p_list,
	const void *p_content);

t_list_element					*class_list_get_root(
	const t_class_list *p_list);
t_list_element					*class_list_get_end(
	const t_class_list *p_list);
t_list_element					*class_list_get_element_from_start_index(
	const t_class_list *p_list,
	size_t index);
t_list_element					*class_list_get_element_from_end_index(
	const t_class_list *p_list,
	size_t index);

void							class_list_cut_element(
	t_class_list *p_list,
	t_list_element *p_element);
t_list_element					*class_list_cut_root(
	t_class_list *p_list);
t_list_element					*class_list_cut_end(
	t_class_list *p_list);
t_list_element					*class_list_cut_element_from_start_index(
	t_class_list *p_list,
	size_t index);
t_list_element					*class_list_cut_element_from_end_index(
	t_class_list *p_list,
	size_t index);

void							class_list_del_element(
	t_class_list *p_list,
	t_list_element **pp_element);
void				class_list_del_root(
	t_class_list *p_list);
void				class_list_del_end(
	t_class_list *p_list);
void				class_list_del_element_from_start_index(
	t_class_list *p_list,
	size_t index);
void				class_list_del_element_from_end_index(
	t_class_list *p_list,
	size_t index);
#endif