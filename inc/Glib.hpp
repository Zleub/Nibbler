//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:02:03
// :ddddddddddhyyddddddddddd: Modified: 2015-04-11 21:06:26
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GLIB_HPP
#define GLIB_HPP

#include <stack>

class Glib {
public:
	class	Exception;
	class	Event;
	enum	Keys
	{
		EMPTY,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		ESC
	};

	virtual ~Glib(void) {} ;

	virtual Glib &					operator=(Glib const &rhs) = 0;

	virtual void					init(void) = 0;
	virtual void					draw(void) = 0;

	virtual bool					isOpen(void) = 0;

	virtual bool					popEvent(void) = 0;
	virtual Glib::Event const *		getEvent(void) = 0 ;
	virtual void					pushEvent(Glib::Event *) = 0 ;

protected:
	void *							_dl_handle;
	// create_t *					_create_t;
	// destroy_t *					_destroy_t;

	virtual void					checkError(void) const = 0;
	virtual void					assign(void) = 0;

	std::stack<Event *>				_stack;

	// virtual std::stack<Event *>		getStack(void) const = 0 ;
};

typedef Glib *						create_t();
typedef void						destroy_t(Glib *);

#endif
