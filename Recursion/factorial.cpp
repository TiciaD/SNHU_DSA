#include <iostream>

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
  cout << iterativeFactorial(3);
  cout << recursiveFactorial(3);
  return 0;
}