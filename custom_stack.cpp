#include <iostream>
#include <vector>
using namespace std;

//Creating a custom container
template <class T>

class Stack {

//Creating a Vector
private:
  vector<T> data;

public:

//Push, Pop, empty and size functions
  void push(T value) {
    data.push_back(value);
  }
  T pop() {
    T value = data.back();
    data.pop_back();
    return value;
  }
  bool empty() {
    return data.empty();
  }
  int size() {
    return data.size();
  }
};

int main() {

  Stack<int> stack;
//Pushing values
  stack.push(10);
  stack.push(20);
  stack.push(30);
//Printing the size of the stack(Vector)
  cout<<"Size of the stack : "<<stack.size()<<endl;
//Printing the values of the stack
  while (!stack.empty()) {
    cout << stack.pop() << endl;
  }

  return 0;
}
