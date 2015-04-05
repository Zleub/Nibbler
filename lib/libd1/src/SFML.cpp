//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:SFML
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 04:59:44
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 17:53:11
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>
#include <SFML.hpp>

SFML::SFML() {}
SFML::~SFML() {}

AGlib &	SFML::operator=(AGlib const &)
{
	return *this;
}

void		SFML::init(void)
{
	std::cout << "SFML init 1" << std::endl;
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
}

void		SFML::update(void)
{
	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();
	}
	_window->clear();
	// _window->draw(sprite);
	_window->display();
}


bool		SFML::isOpen(void)
{
	return _window->isOpen();
}

extern "C"
{
	AGlib * create()
	{
		return new SFML;
	}

	void destroy(AGlib * p)
	{
		delete p;
	}
}
