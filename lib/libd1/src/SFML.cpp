//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:SFML
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:06:16
// :ddddddddddhyyddddddddddd: Modified: 2015-04-18 15:22:50
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>

#include <SFML.hpp>
#include <IGlib_Exception.hpp>
#include <IGlib_Event.hpp>

const int &		Game::operator[](std::size_t index) const { return _map_overtime[index]; }
int				Game::getWidth(void) const { return _width; }
int				Game::getHeight(void) const { return _height; }

/* * * * * * */

SFML::SFML() : _scale(10) {}

SFML::~SFML() {}

IGlib &		SFML::operator=(IGlib const &)
{
	return *this;
}

void		SFML::pushEvent(IGlib::Event * k) { _stack.push(k); }

void		SFML::playMusic(void)
{
	// GAME MUSIC

	// sf::Music music;
	// if (!music.openFromFile("music/got.ogg"))
	// std::cout << "Nibbler (SFML): Could not load game music." << std::endl;
	// music.SetVolume(32);
	// music.play();

	// // la musique s'arrete a la sortie de la fonction

	// // attends la fin de la lecture,
	// // puis relance un autre thread musical
	// while (music.getStatus() == 2)
	// 	;
	// music.stop();
	// std::thread (playMusic).detach();
}

void		SFML::init(Game * game)
{
	_w = game->getWidth();
	_h = game->getHeight();

	if (_w < _h)
		_w = _h;
	else if (_w > _h)
		_h = _w;

	std::cout << "SFML init 1" << std::endl;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	_window = new sf::RenderWindow(
		sf::VideoMode(_w * this->_scale * 2, _h * this->_scale * 2),
		"SFML window",
		sf::Style::Default,
		settings
		);
	_game = game;

	// GAME MUSIC PLAYED IN A SPECIFIC THREAD
	std::thread (this->playMusic).detach();
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

void		SFML::drawFloor(int x, int y) const
{
	sf::ConvexShape rect;

	rect.setPointCount(4);
	rect.setPoint(0, sf::Vector2f(0, 0));
	rect.setPoint(1, sf::Vector2f(_scale, _scale / 2));
	rect.setPoint(2, sf::Vector2f(0, _scale));
	rect.setPoint(3, sf::Vector2f(-_scale, _scale / 2));
	rect.setPosition(x, y);
	rect.setOutlineColor(sf::Color(150, 150, 150));
	rect.setOutlineThickness(0.5);
	_window->draw(rect);
}

void		SFML::drawSnake(int part, int x, int y) const
{
	sf::ConvexShape quad1;
	quad1.setPointCount(4);
	quad1.setPoint(0, sf::Vector2f(-_scale, 0));
	quad1.setPoint(1, sf::Vector2f(0, _scale / 2));
	quad1.setPoint(2, sf::Vector2f(0, _scale));
	quad1.setPoint(3, sf::Vector2f(-_scale, _scale / 2));
	quad1.setPosition(x, y);
	if (part == 1) {
		quad1.setFillColor(sf::Color(204, 102, 0));
		quad1.setOutlineColor(sf::Color::Black);
		quad1.setOutlineThickness(0.5);
	} else if (part == 0) {
		quad1.setFillColor(sf::Color(76, 153, 0));
		quad1.setOutlineColor(sf::Color::Black);
		quad1.setOutlineThickness(0.5);
	}
	_window->draw(quad1);

	sf::ConvexShape quad2;
	quad2.setPointCount(4);
	quad2.setPoint(0, sf::Vector2f(_scale, 0));
	quad2.setPoint(1, sf::Vector2f(_scale, _scale / 2));
	quad2.setPoint(2, sf::Vector2f(0, _scale));
	quad2.setPoint(3, sf::Vector2f(0, _scale / 2));
	quad2.setPosition(x, y);
	if (part == 1) {
		quad2.setFillColor(sf::Color(153, 76, 0));
		quad2.setOutlineColor(sf::Color::Black);
		quad2.setOutlineThickness(0.5);
	} else if (part == 0) {
		quad2.setOutlineThickness(0.5);
		quad2.setFillColor(sf::Color(76, 153, 0));
		quad2.setOutlineColor(sf::Color::Black);
	}
	_window->draw(quad2);

	sf::ConvexShape quad3;
	quad3.setPointCount(4);
	quad3.setPoint(0, sf::Vector2f(0, 0));
	quad3.setPoint(1, sf::Vector2f(_scale, _scale / 2));
	quad3.setPoint(2, sf::Vector2f(0, _scale));
	quad3.setPoint(3, sf::Vector2f(-_scale, _scale / 2));
	quad3.setPosition(x, y - _scale / 2);
	if (part == 1) {
		quad3.setFillColor(sf::Color(255, 128, 0));
		quad3.setOutlineColor(sf::Color::Black);
		quad3.setOutlineThickness(0.5);
	} else if (part == 0) {
		quad3.setOutlineThickness(0.5);
		quad3.setFillColor(sf::Color(102, 204, 0));
		quad3.setOutlineColor(sf::Color::Black);
	}
	_window->draw(quad3);
}

void		SFML::drawSnakeFood(int x, int y) const
{
	drawFloor(x, y);

	// THIS IS BULLSHIT NOT RESPONSIVE TO SCALE
	//
		sf::CircleShape circle(50);
		circle.setRadius(8);
		circle.setPosition(x - (_scale / 2) + 4, y + 4);
		circle.setFillColor(sf::Color(150, 0, 0));
		_window->draw(circle);
		sf::CircleShape circle2(50);
		circle2.setRadius(7);
		circle2.setPosition(x - (_scale / 2) + 5, y + 5);
		circle2.setFillColor(sf::Color(204, 0, 0));
		_window->draw(circle2);
		sf::CircleShape circle3(50);
		circle3.setRadius(2);
		circle3.setPosition(x - (_scale / 2) + 13, y + 6);
		circle3.setFillColor(sf::Color(255, 100, 100));
		_window->draw(circle3);

		sf::ConvexShape leaf;
		leaf.setPointCount(3);
		int _x = x - 20;
		int _y = y - 7;
		leaf.setOutlineColor(sf::Color(0, 77, 0));
		leaf.setOutlineThickness(0.5);
		leaf.setPoint(0, sf::Vector2f(_x + 19, _y + 13));
		leaf.setPoint(1, sf::Vector2f(_x + 15, _y + 10));
		leaf.setPoint(2, sf::Vector2f(_x + 10, _y + 10));
		leaf.setFillColor(sf::Color(102, 204, 0));
		_window->draw(leaf);
		leaf.setPoint(0, sf::Vector2f(_x + 20, _y + 13));
		leaf.setPoint(1, sf::Vector2f(_x + 25, _y + 10));
		leaf.setPoint(2, sf::Vector2f(_x + 22, _y + 7));
		leaf.setFillColor(sf::Color(90, 190, 0));
		_window->draw(leaf);
	//
	// END

}

void		SFML::mdraw(int index, int x, int y) const
{
	if ((*_game)[index] == 11)
		drawSnake(0, x, y);
	else if ((*_game)[index] == 0)
		drawFloor(x, y);
	else if ((*_game)[index] > 11)
		drawSnake(1, x, y);
	else if ((*_game)[index] < 11)
		drawSnakeFood(x, y);
}

void		SFML::draw(void)
{
	_window->clear();

	int middle = _game->getWidth() * this->_scale * 2 / 2;

	int i;
	int j;

	i = middle;
	j = 0;

	int x;
	int y = 0;

	while (y < _game->getHeight())
	{
		x = 0;
		while (x < _game->getWidth())
		{
			mdraw(x + y * _game->getWidth(), i, j);
			x += 1;
			i += _scale;
			j += _scale;
		}
		y += 1;
		i = middle - ((_scale * y) );
		j = ((_scale * y) );
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
