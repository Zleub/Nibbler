//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:05:12
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 11:10:59
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GLIB_HPP
#define GLIB_HPP

#include <iostream>
#include <AGlib.hpp>

class Glib {
private:
	Glib(Glib const &);
	Glib &	operator=(Glib const &);

	void *		_dl_handle;
	AGlib *		_gl_handle;
	create_t *	_create_t;
	destroy_t *	_destroy_t;
public:
	class Exception;

	Glib(void);
	Glib(std::string);
	~Glib(void);

	void		init(void) const ;
	void		update(void) ;
	bool		isOpen(void) ;
};

#endif
