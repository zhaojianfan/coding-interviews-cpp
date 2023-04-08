cmake_minimum_required(VERSION 3.24)
project(coding-interviews-cpp)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(
        src/chapter-2
        CHAPTER_2
)

aux_source_directory(
        src/chapter-3
        CHAPTER_3
)

aux_source_directory(
        src/data-structure
        DS
)

include_directories(src/include)

add_executable(coding-interviews-cpp src/main.cpp ${CHAPTER_2} ${CHAPTER_3} ${DS})
