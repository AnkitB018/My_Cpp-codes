#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class segment_tree{
    vector<int>seg_min;
    vector<int>seg_max;
    vector<int>org;

    public:
        segment_tree(const vector<int>&A): org(A), seg_max(4*A.size(), 0), seg_min(4*A.size(), 0){}

        void build_min(int idx, int low, int high){
            if(low == high){
                seg_min[idx] = low;
                return;
            }

            int mid = low + (high-low)/2;
            build_min(2*idx+1, low, mid);    
            build_min(2*idx+2, mid+1, high);

            int L = seg_min[2*idx+1];
            int H = seg_min[2*idx+2];

            seg_min[idx] = org[L]<org[H]?L:H;
        }

        void build_max(int idx, int low, int high){
            if(low == high){
                seg_max[idx] = low;
                return;
            }

            int mid = low + (high-low)/2;
            build_max(2*idx+1, low, mid);    
            build_max(2*idx+2, mid+1, high);

            int L = seg_max[2*idx+1];
            int H = seg_max[2*idx+2];

            seg_max[idx] = org[L]>org[H]?L:H;

        }

        int query_max(int idx, int low, int high, int l, int r){
            if(low>=l && r >= high){ // completely inside
                return seg_max[idx];
            }else if(high<l || low > r){ //completely outside
                return -1;
            }else{ //partially overlapping
                int mid = low + (high - low)/2;
                int left = query_max(2*idx+1, low, mid, l, r);
                int right = query_max(2*idx+2, mid+1, high, l, r);
                if(left == -1){
                    return right;
                }else if(right ==-1){
                    return left;
                }
                return org[left]>org[right]?left:right;
            }
        }

        int query_min(int idx, int low, int high, int l, int r){
            if(low>=l && r >= high){ // completely inside
                return seg_min[idx];
            }else if(high<l || low > r){ //completely outside
                return -1;
            }else{ //full or partially overlapping
                int mid = low + (high - low)/2;
                int left = query_min(2*idx+1, low, mid, l, r);
                int right = query_min(2*idx+2, mid+1, high, l, r);
                if(left == -1){
                    return right;
                }else if(right == -1){
                    return left;
                }   

                return org[left]<org[right]?left:right;
            }
        }

};


int main(){
    int test;
    cin>>test;
    while(test--){
        cout<<endl;
        int n;
        cin>>n;
        vector<int>vec(n);

        for(int i=0 ; i<n ; i++){
            cin>>vec[i]; //O(n)
        }
        segment_tree seg(vec);
        seg.build_max(0, 0, n-1); //O(n)
        seg.build_min(0, 0, n-1); //O(n)

        int q;
        cin>>q;
        vector<pair<int, int>>queries;
        for(int i=0 ; i<q ; i++){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            queries.push_back({l, r});
        } //O(q)
        
        vector<pair<int, int>>ans;
        for(int i=0 ; i<q ; i++){
            auto [l, r] = queries[i];
            int small = seg.query_min(0, 0, n-1, l, r);
            int big = seg.query_max(0, 0, n-1, l, r);

            if(vec[small] == vec[big]){
                ans.push_back({-2, -2});
            }else{
                ans.push_back({min(small, big), max(small, big)});
            }

        } //O(qlogn)

        for(int i=0 ; i<ans.size() ; i++){
            cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
        } //O(q)


        //O(qlogn)

    }


    return 0;
}