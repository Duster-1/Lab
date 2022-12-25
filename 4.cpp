#include <iostream>
#include <list>

using namespace std;
int main()
{
  cout << "Bidirectional linked list: " << endl;
    list<int> nums = { 3,1,5,9,2,6,4,7,8 };

  cout << "list: ";
  for (int el : nums)
  {
    cout << el << " ";
  }
    
  cout << "\n\nAfter sorting:" << endl;

  list<int> sorted_nums;
  list<int> temp_nums;

  int size = nums.size();

  while (sorted_nums.size() != size) {

    int max = nums.front();

    while (nums.size() != 0) {
      if (nums.front() > max) {
        max = nums.front();
      }
      temp_nums.push_back(nums.front());
      nums.pop_front();
    }


    while (temp_nums.size() != 0) {

      if (temp_nums.front() == max) {
        sorted_nums.push_back(temp_nums.front());
        temp_nums.pop_front();
      }
      else {
        nums.push_back(temp_nums.front());
        temp_nums.pop_front();
      }

    }
  }


    for (int el : sorted_nums)
    {
    nums.push_front(el);
    }

    
  cout << "list: ";
  for (int el : nums)
  {
    cout << el << " ";
  }


  int k = 5;
  cout << "\n\nTry to find "<< k <<" in list: " << endl;

  int index = 0;

  for (int el : nums)
  {
    if (el == k) {
      cout << "k="<< 5 <<" founded of index " << index << endl;
      return 0;
    }
    index++;
  }

  cout << "Not founded" << endl;
}