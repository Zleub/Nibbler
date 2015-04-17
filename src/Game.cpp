//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-15 20:20:04
// :ddddddddddhyyddddddddddd: Modified: 2015-04-16 03:51:43
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Game.hpp>

Game::Game(void) {
	int i = -1;

	this->width = 11;
	this->height = 11;

	// TEST MAP
	while (++i != this->width * this->height)
		this->map.push_back(Game::EMPTY);
	this->map[40] = Game::SNAKE_BODY;
	this->map[41] = Game::SNAKE_BODY;
	this->map[42] = Game::SNAKE_BODY;
	this->map[51] = Game::SNAKE_BODY;
	this->map[60] = Game::SNAKE_HEAD;
	this->map[61] = Game::SNAKE_BODY;
	this->map[62] = Game::SNAKE_BODY;
	this->map[80] = Game::SNAKE_FOOD;
}
