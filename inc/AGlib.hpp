//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:AGlib
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 05:23:58
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 11:05:35
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef AGLIB_HPP
#define AGLIB_HPP

class AGlib {
protected:

public:
	AGlib(void) {};
	AGlib(AGlib const &) {};
	virtual ~AGlib(void) {};

	virtual AGlib &	operator=(AGlib const &) = 0;

	virtual void	init(void) = 0;
	virtual void	update(void) = 0;

	virtual bool	isOpen(void) = 0;
};

typedef AGlib *		create_t();
typedef void		destroy_t(AGlib *);

#endif
