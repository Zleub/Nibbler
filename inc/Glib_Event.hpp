//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib_Event
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 18:00:19
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 18:02:26
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
	Event(Event const &);
	~Event(void);

	int		content;
	Event &	operator=(Event const &);
private:
};

#endif
