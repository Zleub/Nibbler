//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:AGlib_Exception
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-05 00:16:08
// :ddddddddddhyyddddddddddd: Modified: 2015-04-10 15:21:00
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GLIB_EXCEPTION_HPP
#define GLIB_EXCEPTION_HPP

class AGlib::Exception : public std::exception {
public:
	Exception(void);
	Exception(Exception const &);
	~Exception(void) throw();

	virtual char const * what() const throw();
private:
	Exception &	operator=(Exception const &);

};

#endif
