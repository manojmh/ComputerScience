/**
Special Keyboard 
Medium Accuracy: 33.67% Submissions: 6050 Points: 4
Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
Find maximum numbers of A's that can be produced by pressing keys on the special keyboard N times. 
Example 1:
Input: N = 3
Output: 3
Explaination: Press key 1 three times.
Example 2:
Input: N = 7
Output: 9
Explaination: The best key sequence is 
key 1, key 1, key 1, key 2, key 3,
key4, key 4.
Your Task:
You do not need to read input or print anything.
Your task is to complete the function optimalKeys() which takes N as
input parameter and returns the maximum number of A's that can be on the screen after performing N operations.
Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)
Constraints:
1 < N < 75

Intution :
Till N=6 keys will remain as N
From 7 onwards, we have 3 possibilities:
Ex: N=7
AAAAAAA=>7A
AAAA ^A^C^V => AAAA ^A^C AAAA can be written as => AAAA ^A^C f(4) => f(4)*^A^C*f(4) => 2*f(4) => 8A's
AAA ^A^C^V^V => AAA ^A^C AAA AAA can be written as => AAA ^A^C f(3) f(3) => f(3)*^A^C*f(3)f(3) => 3*f(3) => 9A's
AA ^A^C^V^V^V => AA ^A^C AA AA AA can be written as => AA ^A^C f(2) f(2) f(2) => f(2)*^A^C*f(2)f(2)f(2) => 4*f(2) => 8A's
A ^A^C^V^V^V^V => A ^A^C A A A A can be written as => A ^A^C f(1) f(1) f(1) f(1) => f(1)*^A^C*f(1)f(1)f(1)f(1) => 5*f(2) => 5A's
So maximum out of above choices is 9A's
**/
class Solution{
public:
  long long int optimalKeys(int N){
    if(N<=6)
      return N;

    int dp[N];
    for(int n=1; n<=6; n++)
      dp[n-1] = n;

    for(int n=7; n<=N; n++)
      // for any keystroke n, we will need to choose between:-
      // 1. pressing Ctrl-V once after copying the
      // A's obtained by n-3 keystrokes.

      // 2. pressing Ctrl-V twice after copying the A's
      // obtained by n-4 keystrokes.

      // 3. pressing Ctrl-V thrice after copying the A's
      // obtained by n-5 keystrokes.
      dp[n-1] = max(2*dp[n-4], max(3*dp[n-5], 4*dp[n-6]));
    return dp[N-1];
  }
};
