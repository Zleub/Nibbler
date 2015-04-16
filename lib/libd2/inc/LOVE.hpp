//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:LOVE
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 17:48:39
// :ddddddddddhyyddddddddddd: Modified: 2015-04-16 21:30:12
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef LOVE_HPP
#define LOVE_HPP

#include <IGlib.hpp>

class Love : public IGlib {
private:
	int						_scale;
	int						_fd;
	Game					* _game;

	void					checkError(void) const ;
	void					assign(void);

public:
	Love(void);
	Love(Love const &);
	~Love(void);

	IGlib &	operator=(IGlib const &);

	static int				isClosed;

	void					init(Game *) ;
	void					update(void);
	void					draw(void);
	bool					isOpen(void);
	bool					popEvent(void) ;
	IGlib::Event const *	getEvent(void) ;
	void					pushEvent(IGlib::Event *) ;
};

#endif
