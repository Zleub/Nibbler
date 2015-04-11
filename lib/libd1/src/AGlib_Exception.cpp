//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:AGlib_Exception
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:21:55
// :ddddddddddhyyddddddddddd: Modified: 2015-04-10 18:12:29
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

extern "C" {
	#include <dlfcn.h>
}

#include <AGlib.hpp>
#include <AGlib_Exception.hpp>

AGlib::Exception::Exception() {}
AGlib::Exception::~Exception() throw() {}

const char * AGlib::Exception::what() const throw() {
	return "AGlib::Exception";
}
