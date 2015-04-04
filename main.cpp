//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-04 23:19:27
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 01:01:34
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <dlfcn.h>
#include <iostream>

#include <Glib.hpp>

void	dlerror_wrapper(void)
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(-1);
}

int	main(void)
{
	try {
		Glib test("lib/libd1/libd1");
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		exit(-1);
	}


	void *dl_handle = dlopen("lib/libd1/libd1.so", RTLD_LAZY | RTLD_LOCAL);
	void(*shit)(void) = (void(*)(void))dlsym(dl_handle, "print_shit");
	if (!shit)
		dlerror_wrapper();

	std::cout << "Hello World" << std::endl;

	shit();

	// new game
	// update game
	// draw game

	return (0);
}
