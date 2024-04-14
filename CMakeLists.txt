cmake_minimum_required(VERSION 3.10)
project(LookDraw)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# Directories
set(SRC_DIR src)
set(DEPS_DIR third-party)
set(MAIN_INCLUDE_DIR ${DEPS_DIR}/include)
set(MAIN_LIB_DIR ${DEPS_DIR}/lib)

# Libraries
set(LD_LIBS glfw3 GL GLU)
link_directories(${MAIN_LIB_DIR})

# Targets
set(EXECUTABLE lookdraw)
file(GLOB SOURCES ${SRC_DIR}/*.cpp ${DEPS_DIR}/glad/src/glad.c)

# Rules
add_executable(${EXECUTABLE} ${SOURCES})
target_link_libraries(${EXECUTABLE} ${LD_LIBS})
target_include_directories(${EXECUTABLE} PRIVATE ${MAIN_INCLUDE_DIR})

# Custom command to copy assets directory to build directory
set(ASSETS_SOURCE_DIR ${CMAKE_SOURCE_DIR}/assets)
set(ASSETS_DEST_DIR ${CMAKE_BINARY_DIR}/assets)
add_custom_command(
    TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSETS_SOURCE_DIR} ${ASSETS_DEST_DIR}
)