#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <random>
using namespace std;

/// <summary>
/// Функция заполнение массива рандомными значениями
/// </summary>
/// <typeparam name="T">Пользовательский тип</typeparam>
/// <param name="arr">- массив</param>
/// <param name="size">- размер массива</param>
template<typename T>
void FillArray(T* arr, int size) {
	random_device random;
	for (int i = 0; i < size; i++)
		arr[i] = static_cast<T>(random() % (100 + 50) - 50);
}

/// <summary>
/// Функция печати массива в консоль
/// </summary>
/// <typeparam name="T">Пользовательский тип</typeparam>
/// <param name="arr">- массив</param>
/// <param name="size">- размер массива</param>
template<typename T>
void PrintArray(T* arr, int size) {
	for (int* i = arr; i < arr + size; i++)
		cout << "[ " << *i << "] " << " ";

	cout << endl;
}

/// <summary>
/// Функция расчёта размера(новой памяти)
/// </summary>
/// <typeparam name="T">- пользовательский тип</typeparam>
/// <param name="arr">- массив из которого считать</param>
/// <param name="size">- размер</param>
/// <returns>новы размер</returns>
//template <typename T>
//int CalcNewMemory(T* arr, int size) {
//	int count = 0;
//	for (int i = 0; i < size; ++i) {
//		if (IsPrime(arr[i]))
//			++count;
//	}
//	return count;
//}

/// <summary>
/// Функция выделения новой памяти для массива
/// </summary>
/// <typeparam name="T">- пользовательский тип</typeparam>
/// <param name="size">- новый размер</param>
/// <returns>указатель на массив</returns>
template<typename T>
T* AllocateMemory(int size) {
	T* newArray = new T[size];
	return newArray;
}

/// <summary>
/// Перегруженная функция удаления памяти
/// </summary>
/// <typeparam name="T">пользовательский тип</typeparam>
/// <param name="ptr">- указатель</param>
template<typename T>
void ClearMemory(T* ptr) {
	delete ptr;
}

/// <summary>
/// Функция добавления нового элемента в конец массива
/// </summary>
/// <typeparam name="T">пользовательский тип</typeparam>
/// <param name="srcArr">- исходный массив</param>
/// <param name="size">- исходный размер</param>
/// <param name="itemToAdd">- элемент для добавления</param>
/// <returns>указатель на новый массив</returns>
template<typename T>
T* AddNewItemToEnd(T* srcArr, int& size, T itemToAdd) {
	if (srcArr == nullptr || size <= 0)
		return nullptr;

	T* newArr =   AllocateMemory<T>(size + 1);
	if (newArr == nullptr)
		return nullptr;

	for (int i = 0; i < size; ++i)
		newArr[i] = srcArr[i];
	newArr[size] = itemToAdd;

	++size;
	delete[] srcArr;
	return newArr;
}

/// <summary>
/// Функция вставки нового элемента на указанную позицию
/// </summary>
/// <typeparam name="T">пользовательский тип</typeparam>
/// <param name="array">- исходный массив</param>
/// <param name="size">- исходный размер</param>
/// <param name="index">- индекс для вставки элемента</param>
/// <param name="element">- элемент для вставки</param>
/// <returns>указатель на новый массив</returns>
template<typename T>
T* InsertElementToPointPosition(T* array, int& size, int index, const T element) {
	if (array == nullptr || index < 0 || index > size)
		return nullptr;
		
	T* newArray = AllocateMemory<T>(size + 1);
	if (newArray == nullptr)
		return nullptr;
	
	for (int i = 0; i < index; ++i)
		newArray[i] = array[i];
	
	newArray[index] = element;
	
	for (int i = index + 1; i < size + 1; ++i)
		newArray[i] = array[i - 1];
	
	++size;
	ClearMemory(array);
	return newArray;
}

template<typename T>
T* RemoveLastElement(T* array, int& size) {
	if (array == nullptr || size <= 0)
		return nullptr;
		
	T* newArray = AllocateMemory<T>(size - 1);
	if (newArray == nullptr)
		return nullptr;
		
	for (int i = 0; i < size - 1; ++i)
		newArray[i] = array[i];
		
	--size;	
	ClearMemory(array);
	return newArray;
}

#endif
