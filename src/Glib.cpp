//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:03:34
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 17:52:27
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

// Special Members

Glib::Glib(void)
{
	std::cout << "default new Glib with lib/libd1/libd1.so" << std::endl;

	if (!(_dl_handle = dlopen("lib/libd1/libd1.so", RTLD_LAZY | RTLD_LOCAL)))
		throw Glib::Exception();
	assign();
	_gl_handle = _create_t();
}

Glib::Glib(std::string lib)
{
	std::cout << "new Glib: " << lib << std::endl;

	if (!(_dl_handle = dlopen(lib.c_str(), RTLD_LAZY | RTLD_LOCAL)))
		throw Glib::Exception();
	assign();
	_gl_handle = _create_t();
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
	raise();
}

void	Glib::raise(void)
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

void	Glib::init(void) const
{
	_gl_handle->init();
}

void	Glib::update(void)
{
	_gl_handle->update();
}

bool	Glib::isOpen(void) const
{
	return _gl_handle->isOpen();
}
