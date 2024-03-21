// Написать шаблонные функции которые :
// -добавляют новый элемент в конец массива
// - добавляют новый элемент в указанную позицию массива
// - удаляют последний элемент массива
// - удаляют элемент из указанной позиции массива.

#include <iostream>
#include <random>
#include <windows.h>
using namespace std;

// Заполнение массив
template<typename T>
void FillArray(T* arr, int size);

// Печать массива
template<typename T>
void PrintArray(T* arr, int size);

// Динамическое выделение памяти для массива
template<typename T>
T* AllocateMemory(T size);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("%s", "Задать размер массива : ");
	int sizeSrcArray = 0;
	cin >> sizeSrcArray;
	int* SrcArray = new int[sizeSrcArray];
	FillArray(SrcArray, sizeSrcArray);
	printf("%s \n\n", "  -----------------------------------  Заполненный массив ----------------------------------- ");
	PrintArray(SrcArray, sizeSrcArray);
}

template<typename T>
void FillArray(T* arr, int size) {
	random_device random;
	for (T* i = arr; i < arr + size; i++)
		*i = random() % (100 + 50) - 50;
}

template<typename T>
void PrintArray(T* arr, int size) {
	for (int* i = arr; i < arr + size; i++)
		cout << "[ " << *i << "] " << " ";

	cout << endl;
}
