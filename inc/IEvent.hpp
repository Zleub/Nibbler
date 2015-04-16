//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:IGlib_Event
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 18:00:19
// :ddddddddddhyyddddddddddd: Modified: 2015-04-16 19:24:38
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef IGLIB_EVENT_HPP
#define IGLIB_EVENT_HPP

#include <IGlib.hpp>

class IGlib::Event {
public:
	Event(void) {} ;
	Event(IGlib::Keys) {} ;
	Event(Event const &) {} ;
	virtual ~Event(void) {} ;

	virtual Event const &	operator=(Event const & rhs) { _key = rhs.getKey(); return *this; };
	virtual IGlib::Keys		getKey(void) const { return _key; }
private:
	IGlib::Keys		_key;
};

#endif
