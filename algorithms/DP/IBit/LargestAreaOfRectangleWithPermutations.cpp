/**
https://www.interviewbit.com/old/problems/largest-area-of-rectangle-with-permutations/
Given a binary grid A of size N x M consisting of 0's and 1's, find the area of the largest rectangle inside
the grid such that all the cells inside the chosen rectangle should have 1 in them.
You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order in the final grid.
Please follow the sample input and explanation for more clarity.
Input Format
First and only argument is an 2D binary array A.
Output Format
Return a single integer denoting the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them.
Example Input
Input 1:
A =[[1, 0, 1]
    [0, 1 ,0]
    [1, 0, 0]
   ]
Example Output
Output 1: 2
Example Explanation
Explanation 1:
1 0 1
0 1 0
1 0 0
At present we can see that max rectangle satisfying the criteria mentioned in the problem
is of 1 * 1 = 1 area i.e either of the 4 cells which contain 1 in it.
Now since we are allowed to permutate the columns of the given matrix, we can take column 1
and column 3 and make them neighbours. One of the possible configuration of the grid can be:
1 1 0
0 0 1
1 0 0
Now In this grid, first column is column 1, second column is column 3 and third column
is column 2 from the original given grid.
Now, we can see that if we calculate the max area rectangle, we get max area as 1 * 2 = 2
which is bigger than the earlier case. Hence 2 will be the answer in this case.
Intution:
1) store the sum of each element row wise in column(this removes depency on columns of matrix, rows can be independently sorted)
2) sort the each row in decreasing order
3) find max in each row
4) find max in total
**/
int maxarea(vector<int> b){
  int mx=0;
  for(int i=0; i<b.size(); i++){
    int temp=(i+1)*b[i];
    mx=max(mx,temp);
  }
  return mx;
}
int Solution::solve(vector<vector<int> > &A) {
  for(int i=1; i<A.size(); i++){
    for(int j=0; j<A[i].size(); j++){
     if( A[i][j]!=0)
       A[i][j]+=A[i-1][j];
    }
  }
  int mx=0;                                                                                                            
  for(int i=0; i<A.size(); i++){
    vector<int> b = A[i];
    sort(b.begin(),b.end(),greater<int>());
    int temp=maxarea(b);
    mx=max(mx, temp);
  }
  return mx;
}
