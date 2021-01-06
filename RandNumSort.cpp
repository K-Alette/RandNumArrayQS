//This program randomly populates an array of 250 integers then 
//prints them, uses quicksort to sort them, and prints again
//SDEV345-81
//Kodi Lein
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Array //class for array structure and sorting
{
private:
	vector<double>(Vector); //vector 
	int elems;              //number of elements
public:
	Array(int max) : elems(0) //constructor
	{
		Vector.resize(max); //size vector
	}

	void insert(double val) //inserts into array
	{
		Vector[elems] = val;
		elems++;              //increase size after each element is inserted
	}

	void display() //displays aray
	{
		for (int i = 0; i < elems; i++) //for each element in array
			cout << Vector[i] << " ";  //display data
		cout << endl << endl;
	}

	void swap(int A, int B) //function to swap two values for partitioning
	{
		double temp = Vector[A]; //A into temp
		Vector[A] = Vector[B];   //B into A
		Vector[B] = temp;        //temp into B
	}

	int partition(int l, int r, double pivot) //partition for quicksort
	{
		int left = l - 1;
		int right = r;

		while (true)
		{
			while (Vector[++left] < pivot); //find larger element

			while (right > 0 && Vector[--right] > pivot); //find smaller element

			if (left >= right) //if pointers cross, break
				break;
			else
				swap(left, right); //otherwise swap elements
		}
		swap(left, r); //restores pivot point
		return left;  //returns pivot location
	}

	void QS(int l, int r) //recursive function for quicksort
	{
		if (r - l <= 0)
			return;
		else
		{
			double pivot = Vector[r];

			int part = partition(l, r, pivot);
			QS(l, part - 1); //sort left side
			QS(part + 1, r); //sort right side
		}
	}
	void quicksort()
	{
		QS(0, elems - 1); //calls recursive quicksort
	}
};

int main()
{
	time_t aTime;
	int SIZE = 250; //array size
	Array arr(SIZE); //creates array
	srand(static_cast<unsigned>(time(&aTime)));

	for (int i = 0; i < SIZE; i++) //fill array with random numbers
	{
		double n = rand() % 99;
		arr.insert(n);
	}
	
	cout << "Here is the unsorted array: ";
	arr.display(); //display array
	arr.quicksort(); //sort array
	cout << "Here is the sorted array: ";
	arr.display(); //display array

	return 0;
}