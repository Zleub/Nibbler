//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib_Event
// /ddddy:oddddddddds:sddddd/ By Arnaud Debray - Arnaud Debray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-07 16:33:25
// :ddddddddddhyyddddddddddd: Modified: 2015-04-07 19:21:14
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Glib_Event.hpp>

Glib::Event::Event() {}
Glib::Event::~Event() {}

Glib::Event::Event(Glib::Event const & e)
{
	content = e.content;
}

