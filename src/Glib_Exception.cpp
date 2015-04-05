//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib_Exception
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:21:55
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 02:50:18
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

extern "C" {
	#include <dlfcn.h>
}

#include <Glib.hpp>
#include <Glib_Exception.hpp>

Glib::Exception::Exception() {}
Glib::Exception::~Exception() throw() {}

const char * Glib::Exception::what() const throw() {
	return dlerror();
}
