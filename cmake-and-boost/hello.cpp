#include <boost/algorithm/string.hpp>
#include <boost/program_options/option.hpp>
#include <boost/program_options/options_description.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;
namespace po = boost::program_options;

int main()
{
  std::string s = "Boost C++ Libraries";
  std::cout << to_upper_copy(s) << '\n';

  po::options_description desc("Allowed options");
  desc.add_options()
	  ("help", "produce help message");

}
