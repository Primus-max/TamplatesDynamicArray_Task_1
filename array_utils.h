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
/// Перегруженная функция удаления памяти
/// </summary>
/// <typeparam name="T">пользовательский тип</typeparam>
/// <param name="ptr">- указатель</param>
template<typename T>
void ClearMemory(T* ptr) {
	delete[] ptr;
}

#endif
