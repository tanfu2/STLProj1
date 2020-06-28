#include<iostream>

namespace myspace1
{
	template<class T>
	inline const T& max(const T& a, const T& b)
	{
		return a > b ? a : b;
	}

	template<class T,class Compare>
	inline const T& max(const T& a, const T& b,Compare comp)
	{
		return comp(a, b) ? a : b;
	}
	
	bool Strlen(const std::string& s1, const std::string& s2)
	{
		return s1.size() > s2.size();
	}
}
namespace myspace2
{
	template<typename T> struct test
	{
		void t()
		{
			std::cout << "I am generalization" << std::endl;
		}
	};
	template<> struct test<int>
	{
		void t(int x)
		{
			std::cout << "I am specialization(int=" << x << ")" << std::endl;
		}
	};
}
int main()
{
	std::string s1 = "11111";
	std::string s2 = "2222";
	std::cout << myspace1::max(s1, s2, myspace1::Strlen) << std::endl;
	myspace2::test<char> t1; t1.t();
	myspace2::test<int> t2; t2.t(1);
	return 0;
}