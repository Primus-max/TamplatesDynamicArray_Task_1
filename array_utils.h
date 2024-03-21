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
	if (arr == nullptr) return;
	random_device random;
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
	if (arr == nullptr) return;
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
T* AllocateMemory(int size) {
	if (size <= 0) size = 0;
	T* newArray = new T[size];
	return newArray;
}

/// <summary>
/// ������������� ������� �������� ������
/// </summary>
/// <typeparam name="T">���������������� ���</typeparam>
/// <param name="ptr">- ���������</param>
template<typename T>
void ClearMemory(T* ptr) {
	if (ptr == nullptr) return;
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
/// ������� ������� ������ �������� �� ��������� �������
/// </summary>
/// <typeparam name="T">���������������� ���</typeparam>
/// <param name="array">- �������� ������</param>
/// <param name="size">- �������� ������</param>
/// <param name="index">- ������ ��� ������� ��������</param>
/// <param name="element">- ������� ��� �������</param>
/// <returns>��������� �� ����� ������</returns>
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

/// <summary>
/// ������� �������� ���������� �������� �� �������
/// </summary>
/// <typeparam name="T">���������������� ���</typeparam>
/// <param name="array">- �������� ������</param>
/// <param name="size">- ������</param>
/// <returns>��������� �� ����� ������</returns>
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

/// <summary>
/// ������� �������� �������� �� ��������� �������
/// </summary>
/// <typeparam name="T">���������������� ���</typeparam>
/// <param name="array">- �������� ������</param>
/// <param name="size">- ������</param>
/// <param name="index">��������� �� ����� ������</param>
/// <returns></returns>
template<typename T>
T* RemoveElementFromPosition(T* array, int& size, int index) {
	if (array == nullptr || index < 0 || index >= size)
		return nullptr;

	T* newArray = AllocateMemory<T>(size - 1);
	if (newArray == nullptr)
		return nullptr;

	for (int i = 0; i < index; ++i)
		newArray[i] = array[i];

	for (int i = index + 1; i < size; ++i)
		newArray[i - 1] = array[i];

	--size;
	ClearMemory(array);
	return newArray;
}

/// <summary>
/// ������� �������� ���������� �� ������
/// </summary>
/// <typeparam name="T">���������������� ���</typeparam>
/// <param name="array">- �������� ������</param>
/// <param name="size">- ������</param>
/// <returns>��������� �� ����� ������</returns>
template<typename T>
T* RemoveDuplicates(T* array, int& size) {
	if (array == nullptr || size <= 1)
		return nullptr;

	int uniqueCount = 0;

	for (int i = 0; i < size; ++i) {
		bool isUnique = true;
		for (int j = 0; j < i; ++j) {
			if (array[i] == array[j]) {
				isUnique = false;
				break;
			}
		}
		if (isUnique)
			++uniqueCount;
	}

	T* newArray = AllocateMemory<T>(uniqueCount);
	if (newArray == nullptr)
		return nullptr;

	int index = 0;

	for (int i = 0; i < size; ++i) {
		bool isUnique = true;
		for (int j = 0; j < i; ++j) {
			if (array[i] == array[j]) {
				isUnique = false;
				break;
			}
		}
		if (isUnique)
			newArray[index++] = array[i];
	}

	size = uniqueCount;
	ClearMemory(array);

	return newArray;
}

#endif
