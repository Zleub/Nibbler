//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-15 20:20:04
// :ddddddddddhyyddddddddddd: Modified: 2015-04-18 02:53:10
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Game.hpp>
#include <iostream>
#include <sstream>

#include <IGlib_Event.hpp>
#include <IGlib_Exception.hpp>

extern "C" {
	#include <dlfcn.h>
}

Game::Game(void) : _width(11), _height(11) {
	init();
}

Game::Game(int argc, char** argv) : _width(11), _height(11) {
	init();

	if (argc == 2) {
		try {
			load(std::string(argv[1]));
		} catch ( std::exception & e ) {
			std::cout << e.what() << std::endl;
		}
	}
	else {
		char response;

		std::cout << usage() << std::endl;
		std::cin >> response;
		try {
			load(response);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
}

Game::~Game(void) {}

void				Game::init(void) {
	int i = -1;

	while (++i != this->getWidth() * this->getHeight())
		_map.push_back(Game::EMPTY);
	_map[this->getWidth() * this->getHeight() / 2] = SNAKE_HEAD;
	_snake._d = Game::Snake::LEFT;
	_snake._s = 1;
}

std::string			Game::usage(void) {
	std::stringstream ss;

	ss << "\033[0;32m" << std::endl;
	ss << "       -------       Nibbler       -------       " << std::endl;
	ss << "Usage: ./Nibbler <library.so>" << std::endl;
	ss << "No library specified, please choose :" << std::endl;
	ss << "[1] SFML library ('lib/libd1/libd1.so')" << std::endl;
	ss << "[2] LOVE library ('lib/libd2/libd2.so')" << std::endl;
	ss << "[3] OTHER library ('path/to/lib.so')" << std::endl;
	ss << "\033[0;0m" << std::endl;
	return ss.str();
}

const Game::Cells &		Game::operator[](std::size_t index) const { return _map[index]; }
bool					Game::isOpen(void) { return _glib->isOpen(); }
int						Game::getWidth(void) const { return _width; }
int						Game::getHeight(void) const { return _height; }
Game::Snake::Directions	Game::getSnakeDirection(void) const { return _snake._d; }

void				Game::load(std::string lib) {
	if (!(_dl_handle = dlopen(lib.c_str(), RTLD_LAZY | RTLD_LOCAL)))
		throw IGlib::Exception();
	IGlib * (* _create_t)(void) = (create_t *)(dlsym(_dl_handle, "create"));
	if (!(_glib = _create_t()))
		throw IGlib::Exception();
	_glib->init(this);
}

void				Game::load(char lib) {
	std::stringstream	ss;

	ss << "lib/libd" << lib << "/libd" << lib << ".so";
	if (!(_dl_handle = dlopen(ss.str().c_str(), RTLD_LAZY | RTLD_LOCAL)))
		throw IGlib::Exception();
	IGlib * (* _create_t)(void) = (create_t *)(dlsym(_dl_handle, "create"));
	if (!(_glib = _create_t()))
		throw IGlib::Exception();
	_glib->init(this);
}

void				Game::update(void) {
	static int i;
	IGlib::Event const * e;

	i += 1;
	if (i > 100)
	{
		moveSnake();
		i = 0;
	}
	_glib->update();
	do
	{
		e = _glib->getEvent();

		// KEYBOARD INPUT

		if (e->key == IGlib::ESC)
			std::cout << "ESC" << std::endl;
		if (e->key == IGlib::UP) {
			std::cout << "UP" << std::endl;
			_snake._d = Game::Snake::UP;
		}

		if (e->key == IGlib::DOWN) {
			std::cout << "DOWN" << std::endl;
			_snake._d = Game::Snake::DOWN;
		}

		if (e->key == IGlib::LEFT) {
			std::cout << "LEFT" << std::endl;
			_snake._d = Game::Snake::LEFT;
		}

		if (e->key == IGlib::RIGHT) {
			std::cout << "RIGHT" << std::endl;
			_snake._d = Game::Snake::RIGHT;
		}

		else if (e->key == IGlib::EMPTY)
			; //std::cout << "EMPTY" << std::endl;

	} while (_glib->popEvent()) ;
	_glib->draw();
}

void				Game::moveSnake()
{
	std::vector<Game::Cells>::iterator it;

	it = std::find(_map.begin(), _map.end(), Game::SNAKE_HEAD);
	if (it == _map.end())
		std::cout << "snake has no head" << std::endl;
	else {
		if (_snake._d == Game::Snake::LEFT) {
			*it = Game::EMPTY;
			it -= 1;
			*it = Game::SNAKE_HEAD;
		} else if (_snake._d == Game::Snake::RIGHT) {
			*it = Game::EMPTY;
			it += 1;
			*it = Game::SNAKE_HEAD;
		} else if (_snake._d == Game::Snake::UP) {
			*it = Game::EMPTY;
			it -= _width;
			*it = Game::SNAKE_HEAD;
		} else if (_snake._d == Game::Snake::DOWN) {
			*it = Game::EMPTY;
			it += _width;
			*it = Game::SNAKE_HEAD;
		}
	}
}
