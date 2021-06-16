/**
You are given the following :
A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return list of actual order of persons’s height
Consider that heights will be unique
Example
Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4 
So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.
For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.
You can do similar inference for other people in the list.

Explaination:
In a nutshell, we are given 2 lists A,B, such that A[i] is the height of person i, and 
B[i] is how many people should be standing in front of him (i.e. to the left side in the queue).
The lists are not necessarily in the correct order, but each pair A[i],B[i] must stick together, because they belong to the same person.
Your job is to re-order the lists, such that the order becomes correct.
For example:
Heights : 5 3 2 6 1 4
Infronts: 0 1 2 0 3 2
According to these arrays, there are 0 persons in front of ‘5’ that are taller than him. So 5’s order is correct.
And there is 1 person in front of 3 that is taller than him. Also this one is correct, because only 5 is in front of him.
Regarding 2, there are 2 persons in front of him that are taller than him (3 and 5). So its order is also correct.
Moving on to 6, it says that there are 0 persons in front of him that are taller than him. Still correct (5,3,2 are in front of him, but no one is taller).
Now we come to 1. It says that there are 3 persons in front of him that are taller than him. But this is incorrect,
because in the current order there are 4 persons (5,3,2,6). So we must re-arrange this guy, and move him to the correct position (in this case one to the left).
But also its corresponding Infronts[i] must move together with him.
The last person (4) is in the correct order (5,3,2,6,1) are in front of him, but only two are taller than him (5,6).
So the final order is:
Heights : 5 3 2 1 6 4
Infronts: 0 1 2 3 0 2
And the answer is just the Heights array.
**/
vector<int> Solution::order(vector<int> &A, vector<int> &B) {
  vector<int> res;
  priority_queue<pair<int,int>> pq;
  for(int i=0;i<A.size();i++)
    pq.push({A[i],B[i]});
  int n=A.size();
  while(n--){
    int top=pq.top().first;
    int val=pq.top().second;
    pq.pop();
    res.insert(res.begin()+val, top);
  }
  return res;
}
