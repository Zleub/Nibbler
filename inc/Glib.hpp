//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:05:12
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 01:17:32
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GLIB_HPP
#define GLIB_HPP

#include <iostream>

class Glib {
private:
	Glib(Glib const &);
	Glib &	operator=(Glib const &);
	Glib(void);

	void *		_dl_handle;
public:
	class Exception;

	Glib(std::string);
	~Glib(void);
};

#endif
