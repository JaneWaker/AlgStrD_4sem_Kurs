#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include "Queue.cpp"
#include "ProtPred.cpp"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file;
	file.open("in.txt", std::ios::in);
	Queue* Queue1 = new Queue;
	Reading(Queue1, file);
	int size = Queue1->get_size();
	int** Matrix, ** Matrix2;
	Matrix = new int* [size];
	Matrix2 = new int* [size];
	for (int i = 0; i < size; i++) {
		Matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		Matrix2[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Matrix[i][j] = 0;
		}
	}
	file.clear();
	file.seekg(0);
	matrix(Queue1, file, Matrix, size);
	file.close();
	ProtPred(size, Matrix, Matrix2);
	int path = 0;
	for (int i = 0; i < size; i++) {
		if (Matrix[0][i]) {
			path += Matrix2[0][i];
		}
	}
	std::cout << "Максимальный поток:" << max(path, 0);

}