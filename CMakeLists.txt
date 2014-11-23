cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(ymine CXX)
subdirs(src test)

add_custom_target(doc
doxygen ${PROJECT_SOURCE_DIR}/doc/Doxyfile
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
