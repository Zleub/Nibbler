//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:SFML
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 04:59:08
// :ddddddddddhyyddddddddddd: Modified: 2015-04-16 03:51:26
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef SFML_HPP
#define SFML_HPP

#include <IGlib.hpp>
#include <SFML/Graphics.hpp>

class SFML : public IGlib {
private:
	int				_scale;
	Game				* _game;
	sf::RenderWindow	* _window;

	void					checkError(void) const ;
	void					assign(void);

public:
	SFML(void);
	SFML(SFML const &);
	~SFML(void);

	IGlib &	operator=(IGlib const &);

	void					init(Game *) ;
	void					update(void);
	void					draw(void);
	void					mdraw(int, int, int);
	bool					isOpen(void);
	bool					popEvent(void) ;
	IGlib::Event const *	getEvent(void) ;
	void					pushEvent(IGlib::Event *) ;
};

#endif
