#include <string>
#include <sstream>
#include <iostream>

#include <libxml++/libxml++.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "myExceptions.hpp"


using namespace curlpp::options;

int test()
{
	try
	{
		curlpp::Cleanup myCleanup;

		std::ostringstream os;
		os<<curlpp::options::Url("https://he8.wikipedia.org/wiki/Dependency_injection");
		auto html = os.str();
		std::cout<<html<<std::endl;
	}

	catch(curlpp::RuntimeError & e)
	{
		throw es::inValidURL("https://he.wikipedia.org/wiki/Dependency_injection");
		std::cout << "ytfrtdf" << std::endl;
		std::cout << e.what() << std::endl;
	}

	catch(curlpp::LogicError & e)
	{
		std::cout << e.what() << std::endl;
	}
    
  return 0;
}

// #include <curlpp/cURLpp.hpp>
// #include <curlpp/Easy.hpp>
// #include <curlpp/Options.hpp>

// int tast() {
//   curlpp::Easy myRequest;
//   myRequest.setOpt<CURLOPT_URL>("http://www.google.com");
//   myRequest.setOpt<CURLOPT_TIMEOUT>(10);
//   myRequest.perform();
//   long response_code;
//   myRequest.getinfo<CURLINFO_RESPONSE_CODE>(response_code);
//   if (response_code == 200) {
//     std::cout << "Network connection is available." << std::endl;
//   } else {
//     std::cout << "Network connection is not available." << std::endl;
//   }
//   return 0;
// }
