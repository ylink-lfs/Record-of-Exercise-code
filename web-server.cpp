#include <boost/asio.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::istream;
using std::ostream;
using std::fstream;
using std::stringstream;
using std::string;
using std::vector;
using namespace boost::asio;

const unsigned short server_port = 2222;

int main(void)
{
	//If the server has multiple ips, represent them all at once
	io_service ios;
	ip::address server_ip(ip::address_v4::any());
	ip::tcp::endpoint ep(server_ip, server_port);
	ip::tcp::acceptor acceptor(ios);
	try {
		acceptor.open(ep.protocol());
		acceptor.bind(ep);
		//Max connections are set to INT_MAX
		acceptor.listen();
		while (true)
		{
			ip::tcp::socket exc_sock(ios);
			//sock for data exchange is ready to receive data from client or post data to client
			acceptor.accept(exc_sock);

			streambuf sbuf;
			//Only need the first line of the message
			read_until(exc_sock, sbuf, '\n');
			
			string dir;
			istream ost(&sbuf);
			//Throw "GET" string itself
			ost >> dir;
			//Obtain file location
			ost >> dir;
			//Remove the preceding '/' character
			dir.erase(dir.begin());

			//Discard rest content
			read_until(exc_sock, sbuf, -1);

			fstream fst(dir);
			string buf("HTTP/1.1 ");
			if (!fst.is_open())
			{
				buf += "404 Not Found\r\n";
			}
			else
			{
				buf += "200 OK\r\nContent-Type: text-html\r\n\r\n";
			}
			write(exc_sock, buffer(buf));
			while (getline(fst, buf))
			{
				write(exc_sock, buffer(buf));
			}
			exc_sock.close();
		}
	} catch (boost::system::system_error e) {
		cerr << e.what() << '\n';
	} catch (...) {
		cerr << "Unknown error\n";
	}
	cin.get();
	return 0;
}