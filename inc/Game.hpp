//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:02:03
// :ddddddddddhyyddddddddddd: Modified: 2015-04-18 05:13:54
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <IGlib.hpp>

class IGlib;

class Game {
public:
	// class				Exception;
	struct				Snake
	{
		enum			Directions
		{
			UP,
			DOWN,
			LEFT,
			RIGHT
		};

		Directions		_d; // direction variable
		int				_s; // size variable
	};
	enum				Cells
	{
		EMPTY,
		SNAKE_HEAD,
		SNAKE_BODY,
		SNAKE_FOOD
	};

	Game(void) ;
	Game(int, char**) ;
	~Game(void) ;

	const Cells &		operator[](std::size_t) const ;
	bool				isOpen(void) ;

	int					getWidth(void) const ;
	int					getHeight(void) const ;
	Snake::Directions	getSnakeDirection(void) const ;

	void				update(void) ;
private:
	void				menu(void) ;
	std::string			usage(void) ;
	void				init(void) ;
	void				load(std::string) ;
	void				load(char) ;
	void				moveSnakeHead(void) ;
	void				collide(std::vector<Cells>::iterator, int);
	void				moveSnakeBody(std::vector<Cells>::iterator, int);

	Game(Game const & obj) { *this = obj; } ;
	Game &				operator=(Game const & rhs);

	int					_width;
	int					_height;
	std::vector<Cells>	_map;
	Snake				_snake;
	void *				_dl_handle;
	IGlib *				_glib;
};

#endif












