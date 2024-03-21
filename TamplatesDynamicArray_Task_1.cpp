// Написать шаблонные функции которые :
// - добавляют новый элемент в конец массива
// - добавляют новый элемент в указанную позицию массива
// - удаляют последний элемент массива
// - удаляют элемент из указанной позиции массива.

#include <iostream>
#include <random>
#include <windows.h>
#include "array_utils.h"
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

// Очистка памяти
template<typename T>
void ClearMemory(T* ptr);

// Добавление элемента в конец массива
template<typename T>
T* AddNewItemToEnd(T* srcArr, int& size, T itemToAdd);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("%s", "Задать размер массива : ");
	int initSize = 0;
	int& sizeArray = initSize;
	cin >> sizeArray;
	int* SrcArray = new int[sizeArray];
	FillArray(SrcArray, sizeArray);
	printf("%s \n\n", " -----------------------------------  Заполненный массив ----------------------------------- ");
	PrintArray(SrcArray, sizeArray);

	printf("%s", "Работаем с массивом целочисленных значений, какой элемент добавить в конец? : ");
	int itemToAdd = 0;
	cin >>  itemToAdd;
	int* ArrWithAddedItemToEnd = AddNewItemToEnd(SrcArray, sizeArray, itemToAdd);
	printf("%s \n\n", " -----------------------------------  Добавил элемент в конец массива ----------------------------------- ");
	PrintArray(ArrWithAddedItemToEnd, sizeArray);
}

