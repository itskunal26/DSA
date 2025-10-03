#include <iostream>

class Node {

public:

	Node* prev_;
	Node* next_;
	int data_;

	Node(int data) : data_(data) {}

};

//Doubly circular linked list
class DCLL {

private:
	Node* head_;

public:

	DCLL()
	{
		head_ = nullptr;
	}

	//O(1)
	void addFirst(int data)
	{
		Node* newNode = new Node(data);

		if (head_ == nullptr)
		{
			newNode->next_ = newNode;
			newNode->prev_ = newNode;
			head_ = newNode;
		}
		else
		{

			// head_->prev_ is basically a tail

			newNode->next_ = head_;
			newNode->prev_ = head_->prev_;
			head_->prev_->next_ = newNode;
			head_->prev_ = newNode;
			head_ = newNode;
		}
	}

	//O(1)
	void addLast(int data)
	{
		Node* newNode = new Node(data);

		if (head_ == nullptr)
		{
			newNode->next_ = newNode;
			newNode->prev_ = newNode;
			head_ = newNode;
		}
		else
		{
			Node* tail = head_->prev_;

			newNode->prev_ = tail;
			tail->next_ = newNode;
			newNode->next_ = head_;
			head_->prev_ = newNode;

		}
	}

	//O(1)
	void deleteFirst()
	{
		if (head_ == nullptr) return;

		Node* delNode = head_;

		if (head_->next_ == head_)
		{
			head_ = nullptr;
			delete delNode;
			return;
		}

		Node* tail = head_->prev_;
		head_ = head_->next_;

		head_->prev_ = tail;
		tail->next_ = head_; //tail


		delete delNode;
		delNode = nullptr;

	}

	void deleteLast()
	{
		if (head_ == nullptr) return;

		Node* tail = head_->prev_; //tail

		if (head_->next_ == head_)
		{
			head_ = nullptr;
			delete tail;
			return;
		}

		tail->prev_->next_ = head_;
		head_->prev_ = tail->prev_;

		delete tail;
		tail = nullptr;

	}

	void reverseList()
	{
		if (head_ == nullptr || head_->next_ == head_) return;

		Node* current = head_;
		Node* temp = nullptr;
		Node* tail = head_->prev_;

		do
		{

			temp = current->next_;
			current->next_ = current->prev_;
			current->prev_ = temp;
			current = temp;



		} while (head_ != current);

		// Update head to old tail
		head_ = tail;
	}

	void printList()
	{
		if (head_ == nullptr) { std::cout << "Empty List." << std::endl; return; }

		Node* temp = head_;

		do {
			std::cout << "Data: " << temp->data_ << std::endl;
			temp = temp->next_;

		} while (temp != head_);
	}

};


int main()
{
	DCLL obj;

	obj.addFirst(10);
	obj.addFirst(5);
	obj.addFirst(2);

	obj.addLast(20);
	obj.addLast(30);

	//obj.deleteFirst();
	//obj.deleteFirst();

	//obj.deleteLast();

	obj.printList();

	obj.reverseList();

	obj.printList();
}