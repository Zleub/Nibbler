//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:SFML
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:06:16
// :ddddddddddhyyddddddddddd: Modified: 2015-04-16 03:51:56
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>

#include <SFML.hpp>
#include <IGlib_Exception.hpp>
#include <IGlib_Event.hpp>

extern "C" {
	#include <dlfcn.h>
}

SFML::SFML() : _scale(25) {}

SFML::~SFML() {}

IGlib &		SFML::operator=(IGlib const &)
{
	return *this;
}

void		SFML::pushEvent(IGlib::Event * k) { _stack.push(k); }

void		SFML::init(Game * game)
{
	std::cout << "SFML init 1" << std::endl;

	_window = new sf::RenderWindow(
		sf::VideoMode(game->width * this->_scale * 2, game->height * this->_scale * 2),
		"SFML window"
		);
	_game = game;
}

void		SFML::update(void)
{
	sf::Event event;

	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				pushEvent(new IGlib::Event(IGlib::ESC));
			if (event.key.code == sf::Keyboard::Up)
				pushEvent(new IGlib::Event(IGlib::UP));
			if (event.key.code == sf::Keyboard::Down)
				pushEvent(new IGlib::Event(IGlib::DOWN));
			if (event.key.code == sf::Keyboard::Left)
				pushEvent(new IGlib::Event(IGlib::LEFT));
			if (event.key.code == sf::Keyboard::Right)
				pushEvent(new IGlib::Event(IGlib::RIGHT));
		}
	}
}

void		SFML::mdraw(int index, int x, int y)
{
	sf::ConvexShape rect;
	rect.setPointCount(4);
	rect.setPoint(0, sf::Vector2f(0, 0));
	rect.setPoint(1, sf::Vector2f(_scale, _scale / 2));
	rect.setPoint(2, sf::Vector2f(0, _scale));
	rect.setPoint(3, sf::Vector2f(-_scale, _scale / 2));
	rect.setPosition(x, y);

	if (_game->map[index] == Game::SNAKE_HEAD)
		rect.setFillColor(sf::Color::Green);

	_window->draw(rect);
}

void		SFML::draw(void)
{
	_window->clear();

	// sf::Vector2u _v = _window->getSize();

	int middle = _game->width * this->_scale * 2 / 2;

	int i;
	int j;

	i = middle;
	j = 0;

	int x;
	int y = 0;

	while (y < _game->height)
	{
		x = 0;
		while (x < _game->width)
		{
			mdraw(x + y * _game->width, i, j);
			x += 1;
			i += _scale + 1;
			j += _scale + 1;
		}
		y += 1;
		i = middle - ((_scale * y) + y);
		j = ((_scale * y) + y);
	}

	_window->display();
}

bool		SFML::isOpen(void)
{
	return _window->isOpen();
}

IGlib::Event const *		SFML::getEvent(void)
{
	if (!_stack.empty())
		return _stack.top();
	else
		return new IGlib::Event(IGlib::EMPTY);
}

bool					SFML::popEvent(void)
{
	if (_stack.empty())
		return false;
	else
		_stack.pop();
	return true;
}

extern "C"
{
	IGlib * create()
	{
		return new SFML();
	}

	void destroy(IGlib * p)
	{
		delete p;
	}
}
