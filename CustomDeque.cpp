#pragma once
#include <iostream>
#include <exception>
#define INITIAL_CAPACITY 10

using namespace std;

struct NoValuesException : public exception {
	const char* what() {
		return "No values in the container";
	}
};

template<typename T>
class CustomDeque {
public:
	template<typename T>
	void addBack(T value) {
		if (count == capacity) {
			resize(dArray);
			dArray[count++] = value;
		}
		else {
			if (isEmpty()) {
				dArray[0] = value;
				count++;
			}
			else {
				dArray[count++] = value;
			}
		}
	}

	template<typename T>
	void addFront(T value) {
		if (count == capacity) {
			resize(dArray);
			shiftToRight(value);
		}
		else {
			if (isEmpty()) {
				dArray[0] = value;
				count++;
			}
			else {
				shiftToRight(value);
			}
		}
	}

	T removeFront() {
		if (count == 0) {
			throw NoValuesException();
		}
		T removed = dArray[0];
		shiftToLeft();
		
		return removed;
	}

	void shiftToLeft() {
		count--;
		T last = dArray[count];
		for (int i = 0; i < count - 1; i++) {
			T temp = dArray[i + 1];
			dArray[i] = temp;
		}
		dArray[count - 1] = last;
	}

	T removeBack() {
		if (count == 0) {
			throw NoValuesException();
		}
		T removed = dArray[count - 1];
		remove();
		return removed;
	}

	void remove() {
		count--;
		T* tempArr = new T[capacity];
		if (count < capacity) {
			for (int i = 0; i < count; i++) {
				tempArr[i] = dArray[i];
			}
		}
		for (int i = 0; i < capacity; i++) {
			dArray[i] = tempArr[i];
		}
		
		delete[] tempArr;
	}

	template<typename T>
	void shiftToRight(T value) {
		for (int i = count; i > 0; i--) {
			dArray[i] = dArray[i - 1];
		}
		dArray[0] = value;
		count++;
	}

	bool isEmpty() { 
		return count == 0; 
	}

	void printQueue() {
		cout << "Queue elements: \n";
		for (int i = 0; i < count; i++) cout << dArray[i] << "\n";
		cout << endl;
	}

	void printInfo() {
		cout << "Capacity: " << capacity << endl;
		cout << "Count: " << count << endl;
	}

	T peekFront() {
		if (count == 0) throw NoValuesException();
		return dArray[0];
	}

	T peekBack() {
		if (count == 0) throw NoValuesException();
		return dArray[count - 1];
	}

	int size() {
		return count;
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
	
};


/*
INEFFICIENT
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
*/
