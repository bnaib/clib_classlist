# C library - class list  
## Description  
It is library for easy use of lists.  
I created it for myself and didn't thing about sell.  
If you want, you can use, and change it, but can't sell it.  
You use it at your own risk, I will not have any responsibility.  
  
***Version 0.1***  
Not completed yet. In testing process...  
  
## Installation
- Сopy this project to your computer.  
You can use the following command in your terminal.  
    <pre>git clone https://github.com/bnaib/clib_classlist.git</pre>  
- Build a library.  
Makefile use gcc. If you have not it, download and install gcc.  
Open folder "clib_classlist" and use command.
    <pre>make</pre>  
- If build sucessed, you will can see file "libclasslist.a".
- You can use standart make rules.  
    <pre>make clean</pre>  
    <pre>make fclean</pre>  
    <pre>make re</pre>  
- You can use tests.  
    <pre>make runtests</pre>  
  
## Way to use  
In your project, add static library "libclasslist.a" and
use header file "class_list.h" from folder "inc".  
    <pre>gcc -I ~/clib_classlist/inc/ yourproject.c -L ~/clib_classlist/ -lclasslist</pre>
    <pre>#include "class_list.h"</pre>  
  
## Content  

- Structures:  
    <pre>  
    typedef struct      s_class_list t_class_list;
    struct              s_class_list {
        void            (*free_list_content)(void *);
        void            *(*copy_list_content)(const void *);
        t_class_list    *(*acopy_list_content)(t_class_list *, const t_class_list *);
        size_t          length;
        t_list_element  *p_element;
    };
    </pre>
    **t_class_list** - Basic type for using classlist.  
    **t_class_list fields** - It is private! Do not edit the values! Most likely uses the library functions to access these fields.  
    - **free_list_content** - Function pointer for freeing the contents of a list element.  
    - **copy_list_content** - Function pointer for copying the contents of a list element.  
    - **acopy_list_content** - Function pointer for fixing the copied list after base copying.  
    - **length** - Count elements of list  
    - **p_element** - Pointer to root of list  
    <pre>
    typedef struct              s_list_element
    {
        void                    *p_content;
        struct s_list_element   *p_last;
        struct s_list_element   *p_next;
    }                           t_list_element;
    </pre>
    **t_list_element** - Basic type for using classlist element.  
    **t_list_element fields** - It is private! Do not edit the values!  
    - **p_content** - Pointer to content of element.  
    - **p_next** - Pointer to next element.  
    - **p_last** - Pointer to last element.  

Description of functions coming soon...
