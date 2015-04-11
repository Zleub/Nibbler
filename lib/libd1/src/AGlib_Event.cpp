//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:AGlib_Event
// /ddddy:oddddddddds:sddddd/ By Arnaud Debray - Arnaud Debray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-07 16:33:25
// :ddddddddddhyyddddddddddd: Modified: 2015-04-10 18:09:54
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <AGlib.hpp>
#include <AGlib_Event.hpp>

AGlib::Event::Event() {}
AGlib::Event::Event(AGlib::Keys k) { key = k; }
AGlib::Event::~Event() {}

AGlib::Event::Event(AGlib::Event const & e)
{
	key = e.key;
}

AGlib::Event const &		AGlib::Event::operator=(AGlib::Event const & rhs)
{
	*this = rhs;
	return (*this);
}
