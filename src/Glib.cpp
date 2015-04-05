//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Glib
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:03:34
// :ddddddddddhyyddddddddddd: Modified: 2015-04-05 11:12:41
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

Glib::Glib(void)
{
	std::cout << "default new Glib with lib/libd1/libd1.so" << std::endl;

	if (!(_dl_handle = dlopen("lib/libd1/libd1.so", RTLD_LAZY | RTLD_LOCAL)))
		throw Glib::Exception();
	_create_t = (create_t *)(dlsym(_dl_handle, "create"));
	_destroy_t = (destroy_t *)(dlsym(_dl_handle, "destroy"));
	_gl_handle = _create_t();
}

Glib::Glib(std::string lib)
{
	std::cout << "new Glib: " << lib << std::endl;

	if (!(_dl_handle = dlopen(lib.c_str(), RTLD_LAZY | RTLD_LOCAL)))
		throw Glib::Exception();
	_create_t = (create_t *)(dlsym(_dl_handle, "create"));
	_destroy_t = (destroy_t *)(dlsym(_dl_handle, "destroy"));
	_gl_handle = _create_t();
}

Glib::~Glib()
{
	dlclose(_dl_handle);
}

void	Glib::init(void) const
{
	_gl_handle->init();
}

void	Glib::update(void)
{
	_gl_handle->update();
}

bool	Glib::isOpen(void)
{
	return _gl_handle->isOpen();
}
