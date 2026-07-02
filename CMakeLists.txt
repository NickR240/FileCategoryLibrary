cmake_minimum_required(VERSION 3.20)

project(FileCategoryLibrary LANGUAGES CXX)

add_library(FileCategoryLibrary
    src/FileCategory.cpp
)

target_include_directories(FileCategoryLibrary
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(FileCategoryLibrary
    PUBLIC
        cxx_std_17
)
