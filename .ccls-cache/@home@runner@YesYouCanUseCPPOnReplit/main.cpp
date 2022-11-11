#include <iostream>
#include <vector>
#include <algorithm>
// I'm a functional FAILURE :(

int sum(std::vector<int> bases, int target) {
  std::vector<int> based;
  auto predicate = [bases](int num) {
    for(int base : bases) {
      if (num % base == 0) {
        return true;
      }
    }
    return false;
  };
  std::copy_if(0, target, std::back_inserter(based), predicate);
  auto adder = [](int a, int b) {
    return a + b;
  };
  return std::accumulate(based.begin(), based.end(), 0, adder);
}

int imperativeSum(std::vector<int> bases, int target) {
  auto based = [bases](int num) {
    for(int base : bases) {
      if (num % base == 0) {
        return true;
      }
    }
    return false;
  };

  int result = 0;
  for(int i = 0; i < target; i++) {
    if(based(i)) {
      result += i;
    }
  }
  return result;
}

int main() {
  std::vector<int> bases = {3, 5};
  int sumTen = imperativeSum(bases, 10);
  std::cout << "Hello World!\n";
  std::cout << "Multiples sum below ten: " << sumTen << "\n";
  int sumThousand = sum(bases, 1000);
  std::cout << "Multiples sum below one thousand: " << sumThousand << "\n";
}