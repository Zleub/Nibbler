//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:SFML
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 04:59:08
// :ddddddddddhyyddddddddddd: Modified: 2015-04-11 21:02:46
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef SFML_HPP
#define SFML_HPP

#include <Glib.hpp>
#include <SFML/Graphics.hpp>

class SFML : public Glib {
private:
	sf::RenderWindow	*_window;

	void					checkError(void) const ;
	void					assign(void);

public:
	SFML(void);
	SFML(SFML const &);
	~SFML(void);

	Glib &	operator=(Glib const &);

	virtual void					init(void) ;
	virtual void					draw(void);
	virtual bool					isOpen(void);
	virtual bool					popEvent(void) ;
	virtual Glib::Event const *		getEvent(void) ;
	virtual void					pushEvent(Glib::Event *) ;
};

#endif
