//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-04 23:19:27
// :ddddddddddhyyddddddddddd: Modified: 2015-04-10 18:48:18
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <dlfcn.h>
#include <iostream>

#include <AGlib.hpp>
#include <AGlib_Event.hpp>

int	main(void)
{
	AGlib *		p;

	try {
		p = new AGlib;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		exit(-1);
	}

	p->init();
	while (p->isOpen())
	{
		AGlib::Event const * e;
		do
		{
			e = p->getEvent();
			if (e->key == AGlib::ESC)
				std::cout << "ESC" << std::endl;
			else if (e->key == AGlib::EMPTY)
				;
				// std::cout << "EMPTY" << std::endl;
		} while (p->popEvent()) ;
		p->draw();
	}
	return (0);
}
