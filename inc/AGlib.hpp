//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:AGlib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:02:03
// :ddddddddddhyyddddddddddd: Modified: 2015-04-10 18:53:18
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef AGLIB_HPP
#define AGLIB_HPP

#include <stack>

class AGlib {
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

	// AGlib(void) {};
	virtual ~AGlib(void) {} ;

	virtual AGlib &					operator=(AGlib const &);

	virtual void					init(void);
	virtual void					draw(void);

	virtual bool					isOpen(void);

	virtual bool					popEvent(void);
	virtual AGlib::Event const *	getEvent(void) const;
	virtual void					pushEvent(AGlib::Event *);

protected:
	void *							_dl_handle;
	// create_t *					_create_t;
	// destroy_t *					_destroy_t;

	virtual void					checkError(void) const ;
	virtual void					assign(void);

	std::stack<Event *>				_stack;
};

typedef AGlib *						create_t();
typedef void						destroy_t(AGlib *);

#endif
