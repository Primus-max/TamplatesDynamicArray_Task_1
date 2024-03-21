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

#endif
