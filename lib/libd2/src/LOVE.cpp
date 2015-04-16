//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:LOVE
// /ddddy:oddddddddds:sddddd/ By Zleub - Zleub
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 16:42:16
// :ddddddddddhyyddddddddddd: Modified: 2015-04-17 00:08:43
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

int	Love::isClosed = 0;

Love::Love(void) {}
Love::~Love(void) {}

IGlib &		Love::operator=(IGlib const &)
{
	return *this;
}

void		Love::pushEvent(IGlib::Event * k) { _stack.push(k); }

void		caca(int sig)
{
	if (sig == 20)
		Love::isClosed = 1;
	std::cout << sig << std::endl;
}

void		Love::init(Game * game)
{
	std::cout << "Love init 1: you need love in your PATH" << std::endl;

	_game = game;

	int		p1[2];
	if (pipe(p1))
		std::cout << "No pipe !" << std::endl;
	int		p2[2];
	if (pipe(p2))
		std::cout << "No pipe !" << std::endl;

	const char	*argv[3] = {
		"love",
		"ext/love",
		NULL
	};
	pid_t i = fork();
	if (i == 0)
	{
		close(p1[1]);
		dup2(p1[0], 0);

		close(p2[0]);
		dup2(p2[1], 1);
		execvp("love", (char * const *)argv) ;
	}
	else if (i > 0)
	{
		_fd = p1[1];
		close(p1[0]);

		close(p2[1]);
		dup2(p2[0], 0);
		std::cout << "dad" << std::endl;
		signal(SIGCHLD, caca);
	}
	// else
	// {
	// 	std::cout << "fork failed" << std::endl;
	// 	exit(-1);
	// }
}

void					Love::draw(void) {
	static int i;
	// std::cout << "draw" << std::endl;

	std::string s = std::to_string(i) + "\n";
	write(_fd, s.c_str(), s.length());
	i += 1;
}
void					Love::update(void) { std::cout << "c++ update" << std::endl; }
bool					Love::isOpen(void) { if (Love::isClosed) return false; else return true; }
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
