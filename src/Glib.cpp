//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:03:34
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 01:17:26
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

extern "C" {
	#include <dlfcn.h>
}

#include <iostream>
#include <Glib.hpp>
#include <Glib_Exception.hpp>

Glib::Glib(std::string lib)
{
	std::cout << "new Glib: " << lib << std::endl;

	if (!(_dl_handle = dlopen(lib.c_str(), RTLD_LAZY | RTLD_LOCAL)))
		throw Glib::Exception();
}

Glib::~Glib() {}

