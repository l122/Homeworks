#include <iostream>
#include "hello_lib.hxx"

int main(int argc, char *argv[])
{
	return (std::cout << hello_world()).good() ? 0: 1;
}
