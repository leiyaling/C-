#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
//string 的模拟实现
namespace lyl
{
	class string
	{
	public:
		//迭代器
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		//构造函数
		string(const char* str = "")
			:_size(strlen(str)),
			_capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//拷贝构造 s2(s1) ----传统写法
		string(const string& s)
			:_size(s._size),
			_capacity(s._capacity)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		//现代写法
		string(const string& s)
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string tmp(s);
			swap(tmp);
			strcpy(_str, s._str);
		}
		// 赋值重载 s1=s2  ----传统写法
		//s1=s1
		string& operator = (const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		//现代写法
		string& operator=(string s)//传值传参调用拷贝构造
		{
			swap(s);

			return *this;
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
			
		}
		void push_back(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = c;
			++_size;
			_str[_size] = '\0';

		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + len, str);
			_size += len;

		}
		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
			
		}
		const char* c_str() const
		{
			return _str;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];

		}
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];

		}
		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		size_t find(char ch)
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* s, size_t pos = 0)
		{
			const char* ptr = strstr(_str + pos, s);
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}


			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(size_t pos, const char* s)
		{
			assert(pos <= _size);
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + len;
			while (end > pos)
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, s, len);

			return *this;
		}

		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}

			return *this;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
	};

	const size_t string::npos = -1;
}
