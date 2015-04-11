//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib_Event
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 18:00:19
// :ddddddddddhyyddddddddddd: Modified: 2015-04-11 21:00:48
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GLIB_EVENT_HPP
#define GLIB_EVENT_HPP

#include <Glib.hpp>

class Glib::Event {
public:
	Event(void);
	Event(Glib::Keys);
	Event(Event const &);
	~Event(void);

	Glib::Keys		key;
	Event const &	operator=(Event const &);
private:
};

#endif
