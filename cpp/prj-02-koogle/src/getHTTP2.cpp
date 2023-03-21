#include "getHTTP2.hpp"

se::BasePage getHTTPpage(std::string const& url)
{
    std::cout<<"getHTTPpage"<<std::endl;
	curlpp::Cleanup myCleanup;
	curlpp::Easy myRequest;
	std::stringstream os;
	myRequest.setOpt<curlpp::options::Url>(url);
	myRequest.setOpt<curlpp::options::Timeout>(10);
	myRequest.setOpt<curlpp::options::FollowLocation>(true);
	myRequest.setOpt<curlpp::options::WriteStream>(&os);
	myRequest.perform();
	return se::BasePage(url, os.str());
}
/*
int test2() {
    // Create a curlpp::Easy object to make the request
    curlpp::Easy request;

    // Set the URL to be requested
    request.setOpt(curlpp::Options::Url("http://example.com"));

    // Perform the request
    request.perform();

    // Get the response code
    long response_code;
    curlpp::Infos::ResponseCode::get(request, response_code);
    // Print the response code
    std::cout << "Response code: " << response_code << std::endl;

    return 0;
}
*/
