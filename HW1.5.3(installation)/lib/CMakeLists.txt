add_library(hello_static STATIC hello_lib.cxx)
add_library(hello_dynamic SHARED hello_lib.cxx)


# INSTALLATION

# DOESN'T WORK
#set(CMAKE_INSTALL_RPATH "${PROJECT_SOURCE_DIR}/install/bin/lib")
# set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

install(
	TARGETS
	hello_dynamic
	
	DESTINATION
	lib
	)
	
#install(
#	FILES
#	hello_lib.hxx
#	DESTINATION
#	lib
#	)
	

