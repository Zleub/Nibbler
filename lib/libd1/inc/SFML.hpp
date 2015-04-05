//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:SFML
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 04:59:08
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 17:53:21
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef SFML_HPP
#define SFML_HPP

#include <SFML/Graphics.hpp>
#include <AGlib.hpp>

class SFML : public AGlib {
private:
	sf::RenderWindow	*_window;
public:
	SFML(SFML const &);
	SFML(void);
	virtual ~SFML(void);

	virtual AGlib &	operator=(AGlib const &);

	virtual void		init(void);
	virtual void		update(void);
	virtual bool		isOpen(void);
};

#endif
