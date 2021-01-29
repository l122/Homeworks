
find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS}) #------ not necessary

#DYNAMIC linking
add_executable(homework2_dynamic main.cpp)
target_compile_features(homework2_dynamic PUBLIC cxx_std_17)
target_link_libraries(homework2_dynamic SDL2)  #------ works
#target_link_libraries(homework2_dynamic ${SDL2_LIBRARIES}) #------- works


#STATIC linkin
add_executable(homework2_static main.cpp)
target_compile_features(homework2_static PUBLIC cxx_std_17)
target_link_libraries(homework2_static SDL2::SDL2-static)




#CPACK

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# does the application run

add_test(NAME Main_Runs COMMAND main.cpp)
