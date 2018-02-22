#pragma once
#include <cstdlib>

template <class Item>
class CDLL {
private:
	class Node {
	public:
		Node(Item val, Node * prev = NULL, Node *nx = NULL) : value(val), previous(prev), next(nx) {}
		Item value;
		Node *next;
		Node *previous;
	};

public:
	class Iterator { //iterator to allow for searching for 'i'th value
	private: Node* m_ptr;
	public:
		Iterator(Node* ptr) { m_ptr = ptr; }
		void operator ++ () { m_ptr = m_ptr->next; }
		bool operator != (const Iterator& b) { return m_ptr != b.m_ptr; }
		Item getValue() { return m_ptr->value; }
		void setValue(Item val) { m_ptr->value = val; }
	};


public:
	CDLL(); //constructor, creates empty head
	~CDLL(); //deconstructor
	void addData(Item d); //adds new Node to end of list
	Item getData(unsigned int i) const; //will return the data associated in the i-th node of the list
	void incrementHead(); //will advance head to next node
	void decrementHead(); //will move head to previous node
	void swap(unsigned int src, unsigned int dst); //will swap the data in the 2 nodes


	Iterator begin() { return Iterator(m_head); }
	Iterator end() { return Iterator(NULL); }

private:
	Node * m_head;
	Node *m_tail;
	unsigned int m_size;
};

template <class Item> //constructor
CDLL<Item>::CDLL() : m_head(NULL), m_tail(NULL), m_size(0) {}

template <class Item> //deconstructor
CDLL<Item>::~CDLL() {
	Node * here = m_head, *nextNode;
	while (m_size != 0) {
		nextNode = here->next;
		delete here;
		here = nextNode;
		m_size--;
	}
}

template <class Item> //adds new tail
void CDLL<Item>::addData(Item d) {
	if (m_size == 0) { //adds a new head with the value 'd' if list is empty
		m_head = new Node(d, m_head, m_head);
		m_tail = m_head; //sets tail as head
		m_size++;
	}
	else if (m_size == 1) {
		m_tail = m_tail->next = new Node(d, m_head, m_head); //sets a new tail with passed value d, previous address as the old tail
		m_head->next = m_tail;
		m_head->previous = m_tail;
		m_size++;
	}
	else {
		Node * temp = m_tail;
		m_tail = m_tail->next = new Node(d, temp, m_head);
		m_head->previous = m_tail;
		m_size++;
	}
}

template <class Item> //returns desired value based on user input
Item CDLL<Item>::getData(unsigned int i)const {
	if (i == 1) { return m_head->value; } //returns head if users  asks for head (instead of using search algorithm)
	else if (i == m_size) { return m_tail->value; } //returns tail if users  asks for tail (instead of using search algorithm)
	else if (i > 1 && i < m_size) {//search algorithm, searches for the 'i'th value
		int j(0); //stores which value is being checked
		for (CDLL<int>::Iterator k = m_head; k != m_tail; ++k) {
			j++;
			if (j == i) { //checks to see if we are at the right node, and returns value if so
				return k.getValue();
			}
		}
	}
	return 0;
}

template <class Item> //shifts head to the right
void CDLL<Item>::incrementHead() {
	m_tail = m_head;
	m_head = m_head->next;
}

template <class Item>
void CDLL<Item>::decrementHead() { //shifts head to the left
	m_head = m_tail;
	m_tail = m_tail->previous;
	/*m_tail->next = m_head;*/
}

template <class Item> //shifts head to the left
void CDLL<Item>::swap(unsigned int src, unsigned int drc) {
	Item srcValue, drcValue; //stores the values retrived from nodes, so that they can be swapped.

	//get the value from the first item (src):
	Node * here = m_head;
	for (unsigned int k = 1; k < src; k++) here = here->next;
	srcValue = here->value;//this is the source value

	//get value from second item (drc):
	Node * here2 = m_head;
	for (unsigned int k = 1; k < drc; k++) here2 = here2->next;
	drcValue = here2->value;
	here->value = drcValue;
	here2->value = srcValue;
}