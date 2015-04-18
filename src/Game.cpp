//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-15 20:20:04
// :ddddddddddhyyddddddddddd: Modified: 2015-04-18 02:32:20
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
	int i = -1;

	// TEST MAP
	while (++i != this->getWidth() * this->getHeight())
		_map.push_back(Game::EMPTY);
	_map[40] = Game::SNAKE_BODY;
	_map[41] = Game::SNAKE_BODY;
	_map[42] = Game::SNAKE_BODY;
	_map[51] = Game::SNAKE_BODY;
	_map[60] = Game::SNAKE_HEAD;
	_map[61] = Game::SNAKE_BODY;
	_map[62] = Game::SNAKE_BODY;
	_map[80] = Game::SNAKE_FOOD;
}

Game::Game(int argc, char** argv) : _width(11), _height(11) {
	int i = -1;

	// TEST MAP
	while (++i != this->getWidth() * this->getHeight())
		_map.push_back(Game::EMPTY);
	_map[40] = Game::SNAKE_BODY;
	_map[41] = Game::SNAKE_BODY;
	_map[42] = Game::SNAKE_BODY;
	_map[51] = Game::SNAKE_BODY;
	_map[60] = Game::SNAKE_HEAD;
	_map[61] = Game::SNAKE_BODY;
	_map[62] = Game::SNAKE_BODY;
	_map[80] = Game::SNAKE_FOOD;

	std::cout << "checkpoint" << std::endl;

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
	IGlib::Event const * e;

	_glib->update();
	do
	{
		e = _glib->getEvent();

		// KEYBOARD INPUT

		if (e->key == IGlib::ESC)
			std::cout << "ESC" << std::endl;
		if (e->key == IGlib::UP)
			std::cout << "UP" << std::endl;
		if (e->key == IGlib::DOWN)
			std::cout << "DOWN" << std::endl;
		if (e->key == IGlib::LEFT)
			std::cout << "LEFT" << std::endl;
		if (e->key == IGlib::RIGHT)
			std::cout << "RIGHT" << std::endl;
		else if (e->key == IGlib::EMPTY)
			; //std::cout << "EMPTY" << std::endl;

	} while (_glib->popEvent()) ;
	_glib->draw();
}
