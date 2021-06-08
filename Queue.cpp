#include <iostream>
#include <string>
#include <fstream>
#ifndef Queue_H
#define Queue_H
class Queue
{
private:
	class NodeQ {
	public:
		NodeQ* next;
		std::string Graph;
		NodeQ(NodeQ* next = NULL)
		{
			this->next = next;
		};
		NodeQ(std::string  Graph, NodeQ* next = NULL)
		{
			this->Graph = Graph;
			this->next = next;
		};
		~NodeQ() {}
	};
public:
	NodeQ* first;
	NodeQ* last;
	unsigned int size;
	Queue() {
		last = NULL;
		first = NULL;
		size = 0;
	}
	~Queue() {
		clear();
	}
	int get_size() {
		return size;
	}
	void clear() {
		while (size != 0)
		{
			pop();
		}
	}
	void push(std::string Graph) {
		if (size == 0) {
			first = new NodeQ(Graph);
			last = first;
		}
		else {
			last->next = new NodeQ(Graph);
			last = last->next;
		}
		size++;
	}
	void pop() {
		if (size == 0) {
			return;
		}
		if (size == 1) {
			delete first;
			deletel();
		}
		else {
			NodeQ* current = first;
			first = first->next;
			delete current;
		}
		size--;
	}
	void deletel()
	{
		first = NULL;
		last = NULL;
	}
	std::string at(unsigned int index)
	{
		if (index >= size) {
			throw "Error";
		}
		else {
			NodeQ* current = first;
			unsigned int i = 0;
			while (i != index) {
				current = current->next;
				i++;
			}
			return current->Graph;
		}
	}
};
#endif