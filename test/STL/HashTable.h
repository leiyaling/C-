#pragma once
#include <vector>
using namespace std;

namespace OpenAddress
{

	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K, class V>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			// �������ӳ���0.7������
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newht;
				newht._tables.resize(newsize);

				// �����ɱ�����ӳ�䵽�±�
				for (auto& data : _tables)
				{
					if (data._state == EXIST)
					{
						newht.Insert(data._kv);
					}
				}

				_tables.swap(newht._tables);
			}

			size_t hashi = kv.first % _tables.size();

			// ����̽��
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state == EXIST)
			{
				index = hashi + i;
				index %= _tables.size();
				++i;
			}

			_tables[index]._kv = kv;
			_tables[index]._state = EXIST;
			_n++;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return false;
			}

			size_t hashi = key % _tables.size();

			// ����̽��
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._state == EXIST
					&& _tables[index]._kv.first == key)
				{
					return &_tables[index];
				}

				index = hashi + i;
				index %= _tables.size();
				++i;

				// ����Ѿ�����һȦ����ô˵��ȫ�Ǵ���+ɾ��
				if (index == hashi)
				{
					break;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0; // �洢�����ݸ���

	};
}