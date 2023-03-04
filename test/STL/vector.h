#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

namespace lyl
{
	template<class T>
	class vector 
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector() 
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}
		
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		void swap(vector<T> v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		vector(const vector<T>& v)
		{
			/*_start = newT[v.capacity()];
			_finish = _start + v.size();
			_end_of_storage = _start + capacity();
			memcpy(_start, v._start, v.size() * sizeof(T));*/
			if (v != *this)
			{
				vector<T> tmp(v.begin(), v.end());
				swap(tmp);
			}

		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}
		bool empty()
		{
			return _start == _finish;
		}
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}
		
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		void resize(size_t n,T val=T())
		{
			if (n < size())
			{
				//删除数据
				_finish = _start + n;

			}
			else
			{
				if (n > capacity())
				{
					reserve(n);

					while (_finish != _start + n)
					{
						*_finish = val;
						_finish++;
					}
				}
			}
		}
		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_start)
				{
					for (int i = 0; i < sz; i++)
					{
						//自定义类型，拷贝调用自定义类型的深拷贝赋值
						tmp[i] = _start[i];
					}
					
					//memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;

			}
			
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			//扩容地址改变，迭代器会失效
			//insert中发生扩容，it指向的空间被释放，it本质上就是一个野指针
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity * 2);

				//扩容后更新pos，解决pos失效的问题
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (pos >= end)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator start = pos + 1;
			while (start != _finish)
			{
				*(start - 1) = *start;
				++start;
			}
			--_finish;

			return pos;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		
		
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);

		for (int i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
		v1.pop_back();
		vector<int>::iterator it = v1.begin();

		while (it != v1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v1)
		{
			cout << e << " ";
		}
		
		cout << endl;
	}
}