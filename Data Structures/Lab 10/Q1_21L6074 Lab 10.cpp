#include "bits-stdc++.h"
using namespace std;
template <typename K, typename V>


class HashNode
{
public:
	V value;
	K key;

	HashNode(K key, V value)
	{
		this->value = value;
		this->key = key;
	}
};

template <typename K, typename V>

class HashMap
{
	HashNode<K, V>** arr;
	int capacity;

	int len;
	HashNode<K, V>* temp;

public:
	HashMap()
	{
		capacity = 20;
		len = 0;
		arr = new HashNode<K, V>*[capacity];

		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;


		temp = new HashNode<K, V>(-1, -1);
	}
	int hashCode(K key)
	{
		return key % capacity;
	}
	void insertNode(K key, V value)
	{
		HashNode<K, V>* temp = new HashNode<K, V>(key, value);

		int index = hashCode(key);

		while (arr[index] != NULL && arr[index]->key != key && arr[index]->key != -1)
		{
			index = index + 1;
			index = index % capacity;
		}


		if (arr[index] == NULL || arr[index]->key == -1)
			len++;
		arr[index] = temp;
	}
	V deleteHash(int key)
	{

		int index = hashCode(key);


		while (arr[index] != NULL)
		{

			if (arr[index]->key == key)
			{
				HashNode<K, V>* temp = arr[index];

				arr[index] = temp;

				len--;
				return temp->value;
			}
			index = index + 1;
			index = index % capacity;
		}

		return NULL;
	}
	V get(int key)
	{
		int index = hashCode(key);
		int counter = 0;


		while (arr[index] != NULL)
		{

			if (counter++ > capacity)
				return NULL;


			if (arr[index]->key == key)
				return arr[index]->value;
			index = index + 1;
			index = index % capacity;
		}


		return NULL;
	}
	int sizeofMap()
	{
		return len;
	}
	bool isEmpty()
	{
		return len == 0;
	}
	void print()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] != NULL && arr[i]->key != -1)
				cout << "key = " << arr[i]->key << "  value = " << arr[i]->value << "\n";
		}
	}
};

int main()
{
	HashMap<int, int>* h = new HashMap<int, int>;
	h->insertNode(1, 1);
	h->insertNode(2, 2);
	h->insertNode(2, 3);
	h->print();
	cout << "Testing get function = " << h->get(2);
	cout << "\nSize of hash map is " << h->sizeofMap();
	cout << "\nDeleting Node " << h->deleteHash(2);
	cout << "\nSize of after deletion is " << h->sizeofMap();
	if (!h->isEmpty())
	{
		cout << "\nHash map is not empty\n";
	}
	else
	{
		cout << "\nHash map is empty\n";
	}

	system("pause");
	return 0;
}