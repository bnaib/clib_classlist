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
Makefile use gcc. If you havn't it, download and install gcc.  
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
Description of structures and functions coming soon...
