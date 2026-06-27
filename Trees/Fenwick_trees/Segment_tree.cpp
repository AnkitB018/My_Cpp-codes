#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Segment_tree{
    vector<int>seg;
    vector<int>original;
    public:
        Segment_tree(const vector<int> &org): seg(4*org.size(), 0), original(org){}

        void build(int idx, int low, int high){
            if(low == high){
                seg[idx] = original[low];
                return;
            }
            int mid = low+(high-low)/2;
            build(2*idx+1, low, mid);
            build(2*idx+2, mid+1, high);

            seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
        }

        int query(int idx, int low, int high, int l, int r);

};


int Segment_tree::query(int idx, int low, int high, int l, int r){
    if(l<=low && high<=r){ //completely inside
        return seg[idx];
    }else if(high<l || low>r){ // not inside
        return INT_MIN;
    }else{ //partial
        int mid = low+(high-low)/2;
        int left = query(2*idx+1, low, mid, l ,r );
        int right = query(2*idx+2, mid+1, high, l, r);
        return max(left, right);
    }
}


int main(){
    vector<int>vec = {5, 7, 2, 5, 8,9, 12, 1, 0, 7, 18, 16, 1, 3, 76, 89, 0, 17};
    int n= vec.size();
    Segment_tree seg(vec);

    seg.build(0, 0, n-1);
    cout<<seg.query(0, 0, n-1, 8, 12)<<endl;
}