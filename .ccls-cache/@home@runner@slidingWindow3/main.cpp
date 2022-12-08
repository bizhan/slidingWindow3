#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
// Given a string, find the length of the longest substring in it
// with no more than K distinct characters.

class IntegerNumbers {
public:
  static int lengthLongestSubstr(int k, const vector<int> &arr) {
    int len = 0;
    int windowStart = 0;
    int lastWindowEnd = 0;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      if (windowEnd == 0) {
        cout << "First" << endl;
        continue;
      }
      if (arr[lastWindowEnd] == arr[windowEnd]) {
        len++;
        cout << "second " << len << " "<< lastWindowEnd<<" "<<windowEnd<<endl;
        continue;
      }
        else windowStart = lastWindowEnd = windowEnd;
    }
    return 0;
  }
};

int main() {
  std::cout << "Hello World!\n";
  IntegerNumbers::lengthLongestSubstr(3,
                                      vector<int>{2, 3, 3, 3, 4, 5, 6, 3, 3});
}