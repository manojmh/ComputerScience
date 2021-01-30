/**
Merge Sort : Split the array then do sorted merge
**/

#include <bits/stdc++.h>
using namespace std;

void merge(int res[], int l, int m, int r) {
	int n1 = m-l+1;
	int n2 = r-m;

	int a[n1];
	int b[n2];

	for(int i=0; i<n1; i++)
		a[i] = res[l+i];
	for(int i=0; i<n2; i++)
		b[i] = res[m+i+1];

	int i = 0, j = 0;
	int k = l;

	while(i<n1 && j<n2) {
		if(a[i]<=b[j])
			res[k++] = a[i++];
		else
			res[k++] = b[j++];
	}
	while(i<n1)
			res[k++] = a[i++];
	while(j<n2)
			res[k++] = b[j++];
}

void mergeSort(int a[], int l, int r) {
	if(l>=r) return;
	int mid = (l+r)/2;
	mergeSort(a, l, mid);
	mergeSort(a, mid+1, r);
	merge(a, l, mid, r);
}

int main() {
	for(;;) {
		int n;
		cin >> n;
		int a[n];
		for(int i=0; i<n; i++) cin >> a[i];

		mergeSort(a, 0, n);

		for(int i=0; i<n; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}
