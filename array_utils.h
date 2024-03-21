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
    std::random_device random;
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
T* AllocateMemory(T size) {
	T* newArray = new int[size];
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

	T* newArr = new T[size + 1];
	if (newArr == nullptr)
		return nullptr;

	for (int i = 0; i < size; ++i)
		newArr[i] = srcArr[i];
	newArr[size] = itemToAdd;

	++size;
	delete[] srcArr;
	return newArr;
}



#endif
