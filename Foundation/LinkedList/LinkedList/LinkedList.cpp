// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class Node {
private:
	int _data;
	Node* _next = nullptr;

public:

	Node(int data)
	{
		_data = data;
	}

	int get_data()
	{
		return _data;
	}

	void set_data(int data) { _data = data; }

	Node* get_next() { return _next; }

	void set_next(Node* next) { _next = next; }

};


class SLL {
private:

	Node* _head;

public:

	SLL()
	{
		this->_head = nullptr;
	}

	//Time and Space complexity 
	// O(n) and O(1)
	void insert_node(int data)
	{
		Node* newNode = new Node(data);
		newNode->set_next(nullptr);

		if (this->_head == nullptr)
		{
			this->_head = newNode;
		}
		else
		{
			Node* temp = this->_head;

			while (temp->get_next() != nullptr) // n number of iterations
			{
				temp = temp->get_next();
			}
			temp->set_next(newNode);
		}
	}

	//Time and Space complexity 
	// O(1) and O(1)
	void insert_node_at_beginning(int data)
	{
		Node* newNode = new Node(data);
		newNode->set_next(nullptr);

		if (this->_head == nullptr)
		{
			this->_head = newNode;
		}
		else
		{
			newNode->set_next(this->_head);
			this->_head = newNode;
		}

	}

	void insert_at_index(int data, int idx)
	{
		if (_head == nullptr) return;

		int pos = 0;
		Node* newNode = new Node(data);
		Node* temp = _head;

		while (temp != nullptr && pos < idx - 1)
		{
			temp = temp->get_next();
			pos++;
		}

		newNode->set_next(temp->get_next());
		temp->set_next(newNode);

	}

	//Time and Space complexity 
	// O(n) and O(1)
	void delete_last_node()
	{
		//Empty List
		if (this->_head == nullptr)
		{
			return;
		}

		//Single Node
		if (this->_head->get_next() == nullptr)
		{
			delete this->_head;
			this->_head = nullptr;
			return;
		}

		Node* temp = this->_head;

		if (temp != nullptr)
		{
			while (temp->get_next()->get_next() != nullptr)
			{
				temp = temp->get_next();
			}

			Node* delNode = temp->get_next();
			temp->set_next(nullptr);

			delete delNode;
			delNode = nullptr;
		}
	}

	//Time and Space complexity 
	// O(1) and O(1)
	void delete_first()
	{
		if (this->_head == nullptr) { return; }

		Node* delNode = this->_head;
		this->_head = this->_head->get_next();

		delete delNode;

	}

	//
	void delete_at_index(int idx)
	{
		if (_head == nullptr || idx < 0) return;

		// Case 1: delete first node
		if (idx == 0) {
			Node* delNode = _head;
			_head = _head->get_next();
			delete delNode;
			return;
		}

		Node* temp = _head;
		int pos = 0;

		while (temp != nullptr && pos < idx - 1)
		{
			temp = temp->get_next();
			pos++;
		}

		// If index is out of bounds
		if (temp == nullptr || temp->get_next() == nullptr) return;

		Node* delNode = temp->get_next();
		temp->set_next(delNode->get_next());

		delete delNode;
		delNode = nullptr;
	}

	void reverse_list()
	{
		if (_head == nullptr) return;

		Node* current = _head;
		Node* prev = nullptr;
		Node* next = nullptr;


		while (current != nullptr)
		{
			next = current->get_next();
			current->set_next(prev);
			prev = current;
			current = next;
						
			
		}

		_head = prev;
	}


	bool cycle_detection()
	{
		Node* fast = _head->get_next();
		Node* slow = _head;

		while (fast != nullptr && fast->get_next() != nullptr)
		{
			if (slow == fast)
			{
				return true;
			}
			
			slow = slow->get_next();
			fast = fast->get_next()->get_next();
		}

		return false;
	}


	//Time and Space complexity 
	// O(n) and O(1)
	void print_list()
	{
		Node* temp = this->_head;

		while (temp != nullptr)
		{
			std::cout << "Data: " << temp->get_data() << std::endl;
			temp = temp->get_next();
		}
	}


	void print_reverse_list(Node* head)
	{
		if (head == nullptr) return;

		print_reverse_list(head->get_next());

		std::cout << head->get_data();
	}

};


int main()
{
	SLL obj;

	obj.insert_node(10);
	obj.insert_node(30);
	obj.insert_node(20);

	obj.insert_node_at_beginning(5);
	obj.insert_node_at_beginning(2);

	obj.insert_at_index(15, 3);

	//obj.print_list();

	obj.reverse_list();

	//obj.delete_last_node();

	//obj.delete_first();

	//obj.delete_at_index(3);

	obj.print_list();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
