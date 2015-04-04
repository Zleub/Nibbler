//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib_Exception
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:16:08
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 01:15:30
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GLIB_EXCEPTION_HPP
#define GLIB_EXCEPTION_HPP

#include <exception>
#include <Glib.hpp>

class Glib::Exception : public std::exception {
public:
	Exception(void);
	Exception(Exception const &);
	~Exception(void) throw();

	Exception &	operator=(Exception const &);

	virtual char const * what() const throw();
};

#endif
