//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-04 23:19:27
// :ddddddddddhyyddddddddddd: Modified: 2015-04-12 20:39:35
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <dlfcn.h>
#include <iostream>

#include <Glib.hpp>
#include <IGlib_Event.hpp>
#include <IGlib_Exception.hpp>

// Glib::
extern "C" {
	#include <dlfcn.h>
}


int	main(void)
{
	// std::cout << "default new IGlib with lib/libd1/libd1.so" << std::endl;

	void * _dl_handle;
	if (!(_dl_handle = dlopen("lib/libd1/libd1.so", RTLD_LAZY | RTLD_LOCAL)))
		std::cout << "caca" << std::endl;
		// throw IGlib::Exception();

	IGlib * (* _create_t)(void) = (create_t *)(dlsym(_dl_handle, "create"));
	// void (* _destroy_t)(IGlib *) = (destroy_t *)(dlsym(_dl_handle, "destroy"));
	// assign();
	// pushEvent(new IGlib::Event(IGlib::ESC));
	IGlib *		p;

	p = _create_t();

	// try {
	// 	p = new Glib;
	// } catch (std::exception & e) {
	// 	std::cerr << e.what() << std::endl;
	// 	exit(-1);
	// }

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
