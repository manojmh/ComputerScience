/**
Find maximum in a stack in O(1) time and O(1) extra space
https://www.geeksforgeeks.org/find-maximum-in-a-stack-in-o1-time-and-o1-extra-space/
Given a stack of integers. The task is to design a special stack such that maximum element can be found in O(1) time and O(1) extra space.
Examples:
Given Stack :
2
5
1
64   --> Maximum
So Output must be 64 when getMax() is called.
Below are the different functions designed to push and pop elements from the stack.
Push(x) : Inserts x at the top of stack.
If stack is empty, insert x into the stack and make maxEle equal to x.
If stack is not empty, compare x with maxEle. Two cases arise:
If x is less than or equal to maxEle, simply insert x.
If x is greater than maxEle, insert (2*x – maxEle) into the stack and make maxEle equal to x.
For example, let previous maxEle was 3. Now we want to insert 4. We update maxEle as 4 and insert 2*4 – 3 = 5 into the stack.
Pop() : Removes an element from top of stack.
Remove element from top. Let the removed element be y. Two cases arise:
If y is less than or equal to maxEle, the maximum element in the stack is still maxEle.
If y is greater than maxEle, the maximum element now becomes (2*maxEle – y), so update (maxEle = 2*maxEle – y).
This is where we retrieve previous maximum from current maximum and its value in stack.
For example, let the element to be removed be 5 and maxEle be 4. We remove 5 and update maxEle as 2*4 – 5 = 3.
Important Points:
Stack doesn’t hold actual value of an element if it is maximum so far.
Actual maximum element is always stored in maxEle
Illustration
Push(x)
Number to be Inserted: 3, Stack is empty, so insert 3 into stack and maxEle = 3.
Number to be Inserted: 5, Stack is not empty, 5> maxEle, insert (2*5-3) into stack and maxEle = 5.
Number to be Inserted: 2, Stack is not empty, 2< maxEle, insert 2 into stack and maxEle = 5.
Number to be Inserted: 1, Stack is not empty, 1< maxEle, insert 1 into stack and maxEle = 5.
Pop()
Initially the maximum element maxEle in the stack is 5.
Number removed: 1, Since 1 is less than maxEle just pop 1. maxEle=5.
Number removed: 2, 2<maxEle, so number removed is 2 and maxEle is still equal to 5.
Number removed: 7, 7> maxEle, original number is maxEle which is 5 and new maxEle = 2*5 – 7 = 3.
**/
#include <bits/stdc++.h>
using namespace std;
struct MyStack {
  stack<int> s;
  int maxEle;

  void getMax() {
    if (s.empty())
      cout << "Stack is empty\n";
    else
      cout << "Maximum Element in the stack is: " << maxEle << "\n";
  }
  
  void peek() {
    if (s.empty()) {
      cout << "Stack is empty ";
      return;
    }
    int t = s.top(); // Top element.
    cout << "Top Most Element is: " << (t > maxEle) ?  maxEle :  t << endl;
  }

  void pop() {
    if (s.empty()) {
      cout << "Stack is empty\n";
      return;
    }
    cout << "Top Most Element Removed: ";
    int t = s.top();
    s.pop();
    if (t > maxEle) {
      cout << maxEle << "\n";
      maxEle = 2 * maxEle - t;
    }
    else
      cout << t << "\n";
  }

  void push(int x) {
    if (s.empty()) {
      maxEle = x;
      s.push(x);
      cout << "Number Inserted: " << x << "\n";
      return;
    }
    if (x > maxEle) {
        s.push(2 * x - maxEle);
        maxEle = x;
    }
    else
        s.push(x);
    cout << "Number Inserted: " << x << "\n";
  }
};

int main()
{
  MyStack s;
  s.push(3);
  s.push(5);
  s.getMax();
  s.push(7);
  s.push(19);
  s.getMax();
  s.pop();
  s.getMax();
  s.pop();
  s.peek();
  return 0;
}
