/** Amazon VMWare RiverBed
Given a read only array of n + 1 integers between 1 and n,
find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input: [3 4 1 4 1]
Sample Output: 1
If there are multiple possible answers ( like in the sample case above ), output any one.
If there is no duplicate, output -1
**/
int Solution::repeatedNumber(const vector<int> &A) {
  int arr[A.size()];
  for(int i=0; i<A.size(); i++)
    arr[i] = 0;
  for(auto a:A) {
    arr[a-1]++;
    if(arr[a-1] >= 2) return a;
  }
  return -1;
}

//Approach2 : Incorrect solution given in editorial of the question
//Investigate about how its working as it returned 3 for test case [1,2,3]
int Solution::repeatedNumber(const vector<int> &A) {
  int n = A.size();
  long long int sum = 0;
  for(int i = 0; i<n; i++){
    sum += A[i];
  }
  long long int m = n-1;
  long long int total = (m * (m+1)) / 2;
  return sum - total;
}
