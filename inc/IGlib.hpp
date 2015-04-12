//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:IGlib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:02:03
// :ddddddddddhyyddddddddddd: Modified: 2015-04-12 19:13:47
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef IGLIB_HPP
#define IGLIB_HPP

#include <stack>

class IGlib {
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

	virtual ~IGlib(void) {} ;

	virtual IGlib &					operator=(IGlib const &rhs) = 0;

	virtual void					init(void) = 0;
	virtual void					draw(void) = 0;

	virtual bool					isOpen(void) = 0;

	virtual bool					popEvent(void) = 0;
	virtual IGlib::Event const *	getEvent(void) = 0 ;
	virtual void					pushEvent(IGlib::Event *) = 0 ;

protected:
	void *							_dl_handle;

	virtual void					checkError(void) const = 0;
	virtual void					assign(void) = 0;

	std::stack<Event *>				_stack;

	// virtual std::stack<Event *>		getStack(void) const = 0 ;
};

typedef IGlib *						create_t();
typedef void						destroy_t(IGlib *);

#endif
