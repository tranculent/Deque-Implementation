#pragma once
#include <iostream>
#define INITIAL_CAPACITY 10

using namespace std;

template<typename T>
class CustomDeque {
public:
	template<typename T>
	void addFront(T value) {
		if (count == capacity || count + 1 == capacity) {
			resize(dArray);
			tempShift(value);
		}
		else {
			if (isEmpty()) {
				dArray[0] = value;
				count++;
			}
			else {
				tempShift(value);
			}
		}
	}

	bool isEmpty() { return count == 0; }

	void printQueue() {
		cout << "Queue elements: ";
		for (int i = 0; i < count; i++) cout << dArray[i] << "\n";
		cout << endl;
	}

	void printInfo() {
		cout << "Capacity: " << capacity << endl;
		cout << "Count: " << count << endl;
	}

private:
	T* dArray = new T[INITIAL_CAPACITY];
	int count = 0;
	int capacity = INITIAL_CAPACITY;

	template<typename T>
	void resize(T*& arr)
	{
		T* newArr;
		newArr = new T[capacity * 2];

		for (int i = 0; i < count; i++)
			newArr[i] = arr[i];

		cout << endl;
		delete[] arr;
		arr = newArr;
		capacity *= 2;
	}

	template<typename T>
	void tempShift(T value) {
		dArray[count++] = value;
	}

	template<typename T>
	void shiftArray(T value) {
		T* newArr;
		if (isEmpty()) {
			newArr = new T[++count];
			newArr[0] = value;
		}
		else {
			newArr = new T[++count];
			newArr[0] = value;
			
			int dArrayLength = count;
			if (dArrayLength > 1) {
				for (int i = 1; i < dArrayLength; i++) {
					newArr[i] = dArray[i - 1];
				}
			}
			else {
				newArr[1] = dArray[0];
			}
		}
		for (int i = 0; i < count; i++)
			dArray[i] = newArr[i];
		
		delete[] newArr;
	}
};
