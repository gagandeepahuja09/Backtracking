/*
Shuttle Puzzle Problem

We are given n White marbles and n Black marbles along with a strip with 2n+1 holes . The n White marbles are on the left side occupying the leftmost n holes and the n Black marbles are on the right side occupying the rightmost n holes. The middle hole i.e the n+1 hole is empty.

For example if n = 4 , then the initial configuration of the strip is - WWWWHBBBB, Where H denotes the empty hole.

Our Goal is to swap the sets, that is transfer all white marbles to right and black marbles to left with minimum valid moves.

Valid moves are : 1) Move 1 marble by 1 space (into the empty hole) 2) Jump 1 marble over 1 marble of the opposite color (into the empty hole).

Given n as input, output set of valid moves to achieve the transformation.

NOTE - The first move should be the slide of the White marble(At Hole number n-1) to the right.

Constraint -
n<=15

Example :

Input : n = 3

Output:

WWWHBBB

WWHWBBB The first move as mentioned is the slide of the white marble to the right.

WWBWHBB

WWBWBHB

WWBHBWB

WHBWBWB

HWBWBWB

BWHWBWB

BWBWHWB

BWBWBWH

BWBWBHW

BWBHBWW

BHBWBWW

BBHWBWW

BBBWHWW

BBBHWWW*/

vector<string> Solution::solve(int A) {
    string s, target;
    for(int i = 0; i < A; i++)
        s += "W", target += "B";
    s += "H", target += "H";    
    for(int i = 0; i < A; i++)
        s += "B", target += "W";
    queue<pair<string, vector<string>>> q;
    q.push({ s, { s }});
    while(!q.empty()) {
        string curr = q.front().first;
        vector<string> path = q.front().second; 
        q.pop();
        if(curr == target) {
            return path;
        }
        for(int i = 0; i < curr.size(); i++) {
            if((i < curr.size() - 1 && curr[i] == 'W' && curr[i + 1] == 'H') 
            || (i < curr.size() - 1 && curr[i] == 'H' && curr[i + 1] == 'B')) {
                string temp = curr;
                swap(temp[i], temp[i + 1]);
                vector<string> npath = path;
                npath.push_back(temp);
                q.push({ temp, npath });
            }
            if((i < curr.size() - 2 && curr[i] == 'H' 
            && curr[i + 1] == 'W' && curr[i + 2] == 'B') || 
            (i < curr.size() - 2 && curr[i] == 'W' 
            && curr[i + 1] == 'B' && curr[i + 2] == 'H')) {
                string temp = curr;
                swap(temp[i], temp[i + 2]);
                vector<string> npath = path;
                npath.push_back(temp);
                q.push({ temp, npath });        
            }
        }
    }
    return {};
}

