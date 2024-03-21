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
/// ������� ������� �������(����� ������)
/// </summary>
/// <typeparam name="T">- ���������������� ���</typeparam>
/// <param name="arr">- ������ �� �������� �������</param>
/// <param name="size">- ������</param>
/// <returns>���� ������</returns>
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
/// ������� ���������� ������ �������� � ����� �������
/// </summary>
/// <typeparam name="T">���������������� ���</typeparam>
/// <param name="srcArr">- �������� ������</param>
/// <param name="size">- �������� ������</param>
/// <param name="itemToAdd">- ������� ��� ����������</param>
/// <returns>��������� �� ����� ������</returns>
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
