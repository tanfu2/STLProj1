#include<iostream>
#include<array>
#include<ctime>
#include<cstdlib>
#include <vector>
#include <string>
#include <list>
#include<forward_list>
#include<deque>
#include<set>
#include<map>
#include <unordered_set>
#include <unordered_map>

namespace arrayTest
{
#define ASIZE 500000
	typedef int testsize;
	std::array<testsize, ASIZE> aTest;
	int Compare(const void* arg1, const void* arg2)
	{
		return (*(testsize*)arg1 - *(testsize*)arg2);
	}
	void TestArray()
	{
		std::cout << "--Test Array--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < ASIZE; i++)
		{
			aTest[i] = rand();
		}
		std::cout << "array.randtime=" << clock() - tStart << std::endl;
		std::cout << "array.size()=" << aTest.size() << std::endl;
		std::cout << "array.front()=" << aTest.front() << std::endl;
		std::cout << "array.back()=" << aTest.back() << std::endl;
		std::cout << "array.data()=" << aTest.data() << std::endl;

		tStart = clock();
		qsort(aTest.data(), ASIZE, sizeof(testsize), Compare);
		std::cout << "qsort time=" << clock() - tStart << std::endl;

		tStart = clock();
		testsize* tItem = (testsize*)bsearch(&aTest[1000], aTest.data(), ASIZE, sizeof(testsize), Compare);
		std::cout << "bsearch time=" << clock() - tStart << std::endl;

		if (tItem != nullptr)
		{
			std::cout << aTest[1000] << " found it:" << *tItem << std::endl;
		}
		else
		{
			std::cout << "Not found!" << std::endl;
		}
	}
}
namespace vectorTest
{
	typedef std::string testsize;
	std::vector<testsize, std::allocator<testsize>> vTest;
	int Compare(const void* arg1, const void* arg2)
	{
		return ((*(testsize*)arg1)[0] - (*(testsize*)arg2)[0]);
	}
	void TestVector(int& values)
	{
		std::cout << "--Test Vector--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				vTest.push_back(std::to_string(rand()));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "vector.randtime=" << clock() - tStart << std::endl;
		std::cout << "vector.size()=" << vTest.size() << std::endl;
		std::cout << "vector.front()=" << vTest.front() << std::endl;
		std::cout << "vector.back()=" << vTest.back() << std::endl;
		std::cout << "vector.data()=" << vTest.data() << std::endl;
		std::cout << "vector.capacity()=" << vTest.capacity() << std::endl;
		{
			tStart = clock();
			std::vector<testsize, std::allocator<testsize>>::iterator it = find(vTest.begin(),
				vTest.end(), vTest.at(values / 2));
			std::cout << "find time:" << clock() - tStart;
			if (it != vTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
		{
			tStart = clock();
			std::sort(vTest.begin(), vTest.end());
			std::cout << "sort time:" << clock() - tStart << std::endl;

			tStart = clock();
			testsize* tItem = (testsize*)bsearch(&vTest.at(values / 2), vTest.data(),
				vTest.size(), sizeof(testsize), Compare);
			std::cout << "bsearch time:" << clock() - tStart << std::endl;;
			if (tItem != nullptr)
			{
				std::cout << "Found it:" << vTest.at(values / 2) << "=" << *tItem << std::endl;
			}
			else
			{
				std::cout << vTest.at(values / 2) << " Not found!" << std::endl;
			}
		}
	}
}
namespace listTest
{
	typedef std::string testsize;
	std::list<testsize, std::allocator<testsize>> lTest;
	void TestList(int& values)
	{
		std::cout << "--Test List--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				lTest.push_back(std::to_string(rand()));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "list.randtime=" << clock() - tStart << std::endl;
		std::cout << "list.size()=" << lTest.size() << std::endl;
		std::cout << "list.max_size()=" << lTest.max_size() << std::endl;
		std::cout << "list.front()=" << lTest.front() << std::endl;
		std::cout << "list.back()=" << lTest.back() << std::endl;
		{
			tStart = clock();
			std::list<testsize, std::allocator<testsize>>::iterator it = find(lTest.begin(),
				lTest.end(), lTest.back());
			std::cout << "find time:" << clock() - tStart;
			if (it != lTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
		{
			tStart = clock();
			lTest.sort();
			std::cout << "sort time:" << clock() - tStart << std::endl;
		}
	}
}
namespace forwradlistTest
{
	typedef std::string testsize;
	std::forward_list<testsize, std::allocator<testsize>> flTest;
	void TestForwardList(int& values)
	{
		std::cout << "--Test Forward_List--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				flTest.push_front(std::to_string(rand()));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "forward_list.randtime=" << clock() - tStart << std::endl;
		std::cout << "forward_list.max_size()=" << flTest.max_size() << std::endl;
		std::cout << "forward_list.front()=" << flTest.front() << std::endl;
		{
			tStart = clock();
			std::forward_list<testsize, std::allocator<testsize>>::iterator it = find(flTest.begin(),
				flTest.end(), flTest.front());
			std::cout << "find time:" << clock() - tStart;
			if (it != flTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
		{
			tStart = clock();
			flTest.sort();
			std::cout << "sort time:" << clock() - tStart << std::endl;
		}
	}
}
namespace dequeTest
{
	typedef std::string testsize;
	std::deque<testsize, std::allocator<testsize>> dTest;
	void TestDeque(int& values)
	{
		std::cout << "--Test Deque--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				dTest.push_back(std::to_string(rand()));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "deque.randtime=" << clock() - tStart << std::endl;
		std::cout << "deque.size()=" << dTest.size() << std::endl;
		std::cout << "deque.max_size()=" << dTest.max_size() << std::endl;
		std::cout << "deque.front()=" << dTest.front() << std::endl;
		std::cout << "deque.back()=" << dTest.back() << std::endl;
		{
			tStart = clock();
			std::deque<testsize, std::allocator<testsize>>::iterator it = find(dTest.begin(),
				dTest.end(), dTest[values / 2]);
			std::cout << "find time:" << clock() - tStart;
			if (it != dTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
		{
			tStart = clock();
			std::sort(dTest.begin(), dTest.end());
			std::cout << "sort time:" << clock() - tStart << std::endl;
		}
	}
}
namespace multisetTest
{
	typedef std::string testsize;
	std::multiset<testsize> msTest;
	void TestMultiSet(int& values)
	{
		std::cout << "--Test MultiSet--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				msTest.insert(std::to_string(rand()));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "multiset.randtime=" << clock() - tStart << std::endl;
		std::cout << "multiset.size()=" << msTest.size() << std::endl;
		std::cout << "multiset.max_size()=" << msTest.max_size() << std::endl;
		{
			tStart = clock();
			std::multiset<testsize>::iterator it = find(msTest.begin(),
				msTest.end(), testsize("23456"));
			std::cout << "find time:" << clock() - tStart;
			if (it != msTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
		{
			tStart = clock();
			std::multiset<testsize>::iterator it = msTest.find(testsize("23456"));
			std::cout << "multiset find time:" << clock() - tStart << std::endl;
			if (it != msTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
	}
}
namespace multimapTest
{
	typedef std::string testsize;
	std::multimap<int, testsize> mmTest;
	void TestMultiMap(int& values)
	{
		std::cout << "--Test MultiMap--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				mmTest.insert(std::make_pair(i, std::to_string(rand())));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "multimap.randtime=" << clock() - tStart << std::endl;
		std::cout << "multimap.size()=" << mmTest.size() << std::endl;
		std::cout << "multimap.max_size()=" << mmTest.max_size() << std::endl;
		{
			tStart = clock();
			std::multimap<int, testsize>::iterator it = mmTest.find(values / 2);
			std::cout << "multimap find time:" << clock() - tStart << std::endl;
			if (it != mmTest.end())
			{
				std::cout << " found it:" << it->first << "-" << it->second << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
	}
}
namespace unordered_multisetTest
{
	typedef std::string testsize;
	std::unordered_multiset<testsize> umTest;
	void TestUnordered_Multiset(int& values)
	{
		std::cout << "--Test Unordered_Multiset--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				umTest.insert(std::to_string(rand()));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "unordered_multiset.randtime=" << clock() - tStart << std::endl;
		std::cout << "unordered_multiset.size()=" << umTest.size() << std::endl;
		std::cout << "unordered_multiset.max_size()=" << umTest.max_size() << std::endl;
		std::cout << "unordered_multiset.bucket_count()=" << umTest.bucket_count() << std::endl;
		std::cout << "unordered_multiset.load_factor()=" << umTest.load_factor() << std::endl;
		std::cout << "unordered_multiset.max_load_factor()=" << umTest.max_load_factor() << std::endl;
		std::cout << "unordered_multiset.max_bucket_count()=" << umTest.max_bucket_count() << std::endl;
		for (int i = 0; i < 100; i++)
		{
			if (umTest.bucket_size(i)!=0)
			{
				std::cout << "bucket #" << i << " has " << umTest.bucket_size(i) << " elements" << std::endl;
			}	
		}
		{
			tStart = clock();
			auto it = std::find(umTest.begin(), umTest.end(), testsize("23456"));
			std::cout << "std::find time:" << clock() - tStart << std::endl;
			if (it != umTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
		{
			tStart = clock();
			auto it = umTest.find(testsize("23456"));
			std::cout << "unordered_multiset find time:" << clock() - tStart << std::endl;
			if (it != umTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
	}
}
namespace unordered_multimapTest
{
	typedef std::string testsize;
	std::unordered_multimap<int, testsize> umTest;
	void TestUnordered_MultiMap(int& values)
	{
		std::cout << "--Test Unordered_Multimap--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				umTest.insert(std::make_pair(i, std::to_string(rand())));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "unordered_multimap.randtime=" << clock() - tStart << std::endl;
		std::cout << "unordered_multimap.size()=" << umTest.size() << std::endl;
		std::cout << "unordered_multimap.max_size()=" << umTest.max_size() << std::endl;
		{
			tStart = clock();
			std::unordered_multimap<int, testsize>::iterator it = umTest.find(values / 2);
			std::cout << "unordered_multimap find time:" << clock() - tStart << std::endl;
			if (it != umTest.end())
			{
				std::cout << " found it:" << it->first << "-" << it->second << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
	}
}
namespace setTest
{
	typedef std::string testsize;
	std::set<testsize> sTest;
	void TestSet(int& values)
	{
		std::cout << "--Test Set--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				sTest.insert(std::to_string(rand()));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "set.randtime=" << clock() - tStart << std::endl;
		std::cout << "set.size()=" << sTest.size() << std::endl;
		std::cout << "set.max_size()=" << sTest.max_size() << std::endl;
		{
			tStart = clock();
			std::set<testsize>::iterator it = find(sTest.begin(),
				sTest.end(), testsize("23456"));
			std::cout << "find time:" << clock() - tStart;
			if (it != sTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
		{
			tStart = clock();
			std::set<testsize>::iterator it = sTest.find(testsize("23456"));
			std::cout << "set find time:" << clock() - tStart << std::endl;
			if (it != sTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
	}
}
namespace mapTest
{
	typedef std::string testsize;
	std::map<testsize, int> mTest;
	void TestMap(int& values)
	{
		std::cout << "--Test Map--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				mTest.insert(std::pair<testsize, int>(std::to_string(rand()), i));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "map.randtime=" << clock() - tStart << std::endl;
		std::cout << "map.size()=" << mTest.size() << std::endl;
		std::cout << "map.max_size()=" << mTest.max_size() << std::endl;
		{
			tStart = clock();
			std::map<testsize, int>::iterator it = mTest.find(testsize("23456"));
			std::cout << "map find time:" << clock() - tStart << std::endl;
			if (it != mTest.end())
			{
				std::cout << " found it:" << it->first << "-" << it->second << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
	}
}
namespace unordered_setTest
{
	typedef std::string testsize;
	std::unordered_set<testsize> usTest;
	void TestUnordered_set(int& values)
	{
		std::cout << "--Test Unordered_set--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				usTest.insert(std::to_string(rand()));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "unordered_set.randtime=" << clock() - tStart << std::endl;
		std::cout << "unordered_set.size()=" << usTest.size() << std::endl;
		std::cout << "unordered_set.max_size()=" << usTest.max_size() << std::endl;
		std::cout << "unordered_set.bucket_count()=" << usTest.bucket_count() << std::endl;
		std::cout << "unordered_set.load_factor()=" << usTest.load_factor() << std::endl;
		std::cout << "unordered_set.max_load_factor()=" << usTest.max_load_factor() << std::endl;
		std::cout << "unordered_set.max_bucket_count()=" << usTest.max_bucket_count() << std::endl;
		for (int i = 0; i < 100; i++)
		{
			if (usTest.bucket_size(i) != 0)
			{
				std::cout << "bucket #" << i << " has " << usTest.bucket_size(i) << " elements" << std::endl;
			}
		}
		{
			tStart = clock();
			auto it = std::find(usTest.begin(), usTest.end(), testsize("23456"));
			std::cout << "std::find time:" << clock() - tStart << std::endl;
			if (it != usTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
		{
			tStart = clock();
			auto it = usTest.find(testsize("23456"));
			std::cout << "unordered_set find time:" << clock() - tStart << std::endl;
			if (it != usTest.end())
			{
				std::cout << " found it:" << *it << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
	}
}
namespace unordered_mapTest
{
	typedef std::string testsize;
	std::unordered_map<testsize, int> umTest;
	void TestUnordered_Map(int& values)
	{
		std::cout << "--Test Unordered_map--" << std::endl;
		srand((unsigned)time(nullptr));
		clock_t tStart = clock();
		for (int i = 0; i < values; i++)
		{
			try
			{
				umTest.insert(std::make_pair(std::to_string(rand()), i));
			}
			catch (const std::exception& p)
			{
				std::cout << "i = " << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "unordered_map.randtime=" << clock() - tStart << std::endl;
		std::cout << "unordered_map.size()=" << umTest.size() << std::endl;
		std::cout << "unordered_map.max_size()=" << umTest.max_size() << std::endl;
		{
			tStart = clock();
			std::unordered_multimap<testsize, int>::iterator it = umTest.find(testsize("23456"));
			std::cout << "unordered_map find time:" << clock() - tStart << std::endl;
			if (it != umTest.end())
			{
				std::cout << " found it:" << it->first << "-" << it->second << std::endl;
			}
			else
			{
				std::cout << "Not found!" << std::endl;
			}
		}
	}
}
int main()
{
	std::cout << "-------1.array" << std::endl;
	std::cout << "-------2.vector" << std::endl;
	std::cout << "-------3.list" << std::endl;
	std::cout << "-------4.forward_list" << std::endl;
	std::cout << "-------5.deque" << std::endl;
	std::cout << "-------6.multiset" << std::endl;
	std::cout << "-------7.multimap" << std::endl; 
	std::cout << "-------8.unordered_multiset" << std::endl;
	std::cout << "-------9.unordered_multimap" << std::endl;
	std::cout << "-------10.set" << std::endl;
	std::cout << "-------11.map" << std::endl;
	std::cout << "-------12.unordered_set" << std::endl;
	std::cout << "-------13.unordered_map" << std::endl;
	std::cout << "\nyour choice:";
	int c = 0; std::cin >> c;
	switch (c)
	{
		case 1:
		{
			arrayTest::TestArray();
			break;
		}
		case 2:
		{
			int i = 0;
			std::cin >> i;
			vectorTest::TestVector(i);
			break;
		}
		case 3:
		{
			int i = 0;
			std::cin >> i;
			listTest::TestList(i);
			break;
		}
		case 4:
		{
			int i = 0;
			std::cin >> i;
			forwradlistTest::TestForwardList(i);
			break;
		}
		case 5:
		{
			int i = 0;
			std::cin >> i;
			dequeTest::TestDeque(i);
			break;
		}
		case 6:
		{
			int i = 0;
			std::cin >> i;
			multisetTest::TestMultiSet(i);
			break;
		}
		case 7:
		{
			int i = 0;
			std::cin >> i;
			multimapTest::TestMultiMap(i);
			break;
		}
		case 8:
		{
			int i = 0;
			std::cin >> i;
			unordered_multisetTest::TestUnordered_Multiset(i);
			break;
		}
		case 9:
		{
			int i = 0;
			std::cin >> i;
			unordered_multimapTest::TestUnordered_MultiMap(i);
			break;
		}
		case 10:
		{
			int i = 0;
			std::cin >> i;
			setTest::TestSet(i);
			break;
		}
		case 11:
		{
			int i = 0;
			std::cin >> i;
			mapTest::TestMap(i);
			break;
		}
		case 12:
		{
			int i = 0;
			std::cin >> i;
			unordered_setTest::TestUnordered_set(i);
			break;
		}
		case 13:
		{
			int i = 0;
			std::cin >> i;
			unordered_mapTest::TestUnordered_Map(i);
			break;
		}
	}
	return 0;
}