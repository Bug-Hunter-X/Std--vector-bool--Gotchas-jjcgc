#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
  // Original buggy code
  auto start = high_resolution_clock::now();
  std::vector<bool> boolVec(1000000);
  for (size_t i = 0; i < boolVec.size(); ++i) {
    boolVec[i] = (i % 2 == 0);
  }
  for (size_t i = 0; i < boolVec.size(); ++i) {
    bool val = boolVec[i];
  }
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);
  cout << "std::vector<bool> time: " << duration.count() << "ms" << endl;

  // Solution using std::vector<char>
  start = high_resolution_clock::now();
  std::vector<char> charVec(1000000);
  for (size_t i = 0; i < charVec.size(); ++i) {
    charVec[i] = (i % 2 == 0);
  }
  for (size_t i = 0; i < charVec.size(); ++i) {
    bool val = (charVec[i] != 0);
  }
  end = high_resolution_clock::now();
  duration = duration_cast<milliseconds>(end - start);
  cout << "std::vector<char> time: " << duration.count() << "ms" << endl;

  return 0;
}