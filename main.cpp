//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-04 23:19:27
// :ddddddddddhyyddddddddddd: Modified: 2015-04-17 00:06:54
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>

#include <IGlib_Event.hpp>
#include <IGlib_Exception.hpp>

extern "C" {
	#include <dlfcn.h>
}

IGlib::Exception::Exception() {}
IGlib::Exception::~Exception() throw() {}

const char * IGlib::Exception::what() const throw() {
	return "IGlib::Exception";
}

int	main(void)
{
	Game game;


	void * _dl_handle;
	// if (!(_dl_handle = dlopen("lib/libd1/libd1.so", RTLD_LAZY | RTLD_LOCAL)))
	if (!(_dl_handle = dlopen("lib/libd2/libd2.so", RTLD_LAZY | RTLD_LOCAL)))
		throw IGlib::Exception();

	IGlib * (* _create_t)(void) = (create_t *)(dlsym(_dl_handle, "create"));

	IGlib * p;

	p = _create_t();

	p->init(&game);
	while (p->isOpen())
	{
		IGlib::Event const * e;

		p->update();
		do
		{
			e = p->getEvent();

			// KEYBOARD INPUT

			if (e->key == IGlib::ESC)
				std::cout << "ESC" << std::endl;
			if (e->key == IGlib::UP)
				std::cout << "UP" << std::endl;
			if (e->key == IGlib::DOWN)
				std::cout << "DOWN" << std::endl;
			if (e->key == IGlib::LEFT)
				std::cout << "LEFT" << std::endl;
			if (e->key == IGlib::RIGHT)
				std::cout << "RIGHT" << std::endl;
			else if (e->key == IGlib::EMPTY)
				; //std::cout << "EMPTY" << std::endl;


		} while (p->popEvent()) ;
		p->draw();
	}
	return (0);
}
