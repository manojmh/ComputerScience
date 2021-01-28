/**
Permute produces all the combinations of the string
Output:
------------------------------------------------------------------------------------------------------------------------
Enter a string for finding permutations : abc
abc acb bac bca cba cab
Enter a string for finding permutations : abcd
abcd abdc acbd acdb adcb adbc bacd badc bcad bcda bdca bdac cbad cbda cabd cadb cdab cdba dbca dbac dcba dcab dacb dabc
Enter a string for finding permutations : 123
123 132 213 231 321 312
Enter a string for finding permutations : 1234
1234 1243 1324 1342 1432 1423 2134 2143 2314 2341 2431 2413 3214 3241 3124 3142 3412 3421 4231 4213 4321 4312 4132 4123
------------------------------------------------------------------------------------------------------------------------
**/

#include <iostream>
using namespace std;

void permute(string str, uint8_t left, uint8_t right) {
	if(left == right) {
		cout << str << " ";
		return;
	}

	for(uint8_t i = left; i <= right; i++) {
		swap(str[i], str[left]);
		permute(str, left+1, right);
		swap(str[i], str[left]);
	}
}

int main() {
	for(;;) {
		string str;
		cout << "\nEnter a string for finding permutations : ";
		cin >> str;

		permute(str, 0, str.size()-1);
	}
}
