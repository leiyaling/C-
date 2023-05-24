#pragma once
#include <vector>
#include <string>
using namespace std;
template<size_t N>
class bitset
{
public:
	bitset()
	{
		_bits.resize(N / 8 + 1, 0);
	}
	void set(size_t x)
	{
		size_t i = x / 8;
		size_t ij = x % 8;
		_bit[i] |= (1 << j);
	}
	void reset(size_t x)
	{
		size_t i = x / 8;
		size_t ij = x % 8;
		_bits[i] &= ~(1 << j);
	}
	//检测某个数在不在
	bool get(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;

		return _bits[i] & (1 << j);
	}
private:
	vector<char> _bits;
};
void test_bitset()
{
	bitset<100> bs;
	bs.set(10);
}

template<size_t N>
class twobitset
{
public:
	void set(size_t x)
	{
		// 00 -> 01
		if (_bs1.test(x) == false
			&& _bs2.test(x) == false)
		{
			_bs2.set(x);
		}
		else if (_bs1.test(x) == false
			&& _bs2.test(x) == true)
		{
			// 01 -> 10
			_bs1.set(x);
			_bs2.reset(x);
		}
		// 10
	}
	//打印出只出现一次的值（第一个位图上该数的比特位为0，第二个位图上该数的比特位为1）
	void Print()
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (_bs2.test(i))
			{
				cout << i << endl;
			}
		}
	}

public:
	bitset<N> _bs1;
	bitset<N> _bs2;
};
struct BKDRHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 31;
		}

		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); i++)
		{
			size_t ch = s[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};


struct DJBHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

// N最多会插入key数据的个数
template<size_t N,
	class K = string,
	class Hash1 = BKDRHash,
	class Hash2 = APHash,
	class Hash3 = DJBHash>
class BloomFilter
{
public:
	void set(const K& key)
	{
		size_t len = N * _X;
		size_t hash1 = Hash1()(key) % len;
		_bs.set(hash1);

		size_t hash2 = Hash2()(key) % len;
		_bs.set(hash2);

		size_t hash3 = Hash3()(key) % len;
		_bs.set(hash3);
	}

	bool test(const K& key)
	{
		size_t len = N * _X;

		size_t hash1 = Hash1()(key) % len;
		if (!_bs.test(hash1))
		{
			return false;
		}

		size_t hash2 = Hash2()(key) % len;
		if (!_bs.test(hash2))
		{
			return false;
		}

		size_t hash3 = Hash3()(key) % len;
		if (!_bs.test(hash3))
		{
			return false;
		}
		return true;
	}
private:
	static const size_t _X = 6;
	bitset<N* _X> _bs;
};