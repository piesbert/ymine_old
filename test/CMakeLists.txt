include_directories(${ymine_SOURCE_DIR}/src)
include_directories(${ymine_SOURCE_DIR}/test)

exec_program(sdl2-config ARGS --cflags OUTPUT_VARIABLE SDL_CXX_FLAGS)
exec_program(sdl2-config ARGS --libs OUTPUT_VARIABLE SDL_LINKER_FLAGS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SDL_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SDL_LINKER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread -lGL")

file(GLOB_RECURSE SRC_FILES_CORE ${ymine_SOURCE_DIR}/src/core/*.cpp)
file(GLOB_RECURSE SRC_FILES_SERVICE ${ymine_SOURCE_DIR}/src/service/*.cpp)
file(GLOB_RECURSE SRC_FILES_LOG ${ymine_SOURCE_DIR}/src/log/*.cpp)
file(GLOB_RECURSE SRC_FILES_OPENGL ${ymine_SOURCE_DIR}/src/opengl/*.cpp)
file(GLOB_RECURSE SRC_FILES_INPUT ${ymine_SOURCE_DIR}/src/input/*.cpp)

file(GLOB_RECURSE SRC_FILES ${ymine_SOURCE_DIR}/test/*.cpp)

add_executable(ymine_test ${SRC_FILES}
	${SRC_FILES_CORE}
	${SRC_FILES_SERVICE}
	${SRC_FILES_LOG}
	${SRC_FILES_OPENGL}
	${SRC_FILES_INPUT})
target_link_libraries(ymine_test "${ymine_SOURCE_DIR}/lib/libgmock.a")