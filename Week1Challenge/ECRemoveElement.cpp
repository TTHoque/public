#include "ECNumbers.h"
#include <iostream>

void ECRemoveSpace(int nums[], int len, int val)
{
  // your code here
  using namespace std;
  int occurences = 0;
  for (int i=len-1; i>=0; i--) {
    if (nums[i] == val) {
      nums[i] = nums[len-1-occurences];
      nums[len-1-occurences] = '\0';
      occurences++;
    }
  }

  cout << "nums_array: ";
  for(int i=0; i<len-occurences; i++)
  {
      cout << nums[i] << " ";
  } 
  cout << endl;
  cout << "k: " << occurences << endl << endl;

}
