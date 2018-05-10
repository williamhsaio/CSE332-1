#pragma once
#include<iostream>
#include <string>
using namespace std;

template<typename T>
struct ListNode
{
	T value;
	ListNode<T> * next;
	ListNode<T> * prev;
};

template <typename T>
std::ostream & operator<<(ostream &o, const ListNode<T> &n) {
	o << n.value;
	return o;
}

template <typename T>
class MyList {
protected:
	ListNode<T> *head;
	ListNode<T> *tail;
	size_t size;
public:

	MyList() :head(nullptr), tail(nullptr), size(0) {
		std::cout << "list default constructor " << endl;
	};
	
	MyList(const MyList<T>& l){ 
		head = nullptr;
		tail = nullptr;
		size = 0;
		std::cout << "list copy constructor " << std::endl;
		if (!l.isEmpty()) {
			size = l.size;
			head = new ListNode<T>();
			head->next = nullptr;
			head->prev = nullptr;
			head->value = l.head->value;
			tail = head;
			auto lCurr = l.head->next;
			auto prev = head;
			while (lCurr !=nullptr) {
				auto curr = new ListNode<T>();
				curr->value = lCurr->value;
				prev->next = curr;
				curr->next = nullptr;
				curr->prev = prev;
				lCurr = lCurr->next;
				prev = curr;
			}
			tail = prev;
		}
		//return 0;
	};
	
	virtual ~MyList()
	{
		cout << "destructor : list " << endl;
		ListNode<T> *temp = tail;
		while (tail != head) {
			tail = temp->prev;
			delete temp;
			temp = tail;
		}
		delete head;
	};

	MyList<T> & operator=(MyList<T>&l) {
		cout << "list copy assignment " << endl;
		head = l.head;
		tail = l.tail;
		size = l.size;
		return *this;

	}

	
	MyList<T> & operator=(MyList<T>&& l) {
		cout << "list move assignment " << endl;
		
		head = l.head;
		tail = l.tail;
		size = l.size;
		l.head = nullptr;
		l.tail = nullptr;
		l.size = 0;
		return *this;

	}
	
	virtual MyList<T> & insert(T newValue) {
		ListNode<T> * inserting = new ListNode<T>();
		inserting->value = newValue;
		inserting->next = nullptr;
		if (size == 0) {
			inserting->prev = tail;
			head = inserting;
			tail = inserting;
		}
		else {
			inserting->prev = tail;
			tail->next = inserting;
			tail = inserting;
		}
		++size;
		return *this;
	};
	size_t getSize() const {
		return size;
	}
	bool isEmpty()const {
		return (size == 0);
	}

	virtual void print(ostream &o) {
		auto it = head;
		o << "list of size : " << size << endl;
		while (it != nullptr) {
			o << *it << "-->";
			it = it->next;
		}
		o << "end of list" << endl;
	};

};