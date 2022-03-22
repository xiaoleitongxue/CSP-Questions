#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
    std::string s;

    std::getline( std::cin, s );

    std::istringstream is( s );

    std::vector<int> v( ( std::istream_iterator<int>( is ) ), std::istream_iterator<int>() );

    for ( int x : v) std::cout << x << ' ';
    std::cout << std::endl;

    return 0;
}