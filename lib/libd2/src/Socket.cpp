//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Nibbler:Socket
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-17 19:22:25
// :ddddddddddhyyddddddddddd: Modified: 2015-04-17 20:06:29
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <sstream>
#include "Socket.hpp"

Socket::Socket(std::string host, int port) : _nbClients(0)
{
	this->fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->fd == -1)
		std::cerr << "socket creation failed" << std::endl;

	memset(&(this->my_addr), 0, sizeof(struct sockaddr_in));
	this->my_addr.sin_family = AF_INET;
	inet_aton(host.c_str(), (struct in_addr *)&(this->my_addr).sin_addr);
	this->my_addr.sin_port = htons(port);

	if (bind(this->fd, (struct sockaddr *)&(this->my_addr), sizeof(struct sockaddr_in)) == -1)
		std::cerr << "bind failed" << std::endl;
	if (listen(this->fd, 0) == -1)
		std::cerr << "listen failed" << std::endl;

	FD_ZERO (&(this->active_fd_set));
	FD_SET (this->fd, &(this->active_fd_set));
};

Socket::~Socket(void) {};

void	Socket::_select(void)
{
	std::cout << "_select : nb client : " << _nbClients << std::endl;

	read_fd_set = active_fd_set;
	if (select (FD_SETSIZE, &(this->read_fd_set), NULL, NULL, NULL) < 0)
	{
		std::cerr << "select" << std::endl;
		return ;
	}
	for (int i = 0; i < FD_SETSIZE; ++i)
	{
		if (FD_ISSET (i, &(this->read_fd_set)))
		{
			if (i == this->fd)
				this->_accept();
			else
			{
				if (!this->_read(i))
				{
					std::cout << "Client " << i << " left" << std::endl;
					close (i);
					FD_CLR (i, &active_fd_set);
					_nbClients -= 1;
				}
			}
		}
	}
};

Client &	Socket::_accept(void)
{
	Client	*c;

	c = new Client();
	c->setFd(accept(this->fd, c->getAddr(), c->getAddrsize()));
	if (c->getFd() < 0)
		std::cerr << "error accept" << std::endl;
	std::cout << "new client on " << c->getFd() << std::endl;
	_nbClients += 1;
	FD_SET(c->getFd(), &(this->active_fd_set));
	return (*c);
}

void		Socket::_write(int fd, std::string str)
{
	str += '\n';
	write(fd, str.c_str(), str.size());
}

int			Socket::_read(int fd)
{
	char	buf[255];
	int		n;

	memset(buf, 0, 255);
	if (!(n = read(fd, buf, 255)))
		return 0;
	else if (n < 0)
	{
		std::cerr << "read" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "got message: " << buf << " by " << fd << std::endl;
		return 1;
	}
}

int		Socket::getFd(void) { return this->fd; }
int		Socket::getNbClients(void) { return this->_nbClients; }
