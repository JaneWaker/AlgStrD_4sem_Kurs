#include<iostream>
#include<fstream>
#include<string>
#include "Queue.cpp"

void MinOn(int A, int* Array1, int** Array2, int** Array3, int size)
{
	int Min = 1000000;
	for (int i = 0; i < size; i++) {
		if (Array3[A][i] - Array2[A][i] > 0) {
			Min = std::min(Min, Array1[i]);
		}
	}
	if (Min == 1000000) {
		return;
	}
	Array1[A] = Min + 1;
}

void push(int A, int B, int** Array1, int* Array2, int** Array3)
{
	int Min = std::min(Array2[A], Array3[A][B] - Array1[A][B]);
	Array1[A][B] += Min;
	Array1[B][A] = -Array1[A][B];
	Array2[A] -= Min;
	Array2[B] += Min;
}

void Reading(Queue* Queue1, std::ifstream& text) {
	std::string str, Graph;
	int in = 0;
	bool flag = true;
	while (!text.eof()) {
		std::getline(text, str);
		for (unsigned int i = 0; i < str.size(); i++) {
			if (str[i] != ' ')
			{
				Graph += str[i];
				if (str[i + 1] != ' ') {
					throw "Error";
				}
			}
			if (in == 2) {
				break;
			}
			else {
				if (in != 2) {
					for (int j = 0; j < Queue1->get_size(); j++) {
						if (Graph == Queue1->at(j)) {
							flag = false;
						}
					}
					if (flag) {
						Queue1->push(Graph);
					}
					flag = true;
					in++;
					Graph.clear();
				}
				else {
					Graph.clear();
					break;
				}
			}
		}
		Graph.clear();
		in = 0;
	}
	str.clear();
	Graph.clear();
}

void matrix(Queue* Queue1, std::ifstream& text, int** Matrix, int N) {
	std::string str, str2;
	int A = 0, B = 0;
	int in = 0;
	while (!text.eof()) {
		std::getline(text, str);
		for (unsigned int i = 0; i < str.size() + 1; i++) {
			if (str[i] != ' ' && i < str.size())
			{
				str2 += str[i];
			}
			else if (in < 2) {
				for (int j = 0; j < Queue1->get_size(); j++) {
					if (str2 == Queue1->at(j)) {
						if (in == 0) {
							A = j;
						}
						else {
							B = j;
						}
						break;
					}
				}
				in++;
				str2.clear();
			}
			else {
				if (in == 2) {
					Matrix[A][B] = atoi(str2.c_str());
				}
				in++;
				str2.clear();
			}
		}
		in = 0;
		str2.clear();
	}
	str.clear();
	str2.clear();
}

void ProtPred(int size, int** Matrix, int** Matrix2) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Matrix2[i][j] = 0;
		}
	}
	for (int i = 1; i < size; i++) {
		Matrix2[0][i] = Matrix[0][i];
		Matrix2[i][0] = -Matrix[0][i];
	}
	int* Array1 = new int[size];
	Array1[0] = size;
	int* Array2 = new int[size];
	for (int i = 1; i < size; i++) {
		Array2[i] = Matrix2[0][i];
	}
	int i;
	for (i = 1; i < size - 1; i++) {
		if (Array2[i] > 0) {
			break;
		}
	}
	int j;
	for (j = 0; j < size; j++) {
		if (Matrix[i][j] - Matrix2[i][j] > 0 && Array1[i] == Array1[j] + 1) {
			break;
		}
	}
	if (j < size) {
		push(i, j, Matrix2, Array2, Matrix);
	}
	else {
		MinOn(i, Array1, Matrix2, Matrix, size);
	}
}