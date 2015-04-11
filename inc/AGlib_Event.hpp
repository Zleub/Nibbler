//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:AGlib_Event
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 18:00:19
// :ddddddddddhyyddddddddddd: Modified: 2015-04-10 15:22:11
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef AGLIB_EVENT_HPP
#define AGLIB_EVENT_HPP

class AGlib;

class AGlib::Event {
public:
	Event(void);
	Event(AGlib::Keys);
	Event(Event const &);
	~Event(void);

	AGlib::Keys		key;
	Event const &	operator=(Event const &);
private:
};

#endif
