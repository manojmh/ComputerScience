/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
Constraints:
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
**/
class MinStack {
  stack<long long> s;
  long long minEle = LLONG_MAX;
public:
  /** initialize your data structure here. */
  MinStack() {
    while(!s.empty()) s.pop();
  }

  void push(int val) {
    if(s.empty()) {
      s.push(val);
      minEle = val;
      return;
    }
    if(minEle < val)
      s.push(val);
    else {
      s.push((long long)2*val-minEle);
      minEle = val;
    }
  }

  void pop() {
    if(s.empty())
      return;
    if(s.top() >= minEle)
      s.pop();
    else {
      minEle = 2*minEle-s.top();
      s.pop();
    }
  }

  int top() {
    if(s.empty()) return -1;
    if(s.top()<minEle)
      return minEle;
    return s.top();
  }

  int getMin() {
    if(s.empty()) return -1;
    return minEle;
  }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
