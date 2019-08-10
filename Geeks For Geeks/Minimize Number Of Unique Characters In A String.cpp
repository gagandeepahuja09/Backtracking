#include<bits/stdc++.h>
using namespace std;

/*
Minimize number of unique characters in string

Given two strings A and B. Minimize the number of unique characters in string A by either swapping A[i] with B[i] or keeping it unchanged. The number of swaps can be greater than or equal to 0. Note that A[i] can be swapped only with same index element in B. Print the minimum number of unique characters. Constraints: 0 < length of A ≤ 15.
*/

int ans;
unordered_map<char, int> mp;

void f(string A, string B, int i, unordered_map<char, int>& mp) {
	if(i == A.size()) {
		ans = min(ans, (int)mp.size());
		return;
	}
	mp[A[i]]++;
	f(A, B, i + 1, mp);
	mp[A[i]]--;
	if(mp[A[i]] == 0)
		mp.erase(A[i]);

	swap(A[i], B[i]);
	mp[A[i]]++;
	f(A, B, i + 1, mp);
	mp[A[i]]--;
	if(mp[A[i]] == 0)
		mp.erase(A[i]);	
	swap(A[i], B[i]);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string A, B;
		cin >> A >> B;
		ans = INT_MAX;
		f(A, B, 0, mp);
		cout << ans << endl;
	}
}
