//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:LOVE
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 16:42:16
// :ddddddddddhyyddddddddddd: Modified: 2015-04-17 20:11:10
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

extern "C" {
	#include <unistd.h>
}

#include <iostream>
#include <LOVE.hpp>
#include <IGlib_Event.hpp>

IGlib::Event::Event() {}
IGlib::Event::Event(IGlib::Keys k) { key = k; }
IGlib::Event::~Event() {}

IGlib::Event::Event(IGlib::Event const & e)
{
	key = e.key;
}

IGlib::Event const &		IGlib::Event::operator=(IGlib::Event const & rhs)
{
	*this = rhs;
	return (*this);
}

/* * * * */

int			Love::Closed = 0;

Love::Love(void) {}
Love::~Love(void) {}

IGlib &		Love::operator=(IGlib const &)
{
	return *this;
}

void		Love::pushEvent(IGlib::Event * k) { _stack.push(k); }

void		Love::init(Game * game)
{
	std::cout << "Love init 1: you need love in your PATH" << std::endl;

	_game = game;

	const char	*argv[3] = {
		"love",
		"ext/love",
		NULL
	};
	pid_t i = fork();
	if (i == 0)
	{
		execvp("love", (char * const *)argv) ;
	}
	else if (i > 0)
	{
		std::cout << "dad" << std::endl;
		_socket = new Socket("127.0.0.1", 4242);
	}
	else
	{
		std::cout << "fork failed" << std::endl;
		exit(-1);
	}
}

void					Love::update(void) {
	std::cout << "Love::update" << std::endl;
	_socket->_select();
}
void					Love::draw(void) {
	static int i;

	std::cout << "Love::draw" << std::endl;
	_socket->_write(4, "caca !");
	i += 1;
}
bool					Love::isOpen(void) { if (Love::Closed) return false; else return true; }
bool					Love::popEvent(void) { return false; }
IGlib::Event const *	Love::getEvent(void) { return new IGlib::Event(IGlib::EMPTY); }

extern "C"
{
	IGlib * create()
	{
		return new Love();
	}

	void destroy(IGlib * p)
	{
		delete p;
	}
}
