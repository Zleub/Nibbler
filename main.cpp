//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-04 23:19:27
// :ddddddddddhyyddddddddddd: Modified: 2015-04-11 23:10:48
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <dlfcn.h>
#include <iostream>

#include <Glib.hpp>
#include <Glib_Event.hpp>

// Glib::

int	main(void)
{
	Glib *		p;

	try {
		p = new Glib;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		exit(-1);
	}

	p->init();
	while (p->isOpen())
	{
		Glib::Event const * e;
		do
		{
			e = p->getEvent();
			if (e->key == Glib::ESC)
				std::cout << "ESC" << std::endl;
			else if (e->key == Glib::EMPTY)
				;
				// std::cout << "EMPTY" << std::endl;
		} while (p->popEvent()) ;
		p->draw();
	}
	return (0);
}
