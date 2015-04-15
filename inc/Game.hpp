//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:02:03
// :ddddddddddhyyddddddddddd: Modified: 2015-04-12 19:13:47
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GAME_HPP
#define GAME_HPP

# include <vector>

class Game {
public:

	static int			width;
	static int			height;
	std::vector<char>	map;

	enum				map_cells
	{
		EMPTY,
		SNAKE_HEAD,
		SNAKE_BODY,
		FOOD
	};

	Game(void) {
		int i = -1;

		this->width = 11;
		this->height = 11;

		while (++i != this->width * this->height)
			this->map.push_back(Game::EMPTY);
	} ;
	Game(Game const & obj) {} ;
	~Game(void) {} ;

	Game &					operator=(Game const &rhs) = 0;

};

#endif












