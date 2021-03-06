cmake_minimum_required(VERSION 3.18.4)

project(HW1 VERSION 5.3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)

# STATIC files
add_executable(hello_cout_static hello.cxx)
target_include_directories(hello_cout_static PUBLIC lib)
target_link_directories(hello_cout_static PRIVATE lib)
target_link_libraries(hello_cout_static hello_static)


# DYNAMIC files
add_executable(hello_cout_dynamic hello.cxx)
target_include_directories(hello_cout_dynamic PUBLIC lib)
target_link_directories(hello_cout_dynamic PRIVATE lib)
target_link_libraries(hello_cout_dynamic hello_dynamic)


#TESTS
enable_testing()

# does the application run
add_test(NAME Static_Runs COMMAND hello_cout_static)
add_test(NAME Dynamic_Runs COMMAND hello_cout_dynamic)

# INSTALLATION
install(
	TARGETS
	hello_cout_static
	hello_cout_dynamic
	DESTINATION 
	bin
	)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
include(CPack)

