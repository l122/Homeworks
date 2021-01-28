	#include <iostream>
#include "hello_lib.hxx"

int main(int argc, char *argv[])
{
	//std::cout << hello_world() << "\n"; // returns 0 to video0
	std::cout << hello_world() << "\n" <<std::flush; // returns 1 to video0
	//std::cout << hello_world() << std::endl; //returns 1 to video0

	return std::cout.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}
