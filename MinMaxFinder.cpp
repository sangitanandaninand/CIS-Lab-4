#include <iostream>

using namespace std;

//Function to find the minimum and maximum values in an array using pointers
void findMinAndMax(const int arr[], int size, int* min, int* max) {
    //Start looping from the second element (index 1)
    for (int i = 1; i < size; i++) {
        //If the current element is smaller than the value pointed to by min, update min 
        if (arr[i] < *min) {
            *min = arr[i];
        }
        //If the current element is larger than the value pointed to by max, update max 
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    //Create an integer array with at least 10 unsorted values 
	int arr[] = { 23, 5, 67, -2, 45, 87, 1, 99, 34, -10 };
    int size = sizeof(arr) / sizeof(arr[0]);


    //State two integer variables, min, and max
    int min, max;



	//Initialize min and max to the first element of the array
    min = arr[0];
    max = arr[0];


	//Call the findAndMax function, passing the array, its size, and the memory  addresses of min and max
	findMinAndMax(arr, size, &min, &max);


	//After the function call, print the final values of min and max

    cout << "The minimum value is: " << min << endl; 
	cout << "The maximum value is: " << max << endl;

	return 0;

}