//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-04 23:19:27
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 17:42:00
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
	Glib *		p;

	try {
		p = new Glib("lib/libd2/libd2.so");
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		exit(-1);
	}

	p->init();
	while (p->isOpen())
		p->update();
	return (0);
}
