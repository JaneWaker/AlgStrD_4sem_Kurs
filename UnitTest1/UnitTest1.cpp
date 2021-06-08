#include "CppUnitTest.h"
#include  "..\AlgStrD_4sem_Kurs\ProtPred.cpp"
#include  "..\AlgStrD_4sem_Kurs\Queue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Queue* Queue1 = new Queue;
			std::ifstream file;
			file.open("C:\\Users\\walke\\source\\repos\\AlgStrD_4sem_Kurs\\AlgStrD_4sem_Kurs\\in.txt", std::ios::in);
			Reading(Queue1, file);
			int size = Queue1->get_size();
			int** Matrix;
			Matrix = new int* [size];
			for (int i = 0; i < size; i++) {
				Matrix[i] = new int[size];
			}
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					Matrix[i][j] = 0;
				}
			}
			file.clear();
			file.seekg(0);
			int Matrix2[4][4] = { {0,6,5,0},{0,0,0,9},{0,2,3,4},{0,0,0,1} };
			matrix(Queue1, file, Matrix, size);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					Assert::IsTrue(Matrix[i][j] == Matrix2[i][j]);
				}
			}
			file.close();
			delete Matrix;
		}
		TEST_METHOD(TestMethod2)
		{
			Queue* Queue1 = new Queue;
			std::ifstream file;
			std::string Array1[6] = { "S","O","Q","R","T" };
			file.open("C:\\Users\\walke\\source\\repos\\AlgStrD_4sem_Kurs\\AlgStrD_4sem_Kurs\\in.txt", std::ios::in);
			Reading(Queue1, file);
			for (int i = 0; i < Queue1->get_size(); i++) {
				Assert::IsTrue(Queue1->at(i) == Array1[i]);
			}
			file.close();
		}
		
	};
}
