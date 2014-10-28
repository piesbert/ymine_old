include_directories(${ymine_SOURCE_DIR}/src)

exec_program(sdl2-config ARGS --cflags OUTPUT_VARIABLE SDL_CXX_FLAGS)
exec_program(sdl2-config ARGS --libs OUTPUT_VARIABLE SDL_LINKER_FLAGS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SDL_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SDL_LINKER_FLAGS}")

file(GLOB_RECURSE SRC_FILES ${ymine_SOURCE_DIR}/src/*.cpp)
add_executable(ymine ${SRC_FILES})
