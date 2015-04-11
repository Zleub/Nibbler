//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:SFML
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 04:59:08
// :ddddddddddhyyddddddddddd: Modified: 2015-04-10 18:52:53
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef SFML_HPP
#define SFML_HPP

#include <AGlib.hpp>
#include <SFML/Graphics.hpp>

class SFML : public AGlib {
private:
	sf::RenderWindow	*_window;

	void					checkError(void) const ;
	void					assign(void);

public:
	SFML(void);
	SFML(SFML const &);
	~SFML(void);

	AGlib &	operator=(AGlib const &);

	void					init(void) ;
	void					draw(void);
	bool					isOpen(void);
	bool					popEvent(void) ;
	AGlib::Event const *	getEvent(void) const ;
	void					pushEvent(AGlib::Event *) ;
};

#endif
