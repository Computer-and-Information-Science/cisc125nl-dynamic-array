#include "dynamicarray.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  DynamicArray<int> array1;
  DynamicArray<string> array2;

  cout << array1.size() << endl;

  array1.push_back(10);
  array1.push_back(20);
  array1.push_back(30);
  cout << array1.size() << endl;
  array1[1] = 25;

  array1.push_back(44);
  array1.push_back(55);
  array1.push_back(77);
  array1.push_back(123);
  array1.push_back(88);
  array1.push_back(44);
  array1.push_back(44);
  array1.push_back(55);
  array1.push_back(654);
  array1.push_back(444);
  array1.push_back(44);
  array1.push_back(234);
  array1.push_back(22);
  array1.pop_back();
  cout << array1.size() << endl;

  for (int i = 0; i < array1.size(); i++)
    cout << " " << array1[i];
  cout << endl;

  array2.push_back("cat");
  array2.push_back("dog");
  cout << array2.size() << endl;
  // cout << array2[0] << endl;
  // cout << array2[1] << endl;
  array2.resize(20);
  for (int i = 0; i < array2.size(); i++)
    cout << i << ": " << array2[i] << endl;
}
