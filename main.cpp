//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-04 23:19:27
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 02:55:28
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <dlfcn.h>
#include <iostream>

#include <Glib.hpp>

int	main(void)
{
	try {
		Glib test;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		exit(-1);
	}

	// void(*shit)(void) = (void(*)(void))dlsym(dl_handle, "print_shit");
	// if (!shit)
	// 	dlerror_wrapper();

	std::cout << "Hello World" << std::endl;

	// shit();

	// new game
	// update game
	// draw game

	return (0);
}
