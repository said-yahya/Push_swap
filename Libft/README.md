*This project has been created as part of the 42 curriculum by edpolat.*

# Libft

## Description

Libft is a static library project where commonly used standard functions are reimplemented
in the C language. The purpose of the project is to learn the basic structures of C,
memory management, pointer usage, and the fundamentals of programming logic.

## Instructions

### Compilation

To compile the library, use the following command:

```bash
make
```
As a result, a static library named libft.a is created, allowing the written functions
to be used in other projects.

### Cleaning

To remove object (.o) files:

```bash
make clean
```

To remove object files together with the libft.a file:

```bash
make fclean
```

To remove everything and rebuild the project from scratch:

```bash
make re
```

## Library Contents

libft.a contains the following functions:

### Character Check Functions
- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint

### String Functions
- ft_strlen
- ft_strlcpy
- ft_strlcat
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_strnstr
- ft_strdup
- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split
- ft_strmapi
- ft_striteri
### Memory Functions
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_memchr
- ft_memcmp
- ft_calloc

### Conversion and Output Functions
- ft_itoa
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

### Linked List Functions
- ft_lstnew
- ft_lstadd_front
- ft_lstadd_back
- ft_lstsize
- ft_lstlast
- ft_lstdelone
- ft_lstclear
- ft_lstiter
- ft_lstmap

## Usage

To use the library in another project:

```bash
cc main.c libft.a
```

or:

```bash
cc main.c -L. -lft
```

The header file must be included in the source file:

```c
#include "libft.h"
```



## Resources

### References
- man pages

### Use of Artificial Intelligence

During this project, artificial intelligence tools were used for:
- Understanding the C compilation process (compile, assemble, link)
- Learning the structure of a Makefile
- Explaining the behavior of standard C functions

All function implementations and final decisions were made by the project owner.

---

## Author

edpolat
