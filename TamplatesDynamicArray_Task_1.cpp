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
// Возвращает указатель на новый массив
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
	printf("%s \n\n", " -----------------------------------  Заполненный массив ----------------------------------- ");
	PrintArray(SrcArray, sizeSrcArray);
}


template<typename T>
T* AllocateMemory(T size) {
	T* newArray = new int[size];
	return newArray;
}