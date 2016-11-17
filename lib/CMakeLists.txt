

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cotire/CMake)
include(cotire)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  message (STATUS "config C Flags CMAKE_BUILD_TYPE=Debug")
  #add_compile_options("-std=c++11")
  set(CMAKE_CXX_FLAGS "-std=c++0x -D__cplusplus=201103L -Wall -fmessage-length=0 -O0 -g3 -fPIC -MD -MP -MMD")
else()
  message (STATUS "config C Flags CMAKE_BUILD_TYPE=Release")
  #add_definitions("-std=c++11")
  set(CMAKE_CXX_FLAGS "-std=c++0x -D__cplusplus=201103L -Wall -fmessage-length=0 -fPIC -O3 -ftree-vectorize -march=native -MD -MP -MMD")
endif()


set(alinouslibsrc ${alinouslibsrc} "libmain.cpp")

# import source codes
add_subdirectory(./src_lib/)
add_subdirectory(./src_java/)

message (STATUS "source codes  ${srcsrc}")
message (STATUS "source codes  ${srcjava}")

add_library(alinous_lib SHARED ${alinouslibsrc} ${srcsrc} ${srcjava})

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  message (STATUS "config Libraries Flags Debug")
  target_link_libraries(alinous_lib pthread ${JNI_LIBRARIES})
else()
  message (STATUS "config Libraries  Flags Release")
  target_link_libraries(alinous_lib pthread ${JNI_LIBRARIES})
endif()

set_target_properties(alinous_lib PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src_java/includes.h")
cotire(alinous_lib)






