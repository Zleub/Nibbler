//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-12 18:29:42
// :ddddddddddhyyddddddddddd: Modified: 2015-04-12 19:14:02
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GLIB_HPP
#define GLIB_HPP

#include <IGlib.hpp>

class Glib : public IGlib {
public:
	Glib(void);
	Glib(Glib const &);
	~Glib(void);

	virtual IGlib &					operator=(IGlib const &rhs) ;

	virtual void					init(void) ;
	virtual void					draw(void) ;

	virtual bool					isOpen(void) ;

	virtual bool					popEvent(void) ;
	virtual IGlib::Event const *	getEvent(void) ;
	virtual void					pushEvent(IGlib::Event *) ;
private:
	virtual void					checkError(void) const ;
	virtual void					assign(void) ;
};

#endif
