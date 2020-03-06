cmake_minimum_required(VERSION 3.15)
project(fdf C)
include_directories(minilibx)

set(CMAKE_C_STANDARD 99)

add_executable(fdf main.c read.c errors.c fdf.h libft/libft.h libft/ft_strsplit.c libft/ft_atoi.c
        libft/ft_putnbr.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_clear.c libft/get_next_line.c
        libft/ft_cleararr.c libft/ft_countwords.c libft/ft_getword.c libft/ft_memalloc.c libft/ft_strcat.c
        libft/ft_strchr.c libft/ft_strclr.c libft/ft_strdel.c libft/ft_strcpy.c libft/ft_strjoin libft/ft_strlen.c
        libft/ft_strnew.c libft/ft_strsub.c libft/ft_bzero.c clears.c calculate.c drawmap.c checks.c)

#set(CMAKE_EXE_LINKER_FLAGS "../libft/libft.a ../minilibx/libmlx_Linux.a -lX11 -lXext")
set(CMAKE_EXE_LINKER_FLAGS "-I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit")