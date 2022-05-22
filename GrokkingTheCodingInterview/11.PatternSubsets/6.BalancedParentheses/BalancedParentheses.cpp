/*
For a given number ‘N’, write a function to generate all combination of ‘N’ pairs of balanced parentheses.
Example 1:
Input: N=2
Output: (()), ()()

Example 2:
Input: N=3
Output: ((())), (()()), (())(), ()(()), ()()()
*/
vector<string> BalancedParanthesis(int num) {
  if(num < 1) return vector<string>();

	vector<string> res;
	queue<ParaString> q;
	q.push({"", 0, 0});
	while(!q.empty()) {
    ParaString ps(q.front());
		q.pop();
		if(ps.open == num && ps.close == num)
			res.push_back(ps.str);
		else {
			if(ps.open<num)
				q.push({ps.str+"(", ps.open+1, ps.close});
			if(ps.open > ps.close)
				q.push({ps.str+")", ps.open, ps.close+1});
		}
	}
	return res;
}
