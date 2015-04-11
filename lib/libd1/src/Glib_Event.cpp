//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib_Event
// /ddddy:oddddddddds:sddddd/ By Arnaud Debray - Arnaud Debray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-07 16:33:25
// :ddddddddddhyyddddddddddd: Modified: 2015-04-11 20:58:16
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Glib_Event.hpp>

Glib::Event::Event() {}
Glib::Event::Event(Glib::Keys k) { key = k; }
Glib::Event::~Event() {}

Glib::Event::Event(Glib::Event const & e)
{
	key = e.key;
}

Glib::Event const &		Glib::Event::operator=(Glib::Event const & rhs)
{
	*this = rhs;
	return (*this);
}
