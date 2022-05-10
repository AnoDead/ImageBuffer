cmake_minimum_required(VERSION 3.22)
project(ImageBuffer)

add_compile_options(-O3)
add_compile_options(-Wall)


set(CMAKE_CXX_STANDARD 17)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    src/colors.h
    src/colors.cpp
    src/imagebuffer.h
    src/imagebuffer.cpp
    src/image_files.h
    src/image_files.cpp
)