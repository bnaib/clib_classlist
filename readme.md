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
Makefile use gcc. If you havn't it, download and set gcc.  
Open folder "clib_classlist" and use command.
    <pre>make</pre>  
- If build sucessed, you will can see file "libclasslib.a".
- You can use standart make rules.  
    <pre>make clean</pre>  
    <pre>make fclean</pre>  
    <pre>make re</pre>  
- You can use tests.  
    <pre>make runtests</pre>  
  
## Way to use  
In your project, add static library "libclasslib.a" and
use header file "class_list.h" from folder "inc".  
    <pre>gcc yourproject.c -L ~/clib_classlist/ -lclasslist</pre>
    <pre>#include "class_list.h"</pre>  
  
## Content  
### Structures  
+ t_class_list
    - void (*free_list_content)(void *)  
It is callback function for freeing content in list.  
    - size_t length  
It is count of list's elements.  
    - size_t content_size;  
It is size of list item content in bytes.  
    - t_list_element *p_element  
It is pointer of list root item.  
+ t_list_element  
    - void *p_content;  
It is pointer of list item content.  
    - struct s_list_element *p_last  
It is pointer of last list item.  
    - struct s_list_element *p_next  
It is pointer of next list item.  
  
### Functions  
Description of functions coming soon...
