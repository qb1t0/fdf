cmake_minimum_required(VERSION 3.8)
project(fdf_test)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c includes/fdf.h parsing.c)
add_executable(fdf_test ${SOURCE_FILES})
target_link_libraries(fdf_test -lmlx -framework OpenGL -framework AppKit ${CMAKE_SOURCE_DIR}/libft/libft.a ${CMAKE_SOURCE_DIR}/minilibx/libmlx.a)