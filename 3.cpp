#include <iostream>
#include <queue>
#include <string>   

using namespace std;


int main()
{
  queue<string> words;


  cout << "Before sorting:\n" << endl;

  words.push("Apple");
  cout << words.back() << endl;
  words.push("Asus");
  cout << words.back() << endl;
  words.push("Gvido Van Rossum");
  cout << words.back() << endl;
  words.push("Bjarne Stroustrup");
  cout << words.back() << endl;
  words.push("Anders Hejlsberg");
  cout << words.back() << endl;
  words.push("James Gosling");
  cout << words.back() << endl;
  words.push("Google");
  cout << words.back() << endl;
  words.push("Gmail");
  cout << words.back() << endl;

  cout << endl;

  queue<string> sorted_words;
  queue<string> temp_words;

  int size = words.size();

  while (sorted_words.size() != size) {

    int max = words.front().length();

    while (words.size() != 0) {
      if (words.front().length() > max) {
        max = words.front().length();
      }
      temp_words.push(words.front());
      words.pop();
    }


    while (temp_words.size() != 0) {

      if (temp_words.front().length() == max) {
        sorted_words.push(temp_words.front());
        temp_words.pop();
      }
      else {
        words.push(temp_words.front());
        temp_words.pop();
      }

    }
  }

  cout << "After sorting:\n" << endl;

  while (sorted_words.size() != 0) {
    cout << sorted_words.front() << endl;
    sorted_words.pop();
  }

  return 0;
}