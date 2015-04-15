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

	Game(void) {} ;
	Game(Game const & obj) {} ;
	~Game(void) {} ;

	Game &					operator=(Game const &rhs) = 0;

};

#endif










