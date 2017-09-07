/*
 * hello.cpp
 *
 *  Created on: Aug 31, 2017
 *      Author: Michael Ly
 */

/* Michael Ly
 * TA: Eeshita Biswas
 * 8/31/17
 * This file contains functions for Lab 1.
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

// Function declarations
bool isPrime(int k);
/* Returns a boolean determining whether the input is a prime number.
 * Argument: k: integer as an input.
 */

int sum(int x, int y);
/* Returns an integer of the sum between the two inputs.
 * Arguments: x: the first integer as an input.
 * 			  y: the second integer as an input.
 */

void isLeap(int yr);
/* Prints out all the leap years between the input year and the year 400 years later.
 * Argument: yr: the year as an input.
 */

void tri(int num);
/* Prints out a triangle form by integers. The integers are related to the input number of rows.
 * Argument: num: number of rows as an input.
 */

int ArmStrNums(int x);
/* Returns all the armstrong numbers from 1 to the input number.
 * Argument: x: desired number as an input.
 */

int gNum(int arr[], int size);
/* Returns the largest number from the given array.
 * Arguments: arr[]: an array as an input.
 * 			  size: the size of the array as an input.
 */
bool isPa(int arr[], int size);
/* Returns a boolean determining whether the input array is a palindrome.
 * Arguments: arr[]: an array as an input.
 * 			  size: the size of the array as an input.
 */

void com(int arr[], int size);
/* Concatenates all the integers from the array and prints them out as a single integer.
 * Arguments: arr[]: an array as an input.
 *            size: the size of the array as an input.
 */



// Testing Arrays
int arr1[5] = {4, 3, 5, 4, 1};
int arr2[5] = {27, 81, 90, 3, 100};
int arr3[6] = {8, 9, 15, 3, 2, 12};
int arr4[4] = {1, 2, 2, 1};
int arr5[4] = {2, 3, 3, 2};
int arr6[4] = {5, 4, 4, 5};
int arr7[4] = {1, 2, 3, 4};
int arr8[5] = {1, 2, 3, 2, 1};
int arr9[7] = {1, 2, 3, 4, 3, 2, 1};



// Problem 1
int main() {
	cout << "Problem 1" << endl;
	cout << "Hello World!!" << endl;
	cout << "****************************************" << endl;

	cout << "Problem 2" << endl;
	cout << "Test 1: " << isPrime(1) << endl; // Expected output is 0, meaning false.
	cout << "Test 2: " << isPrime(2) << endl; // Expected output is 1, meaning true.
	cout << "Test 3: " << isPrime(16) << endl; // Expected output is 0, meaning false.
	cout << "****************************************" << endl;

	cout << "Problem 3" << endl;
	cout << "Test 1: " << sum(2, 4) << endl; // Expected output is 5.
	cout << "Test 2: " << sum(1, 5) << endl; // Expected output is 10.
	cout << "Test 3: " << sum(6, 2) << endl; // Expected output is 14.
	cout << "****************************************" << endl;

	cout << "Problem 4" << endl;
	cout << "Test 1: " << endl;
	isLeap(2017); // Expected outputs are years from 2020 to 2416 with increments of 4.
	cout << endl;
	cout << "Test 2: " << endl;
	isLeap(100); // Expected outputs are years from 104 to 496 with increments of 4.
	cout << endl;
	cout << "Test 3: " << endl;
	isLeap(200); // Expected outputs are years from 204 to 596 with increments of 4.
	cout << "****************************************" << endl;

	cout << "Problem 5" << endl;
	cout << "Test 1: " << endl;
	tri(4); // Expected output is a triangle like the one in the lab instructions.
	cout << endl;
	cout << "Test 2: " << endl;
	tri(6); // Expected output is a triangle
	cout << endl;
	cout << "Test 3: " << endl;
	tri(1); // Expected output is a single integer 1.
	cout << "****************************************" << endl;

	cout << "Problem 6" << endl;
	cout << "Test 1: " << endl;
	cout << "Integers counted: " << ArmStrNums(100) << endl; // Expected outputs are integers 1-9, total number of outputs is 9.
	cout << endl;
	cout << "Test 2: " << endl;
	cout << "Integers counted: " << ArmStrNums(1000) << endl; // Expected outputs are integers 1-9, 153, 370, 371, 407, total number of outputs is 13.
	cout << endl;
	cout << "Test 3: " << endl;
	cout << "Integers counted: " << ArmStrNums(10000) << endl; // Expected outputs are integers 1-9, 153, 370, 371, 407, 1634, 8208, 9474, total number of output is 16.
	cout << "****************************************" << endl;

	cout << "Problem 7" << endl;
	cout << "Test 1: " << gNum(arr1, 5) << endl; // Expected output is 5.
	cout << "Test 2: " << gNum(arr2, 5) << endl; // Expected output is 100.
	cout << "Test 3: " << gNum(arr3, 6) << endl; // Expected output is 15.
	cout << "****************************************" << endl;

	cout << "Problem 8" << endl;
	cout << "Test 1: " << isPa(arr4, 4) << endl; // Expected output is 1, meaning true.
	cout << "Test 2: " << isPa(arr8, 5) << endl; // Expected output is 1, meaning true.
	cout << "Test 3: " << isPa(arr7, 4) << endl; // Expected output is 0, meaning false.
	cout << "****************************************" << endl;

	cout << "Problem 9" << endl;
	cout << "Test 1: ";
	com(arr4, 4); // Expected output is 1221;
	cout << endl;
	cout << "Test 2: ";
	com(arr1, 5); // Expected output is 43541;
	cout << endl;
	cout << "Test 3: ";
	com(arr9, 7); // Expected output is 1234321;
	cout << endl;
	cout << "****************************************" << endl;

	return 0;
}

// Problem 2
bool isPrime(int k) {
	int divider = 2;
	bool is_prime = true;
	while (divider < k && k%divider==0) {
		is_prime = false;
		divider++;
	}
	if (k == 1)
		is_prime = false;
	return is_prime;
}


// Problem 3
int sum(int x, int y) {
	int total = 0;
	int i;
	if (x < y) {
		for (i=x+1; i<y; i++) {
			total += i;
		}
		total += x;
	}
	if (x > y) {
		for (i=y+1; i<x; i++) {
			total += i;
		}
		total += y;
	}
	return total;
}

// Problem 4
void isLeap(int yr) {
	int end = yr + 400;
	while (yr <= end) {
		if(yr % 4 == 0) {
			if(yr % 100 == 0) {
				if(yr % 400 == 0) {
					cout << yr << endl;
				}
			}
			else{
				cout << yr << endl;
			}
		}
		yr++;
	}
}

// Problem 5
void tri(int num) {
	for (int row=1; row<=num; row++) {
		if (row == 1) {
			for (int space=0; space<num-row; space++) {
				cout << " ";
			}
			cout << row << endl;
		}
		else if (row < num) {
			for (int space=0; space<num-row; space++) {
				cout << " ";
			}
			cout << row;
			for (int spacebtw=0; spacebtw<(2*row)-3; spacebtw++) {
				cout << " ";
			}
			cout << row << endl;
		}
		else {
			for (int n=1; n<=(row*2)-1; n++) {
			cout << num;
			}
		}
	}
}

// Problem 6
int ArmStrNums(int x) {
	int digitnum, digit, num, sum, count = 0;
	if (x >= 1) {
		for (int i=1; i<=x; i++) {
			digitnum = 0, sum = 0, num = i;
			while (num != 0) {
				num /= 10;
				digitnum++;
			}
			num = i;
			while (num != 0) {
				digit = num%10;
				sum += ((int)(pow(digit,digitnum)+.5));
				num /= 10;
			}
			if (sum == i) {
				cout << i << endl;
				count++;
			}
		}
	}
	return count;
}

// Problem 7
int gNum(int arr[], int size) {
	int max = arr[0];
	for (int n=1; n<size; n++) {
		if (arr[n] > max) {
			max = arr[n];
		}
	}
	return max;
}

// Problem 8
bool isPa(int arr[], int size) {
	bool is_pa = false;
	for (int n=0; n<size; n++) {
		if (arr[n] == arr[(size-1)-n]) {
			is_pa = true;
		}
	}
	return is_pa;
}

// Problem 9
void com(int arr[], int size) {
	for (int n=0; n<size; n++) {
		cout << arr[n];
	}
}




