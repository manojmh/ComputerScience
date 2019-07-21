/*
https://www.youtube.com/watch?v=2xUJTXeBZmE&list=PL5jc9xFGsL8FWtnZBeTqZBbniyw0uHyaH&index=5
Output:
6
564564356
*/

//Converts binary number to integer number
int operator"" b(const char *s, size_t l) {
    int res = 0;
    for(int i=0; i<l; i++) {
        res = res << 1;
        if(s[i] == '1')
            res += 1;
    }
    return res;
}

int main() {
    cout << "110"b << endl;
    cout << "100001101001101001000110000100"b << endl;
}
