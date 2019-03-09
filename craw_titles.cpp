#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <cstdlib>

#define COMPILED_IN_WINDOWS

using namespace boost::asio;

int main(void)
{	
	std::string host("ylinknest.top");
	std::string http_port("80");
	std::ofstream log_stream("process.log");
	io_service ios;
	ip::tcp::resolver::query one_query(host, http_port, ip::tcp::resolver::query::numeric_service);
	ip::tcp::resolver resolver(ios);
	try {
		//Establish connection
		std::cout << "Resolving DNS..." << host << '\n';
		log_stream << "Resolving DNS..." << host << '\n';
		auto endpoint_it = resolver.resolve(one_query);
		ip::tcp::socket sock(ios);
		connect(sock, endpoint_it);
		std::cout << "Resolution result: " + sock.remote_endpoint().address().to_string() + "\n";
		log_stream << "Resolution result: " + sock.remote_endpoint().address().to_string() + "\n";
		std::cout << "Successfully established connection to " << host + ":" + http_port << '\n';
		log_stream << "Successfully established connection to " << host + ":" + http_port << '\n';

		//Send an GET request for index page
		//Problem: If I use "/" in what_target, then the server return 200
		//	Else, the server return 301. Why and how to handle it?
		std::string what_target("/");
		std::string http_version("HTTP/1.1");
		std::string GET_request(
			"GET " + what_target + " " + http_version + "\r\n" + \
			"Host: " + host + "\r\n" + \
			"Accept: */*" + "\r\n\r\n");
		streambuf http_request;
		std::ostream request_stream(&http_request);
		request_stream << GET_request;
		write(sock, http_request);

		std::cout << "Posted GET request:\n";
		std::cout << GET_request;
		log_stream << "Posted GET request:\n";
		log_stream << GET_request;

		//Get the feedback
		streambuf response;
		std::ofstream ost("get-result.htm");
		boost::system::error_code ec;
		while (read(sock, response, transfer_at_least(512), ec))
		{
			ost << &response;
		}
		ost.close();
		sock.close();
		std::cout << "Socket to " << host + ":" + http_port << " closed.\n";
		log_stream << "Socket to " << host + ":" + http_port << " closed.\n";

		//Parse
		//Use this regex: "<h2 class="post-title">.+</h2>"
		std::ifstream ist("get-result.htm");
		std::string buf;
		std::regex pattern(R"(<h2 class="post-title">.+</h2>)");
		std::vector<std::string> fit_result;
		std::cout << "Pattern matching start.\n";
		log_stream << "Pattern matching start.\n";
		while (std::getline(ist, buf))
		{
			if (std::regex_search(buf, pattern))
			{
				fit_result.push_back(buf);
			}
		}
		std::cout << "Pattern matching complete.\n";
		log_stream << "Pattern matching complete.\n";

		//Modify parsing result
		std::vector<std::string> title_result;
		for (auto elem : fit_result)
		{
			size_t start_index = elem.rfind("title");
			size_t end_index = elem.find('>', start_index);
			std::string sub(elem.substr(start_index, end_index - start_index + 1));
			
			size_t start_quote = sub.find('"');
			size_t last_quote = sub.find('"', start_quote + 1);
			title_result.push_back(sub.substr(start_quote + 1, last_quote - start_quote - 1));
		}

		//Write result to file
		std::cout << "Write result into files...\n";
		log_stream << "Write result into files...\n";
		std::ofstream res_stream("match-result.txt");
		res_stream << "The parse result of title:\n";
		for (const auto& elem : title_result)
		{
			std::cout << elem << '\n';
			res_stream << elem << '\n';
		}
		std::cout << "Writing done.\n";
		log_stream << "Writing done.\n";
		res_stream.close();
		log_stream.close();

		//Problem: Strange control flow shown in txt files

#ifdef COMPILED_IN_WINDOWS
		std::system("pause");
#endif

	} catch (boost::system::system_error& e) {
		std::cerr << "Error occured with error code = " << e.code() << ". Message: " << e.what() << '\n';
#ifdef COMPILED_IN_WINDOWS
		std::system("pause");
#endif
		return e.code().value();
	}

	return 0;
}