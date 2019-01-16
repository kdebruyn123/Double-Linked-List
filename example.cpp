
#include <string>
#include <iostream>

template <typename T>
class node
{
public:
	node(T inValue)
	{
		value = inValue;
		nextNode = nullptr;
		prevNode = nullptr;
	}
	~node()
	{
		nextNode = nullptr;
		prevNode = nullptr;
	}

	node<T>* nextNode;
	node<T>* prevNode;
	T value;
};

template <typename T>
class linked_list
{
public:
	linked_list()
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
	}

	void add(T value)
	{
		node<T>* tempPtr = head;

		if (head == nullptr)
		{
			head = new node<T>(value);
			tail = head;
			count++;
			return;
		}
		else
		{
			/*while (tempPtr->nextNode != nullptr)
				tempPtr = tempPtr->nextNode;
			node<T>* tempNode = new node<T>(value);
			tempPtr->nextNode = tempNode;
			tempNode->prevNode = tempPtr;
			tail = tempNode;*/

			tempPtr = tail;
			node<T>* tempNode = new node<T>(value);
			tempNode->prevNode = tail;
			tail->nextNode = tempNode;
			tail = tempNode;
			(count)++;
		}
	}

	void print_list()
	{
		node<T>* tempPtr = head;
		if (tempPtr == nullptr)
			return;

		while (tempPtr != nullptr)
		{
			std::cout << tempPtr->value << std::endl;
			tempPtr = tempPtr->nextNode;
		}

	}

	void print_list_reversed()
	{
		node<T>* tempPtr = tail;
		if (tempPtr == nullptr)
			return;

		while (tempPtr != nullptr)
		{
			std::cout << tempPtr->value << std::endl;
			tempPtr = tempPtr->prevNode;
		}
	}

	void print_list_size()
	{
		std::cout << "The list has: " << count << " items inside." << std::endl;
	}

	void deleteHead()
	{
		if (head == nullptr)
			return;
		 
		node<T>* tempPtr = head;
		head = head->nextNode;
		head->prevNode = nullptr;
		delete tempPtr;
	}
	void deleteTail()
	{
		node<T>* tempPtr = tail;
		tail = tail->prevNode;
		tail->nextNode = nullptr;
		delete tempPtr;
	}

	void deleteMiddle(int position)
	{
		node<T> *current;
		int i;
		int pos = position;

		current = head;
		for (i = 1; i<position && current != NULL; i++)
		{
			current = current->nextNode;
		}

		if (position == 1)
		{
			deleteHead();
		}
		  else if (current == tail)
		        {
					deleteTail();
				}
		         else if (current != NULL)
					  {
						current->prevNode->nextNode = current->nextNode;
						current->nextNode->prevNode = current->prevNode;

						free(current);

						std::cout << "The node at position " << pos << " was deleted.\n";
					  }
						else
							{
								std::cout<<"The position does not exist\n";
							}

	}

private:
	node<T>* head;
	node<T>* tail;
	size_t count;
};

int main()
{
	int pos;

	linked_list<int> ll;
	ll.add(1);
	ll.add(2);
	ll.add(3);
	ll.add(4);
	ll.print_list_reversed();
	ll.print_list_size();

	//std::cout << "The first node deleted:" << std::endl;
	//ll.deleteHead();
	//ll.print_list();

	//std::cout << "The last node deleted:" << std::endl;
	//ll.deleteTail();
	//ll.print_list();

	std::cout << "Please enter the position of the node you want to delete: " << std::endl;
	std::cin >> pos;
	ll.deleteMiddle(pos);
	ll.print_list();
}
