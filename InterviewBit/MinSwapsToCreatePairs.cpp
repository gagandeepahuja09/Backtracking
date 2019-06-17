/*
Minimum number of swaps required for arranging pairs adjacent to each other

There are A pairs and therefore 2A people. Each person has a unique number ranging from 1 to 2A. An array of integers B shows the arrangement of these 2N people.

A matrix C of size N x 2 is given describing pairs i.e. people that are partner of each other. C[i][0] and C[i][1] are partner of each other.

Find the minimum number of swaps required to arrange these pairs such that all pairs become adjacent to each other.


Input Format

The First argument given is an integer A.
The Second argument given is the integer array B.
The Third argument given is matrix C.

Output Format

Return the minimum number of swaps required to arrange these pairs such that all pairs become adjacent to each other

Constraints

1 <= A <= 20
1 <= B[i] <= 2*A
C[i][0]!=C[i][1]
1 <= C[i][0], C[i][1] <= 2*A

For Example

Input 1:
    A = 3
    B = [3, 5, 6, 4, 1, 2]
    C = [   [1, 3]
            [2, 6]
            [4, 5]  ]
Output 1:
    2
    Explanation 1:
        One of the ways to arraange them 
        1. swap(5 and 6) order becomes : [3, 6, 5, 4, 1, 2]
        2. swap(6 and 1) order becomes:  [3, 1, 5, 4, 6, 2]
*/

void minSwaps(vector<int>& B, int i, int cnt, int& ans, map<int, int>& mp) {
    if(i >= B.size()) {
        ans = min(ans, cnt);
        return;
    }
    if(i < B.size() - 1) {
        if(mp[B[i]] == B[i + 1]) {
            minSwaps(B, i + 2, cnt, ans, mp);
        }
        else {
            int p;
            for(int k = 0; k < B.size(); k++) {
                if(mp[B[i]] == B[k])
                    p = k;
            }
            swap(B[i + 1], B[p]);
            minSwaps(B, i + 2, cnt + 1, ans, mp);
            swap(B[i + 1], B[p]);
        }
        if(mp[B[i + 1]] == B[i]) {
            minSwaps(B, i + 2, cnt, ans, mp);
        }
        else {
            int p;
            for(int k = 0; k < B.size(); k++) {
                if(mp[B[i + 1]] == B[k])
                    p = k;
            }
            swap(B[i], B[p]);
            minSwaps(B, i + 2, cnt + 1, ans, mp);
            swap(B[i], B[p]);
        }
    }
}

int Solution::solve(int A, vector<int> &B, vector<vector<int> > &C) {
    map<int, int> mp;
    for(int i = 0; i < C.size(); i++) {
        mp[C[i][0]] = C[i][1];
        mp[C[i][1]] = C[i][0];
    }
    int ans = B.size() / 2;
    minSwaps(B, 0, 0, ans, mp);
    return ans;
}

