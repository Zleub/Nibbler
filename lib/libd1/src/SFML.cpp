//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:SFML
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:06:16
// :ddddddddddhyyddddddddddd: Modified: 2015-04-10 18:06:55
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>

#include <AGlib.hpp>
#include <AGlib_Event.hpp>
#include <AGlib_Exception.hpp>
#include <SFML.hpp>

extern "C" {
	#include <dlfcn.h>
}

SFML::SFML()
{
	std::cout << "default new AGlib with lib/libd1/libd1.so" << std::endl;

	if (!(_dl_handle = dlopen("lib/libd1/libd1.so", RTLD_LAZY | RTLD_LOCAL)))
		throw AGlib::Exception();
	assign();
	pushEvent(new AGlib::Event(AGlib::ESC));
}

SFML::~SFML()
{
	// _destroy_t(_gl_handle);
	dlclose(_dl_handle);
}

AGlib &		SFML::operator=(AGlib const &)
{
	return *this;
}

void	SFML::assign(void)
{
	// _create_t = (create_t *)(dlsym(_dl_handle, "create"));
	// _destroy_t = (destroy_t *)(dlsym(_dl_handle, "destroy"));
	// checkError();
	// _gl_handle = _create_t();
	// _gl_handle->setPush(&Glib::pushEvent);
}

void	SFML::checkError(void) const
{
	const char *	error;

	error = dlerror();
	if (error)
	{
		std::cerr << error << std::endl;
		throw AGlib::Exception();
	}
}

void		SFML::pushEvent(AGlib::Event * k) { _stack.push(k); }

void		SFML::init(void)
{
	std::cout << "SFML init 1" << std::endl;
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
}

void		SFML::draw(void)
{
	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();
		else if (event.type == sf::Event::KeyPressed)
			pushEvent(new AGlib::Event(AGlib::ESC));
			// std::cout << "i got a keypressed" << std::endl;
	}
	_window->clear();
	// _window->draw(sprite);
	_window->display();
}

bool		SFML::isOpen(void)
{
	return _window->isOpen();
}

AGlib::Event const *		SFML::getEvent(void) const
{
	if (!_stack.empty())
		return _stack.top();
	else
		return new AGlib::Event(AGlib::EMPTY);
}

bool					SFML::popEvent(void)
{
	if (_stack.empty())
		return false;
	else
		_stack.pop();
	return true;
}


extern "C"
{
	AGlib * create()
	{
		return new SFML();
	}

	void destroy(AGlib * p)
	{
		delete p;
	}
}
