//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:SFML
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-10 15:06:16
// :ddddddddddhyyddddddddddd: Modified: 2015-04-12 20:39:02
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>

#include <SFML.hpp>
#include <IGlib_Exception.hpp>
#include <IGlib_Event.hpp>

extern "C" {
	#include <dlfcn.h>
}

SFML::SFML()
{
	// std::cout << "default new IGlib with lib/libd1/libd1.so" << std::endl;

	// if (!(_dl_handle = dlopen("lib/libd1/libd1.so", RTLD_LAZY | RTLD_LOCAL)))
	// 	throw IGlib::Exception();
	// assign();
	// pushEvent(new IGlib::Event(IGlib::ESC));
}

SFML::~SFML()
{
	// _destroy_t(_gl_handle);
	// dlclose(_dl_handle);
}

IGlib &		SFML::operator=(IGlib const &)
{
	return *this;
}

void	SFML::assign(void)
{
	// _create_t = (create_t *)(dlsym(_dl_handle, "create"));
	// _destroy_t = (destroy_t *)(dlsym(_dl_handle, "destroy"));
	// checkError();
	// _gl_handle = _create_t();
	// _gl_handle->setPush(&IGlib::pushEvent);
}

void	SFML::checkError(void) const
{
	// const char *	error;

	// error = dlerror();
	// if (error)
	// {
	// 	std::cerr << error << std::endl;
	// 	throw IGlib::Exception();
	// }
}

void		SFML::pushEvent(IGlib::Event * k) { _stack.push(k); }

void		SFML::init(void)
{
	std::cout << "SFML init 1" << std::endl;
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
}

void		SFML::update(void)
{
	sf::Event event;

	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			pushEvent(new IGlib::Event(IGlib::ESC));
				if (event.key.code == sf::Keyboard::Up)
			pushEvent(new IGlib::Event(IGlib::UP));
				if (event.key.code == sf::Keyboard::Down)
			pushEvent(new IGlib::Event(IGlib::DOWN));
				if (event.key.code == sf::Keyboard::Left)
			pushEvent(new IGlib::Event(IGlib::LEFT));
				if (event.key.code == sf::Keyboard::Right)
			pushEvent(new IGlib::Event(IGlib::RIGHT));
			// std::cout << "i got a keypressed" << std::endl;
		}
	}
}

void		SFML::draw(void)
{
	_window->clear();
	// _window->draw(sprite);
	_window->display();
}

bool		SFML::isOpen(void)
{
	return _window->isOpen();
}

IGlib::Event const *		SFML::getEvent(void)
{
	if (!_stack.empty())
		return _stack.top();
	else
		return new IGlib::Event(IGlib::EMPTY);
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
	IGlib * create()
	{
		return new SFML();
	}

	void destroy(IGlib * p)
	{
		delete p;
	}
}
