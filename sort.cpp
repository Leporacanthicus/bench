#include <algorithm>
#include <cstdlib>
#include <iostream>

const int n = 10000000;
int arr[n];

int main()
{
    for(auto& i: arr)
	i = rand();

    std::sort(&arr[0], &arr[n]);
    // Print the 10 smallest and 10 biggest numbers. 
    for(int i = 0; i < 10; i++)
	std::cout << "Smallest=" << arr[i] << " Biggest=" << arr[n-(i+1)] << std::endl;
}
