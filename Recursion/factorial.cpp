#include <iostream>
#include <time.h>

using namespace std;

int iterativeFactorial(int num) {
  int total = 1;
  for (int i = num; i > 1; i--) {
    total *= i;
  }
    return total;
}

int recursiveFactorial(int num) {
  if (num == 1) {
    return 1;
  } else {
    return num * recursiveFactorial(num - 1);
  }
}

int main()
{
  // Define a timer variable
  clock_t ticks;

  int choice = 0;
  int userInput = 0;

    while (choice != 9) {
        cout << "Factorial Menu:" << endl;
        cout << "  1. Iterative " << endl;
        cout << "  2. Recursive" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
          case 1:
              // Initialize a timer variable before loading bids
              ticks = clock();

              // Request User input for number to call function
              cout << "Enter a number: ";
              cin >> userInput;

              // call iterative recursion function with userInput
              cout << "result:" << iterativeFactorial(userInput) << endl;

              // Calculate elapsed time and display result
              ticks = clock() - ticks; // current clock ticks minus starting clock ticks
              cout << "time: " << ticks << " clock ticks" << endl;
              cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

              break;

          case 2:
              // Initialize a timer variable before loading bids
              ticks = clock();

              // Request User input for number to call function
              cout << "Enter a number: ";
              cin >> userInput;

              // call iterative recursion function with userInput
              cout << "result:" << recursiveFactorial(userInput) << endl;

              // Calculate elapsed time and display result
              ticks = clock() - ticks; // current clock ticks minus starting clock ticks
              cout << "time: " << ticks << " clock ticks" << endl;
              cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
        }
    }
  

  return 0;
}