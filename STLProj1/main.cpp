#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

int main()
{
	int ia[6] = { 1,3,2,5,4,6 };
	std::vector<int, std::allocator<int>> vi(ia, ia + 6);
	for (std::vector<int, std::allocator<int>>::iterator ite = vi.begin(); ite != vi.end(); ite++)
	{
		std::cout << (*ite = 1) << std::endl;
	}
	for (auto ite = vi.begin(); ite != vi.end(); ite++)
	{
		std::cout << *ite << std::endl;
	}
	for (auto& ite : vi)
	{
		static int i = 1;
		std::cout << (ite = i++) << std::endl;
	}
	std::cout << std::count_if(vi.begin(), vi.end(), std::not1(std::bind2nd(std::less<int>(), 4)));
	return 0;
}