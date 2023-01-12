#pragma once
#include <iostream>
#include <string>

template <typename T> class Node {
public:
	//data
	std::string key;
	T value;
	Node* child;

	//constructors
	Node() {
		this->key = "";
		this->value = NULL;
		this->child = NULL;
	}
	Node(std::string key, T value) {
		this->key = key;
		this->value = value;
		this->child = NULL;
	}

	//functions
	std::string print() {
		return this->key + " -> " + std::to_string(this->value) + "\n";
	}
	std::string printString() {
		return this->key + " -> " + this->value + "\n";
	}
};

template<typename T> class SLL {
public:
	//data
	Node<T>* head;

	//constructor
	SLL() {
		this->head = NULL;
	}

	//functions
	std::string print() {
		std::string result = "";
		if (this->head != NULL) {
			Node<T>* tmp = head;
			while (tmp != NULL) {
				result += tmp->print();
				tmp = tmp->child;
			}
			result += "\n";
		}
		return result;
	}
	std::string printString() {
		std::string result = "";
		if (this->head != NULL) {
			Node<T>* tmp = head;
			while (tmp != NULL) {
				result += tmp->printString();
				tmp = tmp->child;
			}
			result += "\n";
		}
		return result;
	}
	Node<T>* search(std::string key) {
		Node<T>* tmp = head;
		if (tmp == NULL)return NULL;
		while (tmp != NULL) {
			if (tmp->key == key)return tmp;
			tmp = tmp->child;
		}
		return NULL;
	}
	int add(std::string key, T value) {
		Node<T>* newNode = new Node<T>(key, value);

		if (search(key) == NULL) {
			if (this->head == NULL) head = newNode;
			else {
				Node<T>* tmp = head;
				while (tmp->child != NULL) tmp = tmp->child;
				tmp->child = newNode;
			}
			return 1;
		}
		else {
			Node<T>* tmp = search(key);
			tmp->value = value;
			return 0;
		}
	}
	int del(std::string key) {
		if (search(key) == NULL)return NULL;
		else {
			Node<T>* tmp = search(key);
			if (tmp == head) { this->head = tmp->child; return 1; }
			else {
				Node<T>* parent = head;
				while (parent->child != tmp)  parent = parent->child;
				parent->child = tmp->child;
				return 1;
			}
			return NULL;
		}
	}
};























