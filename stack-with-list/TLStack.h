#pragma once
#include <iostream>
using namespace std;

template <class T>
struct TNode {
	T value;
	TNode* next;
};

template <class T>
class TLStack {
private:
	TNode<T>* first;
public:
	TLStack();
	~TLStack();
	TLStack(const TLStack<T>& st);

	TLStack<T>& operator=(const TLStack<T>& st);

	bool operator==(const TLStack<T>& st) const;
	bool operator!=(const TLStack<T>& st) const;

	bool empty() const;
	void clear();

	void push(T value);
	T pop();
	T top() const;

	friend ostream& operator<<(ostream& out, const TLStack<T>& st) {
		TNode<T>* node = st.first;

		out << "[ ";
		while (node != nullptr) {
			out << node->value << " ";
			node = node->next;
		}
		out << "]";

		return out;
	}
};

template <class T>
TLStack<T>::TLStack() : first(nullptr) {}

template <class T>
TLStack<T>::~TLStack() {
	clear();
}

template <class T>
TLStack<T>::TLStack(const TLStack& st) {
	first = nullptr;

	if (!st.empty()) {
		TNode<T>* new_node;
		new_node = new TNode<T>;
		new_node->value = st.first->value;
		new_node->next = nullptr;
		first = new_node;

		TNode<T>* prev_new_node = new_node;
		TNode<T>* other_node = st.first->next;

		while (other_node != nullptr) {
			new_node = new TNode<T>;
			new_node->value = other_node->value;
			new_node->next = nullptr;

			prev_new_node->next = new_node;

			prev_new_node = new_node;
			other_node = other_node->next;
		}
	}
}

template <class T>
TLStack<T>& TLStack<T>::operator=(const TLStack<T>& st) {
	if (this == &st) {
		return *this;
	}

	clear();

	if (!st.empty()) {
		TNode<T>* new_node;
		new_node = new TNode<T>;
		new_node->value = st.first->value;
		new_node->next = nullptr;
		first = new_node;

		TNode<T>* prev_new_node = new_node;
		TNode<T>* other_node = st.first->next;

		while (other_node != nullptr) {
			new_node = new TNode<T>;
			new_node->value = other_node->value;
			new_node->next = nullptr;

			prev_new_node->next = new_node;

			prev_new_node = new_node;
			other_node = other_node->next;
		}
	}
}

template <class T>
bool TLStack<T>::operator==(const TLStack<T>& st) const {
	TNode<T>* node = first;
	TNode<T>* node_other = st.first;

	while (node != nullptr && node_other != nullptr) {
		if (node->value != node_other->value) {
			return false;
		}
		node = node->next;
		node_other = node_other->next;
	}

	if (node != nullptr || node_other != nullptr) {
		return false;
	}

	return true;
}

template <class T>
bool TLStack<T>::operator!=(const TLStack<T>& st) const {
	return !operator==(st);
}

template <class T>
bool TLStack<T>::empty() const {
	return first == nullptr;
}

template <class T>
void TLStack<T>::clear() {
	TNode<T>* node;
	while (first != nullptr) {
		node = first;
		first = first->next;
		delete node;
	}
}

template <class T>
void TLStack<T>::push(T value) {
	TNode<T>* new_node = new TNode<T>();
	new_node->value = value;
	new_node->next = first;
	first = new_node;
}

template <class T>
T TLStack<T>::pop() {
	if (first == nullptr) {
		throw "Can't pop: stack is empty";
	}

	TNode<T>* old_first = first;
	T top_value = old_first->value;

	first = old_first->next;
	delete old_first;

	return top_value;
}

template <class T>
T TLStack<T>::top() const {
	if (first == nullptr) {
		throw "Can't access top element: stack is empty";
	}
	return first->value;
}