#include <bits/stdc++.h> 
using namespace std;
#define DEBUG_PRINT 1

int binarySearchDiv(const vector<int> &v, const int val, int &steps, int start, int end) {
    if(start > end) return -1;

    steps++;
#if DEBUG_PRINT 
    cout << "step : " << steps << ", [" << start << "," << end << "]" << endl;
#endif

    /* 
     * To avoid overflow of mid
     * incase of large array size,
     * whose length fits in 32bit
     */
    int mid = start + (end - start)/2;
    if(v[mid] == val) return mid;
    if(v[mid] > val) return binarySearchDiv(v, val, steps, start, mid-1);
    else return binarySearchDiv(v, val, steps, mid+1, end);
}

int binarySearch(const vector<int> &v, const int val, int &steps){
    steps = 0;
    return binarySearchDiv(v, val, steps, 0, v.size()-1);
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
    int x, steps;
    while(true) {        
        cout << "Search : ";
        cin >> x;
        cout << "Sorted Index : " << binarySearch(A, x, steps);
        cout <<  " Steps: " << steps << endl; 
    }
    return 0;
}