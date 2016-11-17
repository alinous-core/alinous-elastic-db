#project(alinous)

cmake_minimum_required (VERSION 2.6)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cotire/CMake)
include(cotire)


message (STATUS "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")

find_package(JNI REQUIRED)
if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()

include_directories(${JNI_INCLUDE_DIRS})



include_directories(lib/src_lib/)
include_directories(lib/src_java/)


add_subdirectory(lib)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "-std=c++0x -D__cplusplus=201103L -fmessage-length=0 -Wall -O0 -g3 -MMD -MP -MF -pipe")
  
else()
  set(CMAKE_CXX_FLAGS "-std=c++0x -D__cplusplus=201103L -Wall -fmessage-length=0 -O3 -march=native -MMD -MP -MF -pipe")
endif()

set(alinoussrc main/main.cpp)

add_executable(alinous ${alinoussrc})
target_link_libraries(alinous  alinous_lib)

install(TARGETS alinous RUNTIME DESTINATION bin)
