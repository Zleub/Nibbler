//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:03:34
// :ddddddddddhyyddddddddddd: Modified: 2015-04-07 19:17:36
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

extern "C" {
	#include <dlfcn.h>
}

#include <iostream>
#include <Glib.hpp>
#include <Glib_Exception.hpp>
#include <Glib_Event.hpp>

// Special Members

Glib::Glib(void)
{
	std::cout << "default new Glib with lib/libd1/libd1.so" << std::endl;

	if (!(_dl_handle = dlopen("lib/libd1/libd1.so", RTLD_LAZY | RTLD_LOCAL)))
		throw Glib::Exception();
	assign();
}

Glib::Glib(std::string lib)
{
	std::cout << "new Glib: " << lib << std::endl;

	if (!(_dl_handle = dlopen(lib.c_str(), RTLD_LAZY | RTLD_LOCAL)))
		throw Glib::Exception();
	assign();
}

Glib::~Glib()
{
	_destroy_t(_gl_handle);
	dlclose(_dl_handle);
}

// Private Members

void	Glib::assign(void)
{
	_create_t = (create_t *)(dlsym(_dl_handle, "create"));
	_destroy_t = (destroy_t *)(dlsym(_dl_handle, "destroy"));
	checkError();
	_gl_handle = _create_t();
}

void	Glib::checkError(void) const
{
	const char *	error;

	error = dlerror();
	if (error)
	{
		std::cerr << error << std::endl;
		throw Glib::Exception();
	}
}

// Public Members

void				Glib::init(void) const { _gl_handle->init(); }
void				Glib::draw(void) { _gl_handle->draw(); }
bool				Glib::isOpen(void) const { return _gl_handle->isOpen(); }
void				Glib::popEvent(void) { _stack.pop(); }
Glib::Event const *	Glib::getEvent(void) const { return _stack.top(); }
