#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <random>
using namespace std;

/// <summary>
/// ������� ���������� ������� ���������� ����������
/// </summary>
/// <typeparam name="T">���������������� ���</typeparam>
/// <param name="arr">- ������</param>
/// <param name="size">- ������ �������</param>
template<typename T>
void FillArray(T* arr, int size) {
    std::random_device random;
    for (int i = 0; i < size; i++)
        arr[i] = static_cast<T>(random() % (100 + 50) - 50);
}

/// <summary>
/// ������� ������ ������� � �������
/// </summary>
/// <typeparam name="T">���������������� ���</typeparam>
/// <param name="arr">- ������</param>
/// <param name="size">- ������ �������</param>
template<typename T>
void PrintArray(T* arr, int size) {
	for (int* i = arr; i < arr + size; i++)
		cout << "[ " << *i << "] " << " ";

	cout << endl;
}

/// <summary>
/// ������� ��������� ����� ������ ��� �������
/// </summary>
/// <typeparam name="T">- ���������������� ���</typeparam>
/// <param name="size">- ����� ������</param>
/// <returns>��������� �� ������</returns>
template<typename T>
T* AllocateMemory(T size) {
	T* newArray = new int[size];
	return newArray;
}

/// <summary>
/// ������������� ������� �������� ������
/// </summary>
/// <typeparam name="T">���������������� ���</typeparam>
/// <param name="ptr">- ���������</param>
template<typename T>
void ClearMemory(T* ptr) {
	delete ptr;
}

/// <summary>
/// ������������� ������� �������� ������
/// </summary>
/// <typeparam name="T">���������������� ���</typeparam>
/// <param name="ptr">- ���������</param>
template<typename T>
void ClearMemory(T* ptr) {
	delete[] ptr;
}

#endif
