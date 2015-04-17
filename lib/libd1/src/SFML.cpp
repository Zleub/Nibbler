//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:SFML
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:06:16
// :ddddddddddhyyddddddddddd: Modified: 2015-04-16 19:45:23
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>

#include <SFML.hpp>
#include <IGlib_Exception.hpp>
#include <IGlib_Event.hpp>

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

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	_window = new sf::RenderWindow(
		sf::VideoMode(game->width * this->_scale * 2, game->height * this->_scale * 2),
		"SFML window",
		sf::Style::Default,
		settings
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

void		SFML::drawSnakeHead(int x, int y) const
{
	sf::ConvexShape quad1;
	quad1.setPointCount(4);
	quad1.setPoint(0, sf::Vector2f(-_scale, 0));
	quad1.setPoint(1, sf::Vector2f(0, _scale / 2));
	quad1.setPoint(2, sf::Vector2f(0, _scale));
	quad1.setPoint(3, sf::Vector2f(-_scale, _scale / 2));
	quad1.setPosition(x, y);

	quad1.setFillColor(sf::Color(76, 153, 0));
	quad1.setOutlineColor(sf::Color::Black);
	quad1.setOutlineThickness(0.5);
	_window->draw(quad1);

	sf::ConvexShape quad2;
	quad2.setPointCount(4);
	quad2.setPoint(0, sf::Vector2f(_scale, 0));
	quad2.setPoint(1, sf::Vector2f(_scale, _scale / 2));
	quad2.setPoint(2, sf::Vector2f(0, _scale));
	quad2.setPoint(3, sf::Vector2f(0, _scale / 2));
	quad2.setPosition(x, y);
	quad2.setOutlineThickness(0.5);
	quad2.setFillColor(sf::Color(76, 153, 0));
	quad2.setOutlineColor(sf::Color::Black);
	_window->draw(quad2);

	sf::ConvexShape quad3;
	quad3.setPointCount(4);
	quad3.setPoint(0, sf::Vector2f(0, -_scale / 2));
	quad3.setPoint(1, sf::Vector2f(_scale, 0));
	quad3.setPoint(2, sf::Vector2f(0, _scale / 2));
	quad3.setPoint(3, sf::Vector2f(-_scale, 0));
	quad3.setPosition(x, y);
	quad3.setOutlineThickness(0.5);
	quad3.setFillColor(sf::Color(102, 204, 0));
	quad3.setOutlineColor(sf::Color::Black);
	_window->draw(quad3);
}

void		SFML::drawSnakeBody(int x, int y) const
{
	sf::ConvexShape quad1;
	quad1.setPointCount(4);
	quad1.setPoint(0, sf::Vector2f(-_scale, 0));
	quad1.setPoint(1, sf::Vector2f(0, _scale / 2));
	quad1.setPoint(2, sf::Vector2f(0, _scale));
	quad1.setPoint(3, sf::Vector2f(-_scale, _scale / 2));
	quad1.setPosition(x, y);

	quad1.setFillColor(sf::Color(204, 102, 0));
	quad1.setOutlineColor(sf::Color::Black);
	quad1.setOutlineThickness(0.5);
	_window->draw(quad1);

	sf::ConvexShape quad2;
	quad2.setPointCount(4);
	quad2.setPoint(0, sf::Vector2f(_scale, 0));
	quad2.setPoint(1, sf::Vector2f(_scale, _scale / 2));
	quad2.setPoint(2, sf::Vector2f(0, _scale));
	quad2.setPoint(3, sf::Vector2f(0, _scale / 2));
	quad2.setPosition(x, y);
	quad2.setFillColor(sf::Color(153, 76, 0));
	quad2.setOutlineColor(sf::Color::Black);
	quad2.setOutlineThickness(0.5);
	_window->draw(quad2);

	sf::ConvexShape quad3;
	quad3.setPointCount(4);
	quad3.setPoint(0, sf::Vector2f(0, -_scale / 2));
	quad3.setPoint(1, sf::Vector2f(_scale, 0));
	quad3.setPoint(2, sf::Vector2f(0, _scale / 2));
	quad3.setPoint(3, sf::Vector2f(-_scale, 0));
	quad3.setPosition(x, y);

	quad3.setFillColor(sf::Color(255, 128, 0));
	quad3.setOutlineColor(sf::Color::Black);
	quad3.setOutlineThickness(0.5);
	_window->draw(quad3);
}

void		SFML::drawSnakeFood(int x, int y) const
{
	sf::ConvexShape rect;

	rect.setPointCount(4);
	rect.setPoint(0, sf::Vector2f(0, 0));
	rect.setPoint(1, sf::Vector2f(_scale, _scale / 2));
	rect.setPoint(2, sf::Vector2f(0, _scale));
	rect.setPoint(3, sf::Vector2f(-_scale, _scale / 2));
	rect.setPosition(x, y);
	rect.setOutlineThickness(0.5);
	rect.setOutlineColor(sf::Color(77, 77, 77));
	_window->draw(rect);

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

}

void		SFML::mdraw(int index, int x, int y) const
{
	if (_game->map[index] == Game::SNAKE_HEAD)
		drawSnakeHead(x, y);
	else if (_game->map[index] == Game::SNAKE_BODY)
		drawSnakeBody(x, y);
	else if (_game->map[index] == Game::SNAKE_FOOD)
		drawSnakeFood(x, y);
	else
		drawFloor(x, y);
}

void		SFML::draw(void)
{
	_window->clear();

	int middle = _game->width * this->_scale * 2 / 2;

	int i;
	int j;

	i = middle;
	j = (_game->height * _scale / 2) - ((_scale / 2) + 1) * (_game->height / 2);

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
			j += (_scale / 2) + 1;
		}
		y += 1;
		i = middle - ((_scale * y) + y);
		j = (_game->height * _scale / 2) - ((_scale / 2) + 1) * (_game->height / 2) + ((_scale / 2 * y) + y);
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
