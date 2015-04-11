//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:LOVE
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 17:48:39
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 17:55:28
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef LOVE_HPP
#define LOVE_HPP

#include <AGlib.hpp>

class LOVE : public AGlib {
public:
	LOVE(void);
	LOVE(LOVE const &);
	virtual ~LOVE(void);

	virtual AGlib &	operator=(AGlib const &);

	virtual void		init(void);
	virtual void		draw(void);
	virtual bool		isOpen(void);
	virtual void		setPush(void(Glib::* p)(Glib::Event *));
};

#endif
