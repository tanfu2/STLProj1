#include<iostream>
#include <xmemory>
#include <list>

int main()
{
	std::cout << sizeof(std::list<int>) << std::endl;
	std::allocator<int> test = std::allocator<int>();
	int* p = test.allocate(10);
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
		std::cout << *(p + i) << " ";
	}
	std::cout << std::endl;
	test.deallocate(p, 10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << *(p + i) << "\t";
	}
	std::cout << std::endl;
	return 0;
}