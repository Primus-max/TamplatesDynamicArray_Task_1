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

template<typename T>
void FillArray(T* arr, int size);

template<typename T>
void PrintArray(T* arr, int size);

template<typename T>
T* AddNewItemToEnd(T* srcArr, int& size, T itemToAdd);

template<typename T>
T* InsertElementToPointPosition(T* array, int& size, int index, const T element);

template<typename T>
T* RemoveLastElement(T* array, int& size);

template<typename T>
T* RemoveElementFromPosition(T* array, int& size, int index);

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

	printf("%s %i %s", "Работаем с массивом целочисленных значений, какой элемент добавить и на какую позицию из : ", sizeArray, " элементов ?");
	int item = 0, position = 0;
	cin >> item >> position;
	int* ArrWithElementToPointPosition = InsertElementToPointPosition(ArrWithAddedItemToEnd, sizeArray, position, item);
	printf("%s \n\n", " -----------------------------------  Добавил указанный элемент на указанную позицию ----------------------------------- ");
	PrintArray(ArrWithElementToPointPosition, sizeArray);

	printf("%s \n\n", " -----------------------------------  Удаление последнего элемента из массива ----------------------------------- ");
	int* RemovedLastElement =  RemoveLastElement(ArrWithElementToPointPosition, sizeArray);
	PrintArray(RemovedLastElement, sizeArray);

	printf("%s %i %s", "Работаем с массивом целочисленных значений, на какой позиции удалить элемент? Из : ", sizeArray, " элементов ?");
	int positionToRemove = 0;
	cin >>  positionToRemove;
	int* RemovedElementByPosition = RemoveElementFromPosition(RemovedLastElement, sizeArray, position);
	printf("%s \n\n", " -----------------------------------  Удалил элемент на указанной позиции ----------------------------------- ");
	PrintArray(RemovedElementByPosition, sizeArray);
}

