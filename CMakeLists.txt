cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

project(gdbackup) # change the name here

add_subdirectory(libs/minhook)
add_subdirectory(libs/cocos-headers)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(IS_MACOS On)
endif()

# this is so stupid
set(CMAKE_SIZEOF_VOID_P 4)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL Clang AND NOT ${IS_MACOS})
    # ensure 32 bit on clang
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -target i386-pc-windows-msvc")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -target i386-pc-windows-msvc")
    add_definitions("--target=i386-pc-windows-msvc")
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    libs/minhook/include
    libs/gd.h/include
    libs/gd.h/
)



target_link_libraries(${PROJECT_NAME} minhook cocos2d)