#include <iostream>

extern "C" {
	void	print_shit(void)
	{
		std::cout << "caca" << std::endl;
	}
}
