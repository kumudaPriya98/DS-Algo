#include <bits/stdc++.h> 
using namespace std;

/*************************************************
Problem : https://www.interviewbit.com/problems/count-element-occurence/
TEST CASE :
370 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 
4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 
4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 
5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 
6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 7 7 7 7 7 7 7 7 7 
7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 8 8 
8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 
8 8 8 8 8 8 8 8 8 8 8 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 10 10 10 10 10 
10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 
10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
Search 2
Occurences : 37
*************************************************/

void binarySearch(const vector<int> &A, int B, int &start, int &end, int low, int high) {
    if(low > high) return; 
    
    int mid = low + (high - low)/2;
    if(A[mid] == B){
        if(start == -1) {
            start = mid;
            end = mid;
            binarySearch(A,B,start,end, low, mid-1);
            binarySearch(A,B,start,end, mid+1, high);
        }
        else if(start > mid) {
            start = mid;
            binarySearch(A,B,start,end, low, mid-1);
        }
        else if(end < mid) {
            end = mid;
            binarySearch(A,B,start,end, mid+1, high);
        }
    }
    else if (A[mid] > B) {
        binarySearch(A,B,start,end, low, mid-1);
    }
    else {
        binarySearch(A,B,start,end, mid+1, high);
    }    
}

int findCount(const vector<int> &A, int B) {
    int start = -1;
    int end = A.size();
    binarySearch(A, B, start, end, 0, end-1);

    if(start == -1) return 0;
    return (end - start + 1);    
}

int main() {
    int n;
    cin >> n;
    
    vector<int> A;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    sort(A.begin(), A.end());
    
    int x;
    cout << "Search  : ";
    cin >> x;
    cout << "Occurences : " << findCount(A, x) << endl;

    return 0;
}