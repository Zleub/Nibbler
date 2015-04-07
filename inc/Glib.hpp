//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:05:12
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 17:44:20
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GLIB_HPP
#define GLIB_HPP

#include <stack>
#include <AGlib.hpp>

class Glib {
public:
	class	Exception;
	class	Event;
	enum	Keys
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		ESC
	};

	Glib(void);
	Glib(std::string);
	~Glib(void);

	void		init(void) const ;
	void		draw(void) ;
	bool		isOpen(void) const ;
	void		popEvent(void) ;
	Glib::Event const *		getEvent(void) const ;
private:
	Glib(Glib const &);
	Glib &	operator=(Glib const &);

	void *				_dl_handle;
	AGlib *				_gl_handle;
	create_t *			_create_t;
	destroy_t *			_destroy_t;

	void				checkError(void) const ;
	void				assign(void);

	void				pushEvent(Event);

	std::stack<Event *>	_stack;
};

#endif
