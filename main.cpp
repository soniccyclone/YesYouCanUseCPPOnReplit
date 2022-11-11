#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

//Functional but not really fluent
int sum(std::vector<int> bases, int target) {
  std::vector<int> range(target);
  std::iota(std::begin(range), std::end(range), 0);

  auto predicate = [bases](int num) {
    for(int base : bases) {
      if (num % base == 0) {
        return true;
      }
    }
    return false;
  };
  std::vector<int> based;
  std::copy_if(range.begin(), range.end(), std::back_inserter(based), predicate);
  
  auto adder = [](int a, int b) {
    return a + b;
  };
  return std::accumulate(based.begin(), based.end(), 0, adder);
}

//Imperative...
bool isBased(int num, std::vector<int> bases) {
  for(int base : bases) {
    if (num % base == 0) {
      return true;
    }
  }
  return false;
}

int imperativeSum(std::vector<int> bases, int target) {
  int result = 0;
  for(int i = 0; i < target; i++) {
    if(isBased(i, bases)) {
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