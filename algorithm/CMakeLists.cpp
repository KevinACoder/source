cmake_minimum_required (VERSION 2.6)
project (Algorithm)

#the version number
set (Algorithm_VERSION_MAJOR)
set (Algorithm_VERSION_MINOR)

#config the header file to pass cmake setting to
# source code
configure_file (
	"$(PROJECT_SOURCE_DIR)/AlgorithmConfig.h.in"
	"$(PROJECT_BINARY_DIR)/AlgorithmConfig.h"
	)

#add the binary tree to the search path for includes files
# so that we can find config.h
include_directories("$(PROJECT_BINARY_DIR)")

add_executable(Algorithm run.cpp)