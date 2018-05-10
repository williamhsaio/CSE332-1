#pragma once
#include "MyList.h"
using namespace std;

template <typename T>
class MySortList : public MyList<T> {
public:
	MySortList() {
		cout << "sorted list default constructor" << endl;

	};
	MySortList(const MySortList<T>& sl) : MySortList<T>(sl) {
		cout << "sorted list copy constructor " << endl;
	}
	/*
	MySortList(const MyList<T>& sl) : MySortList<T>(sl) {
		cout << "sorted list copy constructor " << endl;
	}
	*/
	~MySortList() {
		cout << "destructor : sorted list " << endl;
	}

	
	MySortList<T> & operator=(MySortList<T>&& l) {
		cout << " sort list move assignment " << endl;

		head = l.head;
		tail = l.tail;
		size = l.size;
		l.head = nullptr;
		l.tail = nullptr;
		l.size = 0;
		return *this;

	}
	
	MySortList<T> & operator=(MySortList<T>&l) {
		cout << "sorted list copy assignment " << endl;
		head = l.head;
		tail = l.tail;
		size = l.size;
		return *this;

	}
	


	virtual MySortList<T> & insert(T newValue) {
		ListNode<T> * inserting = new ListNode<T>();
		inserting->value = newValue;
		inserting->next = nullptr;
		if (size == 0) {
			inserting->prev = tail;
			head = inserting;
			tail = inserting;
		}
		else {
			auto i = head;
			while (i != nullptr && newValue > i->value) {
				i = i->next;
			}
			if (i == nullptr) {
				tail->next = inserting;
				inserting->prev = tail;
				tail = inserting;
			}
			else {
				inserting->next = i;
				inserting->prev = i->prev;
				if (i != head) {
					i->prev->next = inserting;
				}
				else {
					head = inserting;
				}
				i->prev = inserting;

			}
		}
		++size;
		return *this;
	};

	virtual void print(ostream &o) {
		if (size >0 ) {
			auto it = head;
			o << "sorted list of size : " << size<< "min value : "<<head->value<< "max value: "<< tail->value << endl;
			while (it != nullptr) {
				o << *it << "<=";
				it = it->next;
			}
			o << "end of sortrd list" << endl;
		}
	};
};