//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:LOVE
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 16:42:16
// :ddddddddddhyyddddddddddd: Modified: 2015-04-06 17:36:27
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>
#include <LOVE.hpp>

LOVE::LOVE() {}
LOVE::~LOVE() {}

AGlib &	LOVE::operator=(AGlib const &)
{
	return *this;
}

void		LOVE::init(void)
{
	std::cout << "LOVE init 1" << std::endl;

}

void		LOVE::update(void)
{
	// sf::Event event;
	// while (_window->pollEvent(event))
	// {
	// 	if (event.type == sf::Event::Closed)
	// 		_window->close();
	// }
	// _window->clear();
	// // _window->draw(sprite);
	// _window->display();
}


bool		LOVE::isOpen(void)
{
	// return _window->isOpen();
	return true;
}

extern "C"
{
	AGlib * create()
	{
		return new LOVE;
	}

	void destroy(AGlib * p)
	{
		delete p;
	}
}
