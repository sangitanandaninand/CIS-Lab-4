#include <iostream>
#include <iomanip>

using namespace std;

// Function to get scores from the user with validation
void getScores(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        double score;
        bool validInput = false;
        
        while (!validInput) {
            cout << "Enter score " << (i + 1) << ": ";
            cin >> score;
            
            // Input validation to ensure scores are not negative
            if (score < 0) {
                cout << "Error: Scores cannot be negative. Please enter a valid score." << endl;
            } else {
                arr[i] = score;
                validInput = true;
            }
        }
    }
}

// Function to sort scores in ascending order using bubble sort
void sortScores(double* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the average of scores
double calculateAverage(const double* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main()
{
    int numScores;

    // Get the number of test scores from the user
    cout << "How many test scores would you like to enter? ";
    cin >> numScores;

    // Input validation to ensure positive number
    if (numScores <= 0) {
        cout << "Error: Number of scores must be positive." << endl;
        return 1;
    }

    // Dynamically allocate an array to hold the test scores
    double* testScores = new double[numScores];

    // Call getScores to fill the array
    getScores(testScores, numScores);

    // Call sortScores to sort the array
    sortScores(testScores, numScores);

    // Call calculateAverage to get the average
    double average = calculateAverage(testScores, numScores);

    // Display the sorted test scores
    cout << "\nThe sorted scores are: ";
    cout << fixed << setprecision(2);
    for (int i = 0; i < numScores; i++) {
        cout << testScores[i] << " ";
    }
    cout << endl;

    // Display the average test score
    cout << "The average score is: " << average << endl;

    // Free the dynamically allocated memory and set pointer to nullptr
    delete[] testScores;
    testScores = nullptr;

    return 0;