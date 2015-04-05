//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Nibbler
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 04:59:44
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 07:36:28
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>
#include <Nibbler.hpp>

Nibbler::Nibbler() {}
Nibbler::~Nibbler() {}

AGlib &	Nibbler::operator=(AGlib const &)
{
	return *this;
}

void		Nibbler::init(void)
{
	std::cout << "Nibbler init 1" << std::endl;
}

extern "C"
{
	AGlib * create()
	{
		return new Nibbler;
	}

	void destroy(AGlib * p)
	{
		delete p;
	}
}
