//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Nibbler
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 04:59:44
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 11:07:26
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
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
}

void		Nibbler::update(void)
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


bool		Nibbler::isOpen(void)
{
	return _window->isOpen();
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
