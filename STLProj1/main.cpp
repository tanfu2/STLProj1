#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

int main()
{
	int ia[6] = { 1,3,2,5,4,6 };
	std::vector<int, std::allocator<int>> vi(ia, ia + 6);

	std::cout << std::count_if(vi.begin(), vi.end(), std::not1(std::bind2nd(std::less<int>(), 4)));
	return 0;
}