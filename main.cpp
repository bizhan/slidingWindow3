#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
// Given a string, find the length of the longest substring in it
// with no more than K distinct characters.

// Debugging got better after the following implementation
// 1. providing indication what part of the loop debugging info is provided.
//   a. using >> , << for enter and exit, *** and --- begining and end of loop
//   b. printing information such that data corrolete better to each other:
//      windowStart, windowEnd, arr[windowStart], arr[windowEnd]

class IntegerNumbers {
public:
  static int lengthLongestSubstr(int k, const vector<int> &arr) {
    int len = 0;
    int windowStart = 0;
    int maxLen = 0;
    int windowEnd = 0;
    for (; windowEnd < arr.size(); windowEnd++) {
        cout<<" *** "<<windowStart<<" "<<windowEnd<< " "<<arr[windowStart]<< " "<<arr[windowEnd]<<endl;
      // Check if contents of start and end indexes are different
      if(arr[windowStart] != arr[windowEnd]) {
        // Find the length of window
        len = windowEnd - windowStart;
        // If it is 1, set start and end pointer of the window same
        // continue;
        if (len == 1) {windowStart = windowEnd;
            cout<<"cont "<<windowStart<<" "<<windowEnd<< " "<<arr[windowStart]<< " "<<arr[windowEnd]<<endl;
           cout<<"------------------"<<endl;
          continue;}
        // if the length of the window is greater than 1 then we sequence of same value in the window
        cout<<" >> "<<windowStart<<" "<<windowEnd<< " "<<arr[windowStart]<< " "<<arr[windowEnd]<<endl;
        cout<<" >>> "<<len<<endl;
        // we update the len only when if less than constrains
        if (len <= k)
          if(len > maxLen) maxLen = len;
        // cout<<"Enter if "<<arr[windowStart]<< " "<<arr[windowEnd]<<endl;
        //minLen = max(len, minLen);
        // reset all metrics, len to zero, windowStart = windowEnd
        len = 0;
        windowStart = windowEnd;
        cout<<" << "<<windowStart<<" "<<windowEnd<< " "<<arr[windowStart]<< " "<<arr[windowEnd]<<endl;
        //cout<<"Exit if "<<windowEnd<< " "/*<<len<<" "<< " "<<minLen<< " "*/<<arr[windowEnd]<< " "<<arr[windowStart]<<endl;
      } else {
        cout<<"else "<<windowStart<<" "<<windowEnd<< " "<<arr[windowStart]<< " "<<arr[windowEnd]<<endl;
        // we are here since we had consequence element of the same value, increment.
        len++; 
        //cout<<"else "<<windowEnd<< " "/*<<len<<" "<< " "<<minLen<< " "*/<<arr[windowEnd]<< " "<<arr[windowStart]<<endl;
        
        }
      cout<<"------------------"<<endl;
    }
      if(windowEnd > windowStart){
        // one more time check for the length.
        cout<<"Before exit "<< windowEnd - windowStart<< endl;
        if(windowEnd - windowStart <= k )
          if(maxLen < windowEnd - windowStart) maxLen = windowEnd - windowStart;
      }
    cout<<" maxLen "<<maxLen<<endl;
    return maxLen;
  }
};

int main() {
  std::cout << "Hello World!\n";
  IntegerNumbers::lengthLongestSubstr(4,
                                      vector<int>{2, 3, 3, 3, 3, 3, 3, 3, 3});
}