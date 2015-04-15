//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:02:03
// :ddddddddddhyyddddddddddd: Modified: 2015-04-15 20:20:34
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

class Game {
public:

	int					width;
	int					height;
	std::vector<char>	map;

	enum				map_cells
	{
		EMPTY,
		SNAKE_HEAD,
		SNAKE_BODY,
		FOOD
	};

	Game(void) ;
	Game(Game const & obj) { *this = obj; } ;
	~Game(void) {} ;

	Game &					operator=(Game const & rhs);

};

#endif












