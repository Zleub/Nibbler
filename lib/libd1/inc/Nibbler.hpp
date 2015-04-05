//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Nibbler
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 04:59:08
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 07:42:13
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef NIBBLER_HPP
#define NIBBLER_HPP

#include <SFML/Graphics.hpp>
#include <AGlib.hpp>

class Nibbler : public AGlib {
private:
public:
	Nibbler(Nibbler const &);
	Nibbler(void);
	virtual ~Nibbler(void);

	virtual AGlib &	operator=(AGlib const &);

	virtual void init(void);
};

#endif
