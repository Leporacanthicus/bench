#include <iostream>
#include <vector>
#include <cstdint>

#define N 300000000

int main(void)
{
    std::vector<int> d;
    for(int i = 0; i < N; i++)
	d.push_back(i);

    uint64_t sum = 0;
    for (int i = 0; i < N; i++)
	sum += d[i];

    std::cout << "Sum is " << sum << std::endl;
}
