cmake_minimum_required(VERSION 3.8)
project(fdf_test)

set(CMAKE_C_STANDARD 99)
find_package(OpenGL REQUIRED)

set(SOURCE_FILES main.c includes/fdf.h parsing.c algo.c drawmap.c)

include_directories(include libft minilibx_macos) # header directories

link_directories(libft minilibx_macos) # library directories

add_executable(fdf_test ${SOURCE_FILES})
find_package(OpenGL REQUIRED)

include_directories(${OpenGL_INCLUDE_DIR})
target_link_libraries(fdf_test -lmlx "-framework OpenGL" "-framework AppKit" ${CMAKE_SOURCE_DIR}/libft/libft.a ${CMAKE_SOURCE_DIR}/minilibx/libmlx.a)