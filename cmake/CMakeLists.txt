cmake_minimum_required(VERSION 3.19)

project(SimpleProject
  LANGUAGES CXX # Fortran C ASM
    #CUDA # 3.8
    #OBJC OBJCXX  # 3.16
    #ISPC # 3.18

  DESCRIPTION "A simple project using CMake" # 3.9
  VERSION 1.0.0 # 3.12
  HOMEPAGE_URL  https://convergecfd.com # 3.12
  )

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake")

include(CMake/SimpleProjectMacros.cmake)

set_env(DUMMY 0)

set(MYLIB_sources
  src/mylib.cpp
  )
set(MYLIB_include_public_dirs
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )
set(MYLIB_include_private_dirs
  ${CMAKE_CURRENT_SOURCE_DIR}/src/include
  )

add_library(mylib ${MYLIB_sources})
target_include_directories(mylib
  PUBLIC
    ${MYLIB_include_public_dirs})

target_include_directories(mylib
  PRIVATE
    ${MYLIB_include_private_dirs}
)

set(MYEXEC_sources
  src/main.cpp
  )
set(MYEXEC_include_dirs
  #${CMAKE_CURRENT_SOURCE_DIR}
  )
set(MYEXEC_libraries
  mylib
  )

add_executable(myexec ${MYEXEC_sources})
target_link_libraries(myexec ${MYEXEC_libraries})
