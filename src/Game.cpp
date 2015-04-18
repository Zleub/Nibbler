//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-15 20:20:04
// :ddddddddddhyyddddddddddd: Modified: 2015-04-18 02:04:41
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Game.hpp>

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

Game::~Game(void) {}

void				Game::udpate(void) {

}

const Game::Cells &	Game::operator[](std::size_t index) const { return _map[index]; }
int					Game::getWidth(void) const { return _width; }
int					Game::getHeight(void) const { return _height; }
Snake::Directions	Game::getSnakeDirection(void) const { return _snake._d; }

void				Game::update(void) {
	IGlib::Event const * e;

	p->update();
	do
	{
		e = p->getEvent();

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

	} while (p->popEvent()) ;
}
