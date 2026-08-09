#include<iostream>
#include<vector>

using namespace std;

int and_range(vector<vector<int>>&pre, int l, int r){
	int ans = 0;

	for(int i=0 ; i<30 ; i++){
		int zeros = pre[i][r] - (l?pre[i][l-1]:0);
		if(zeros == 0){
			ans += (1<<i);
		}
	}

	return ans;
}


int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int>a(n);

		for(int i=0 ; i<n ; i++){
			cin>>a[i];
		}

		vector<vector<int>>pre(30, vector<int>(n, 0));

		for(int i=0 ; i<30 ; i++){
			for(int j=0 ; j<n ; j++){
				if((1<<i) & a[j]){
					pre[i][j] = j==0?0:pre[i][j-1];
				}else{
					pre[i][j] = j==0?1:pre[i][j-1]+1;
				}
			}
		}

		int q;
		cin>>q;
		while(q--){
			int l, k;
			cin>>l>>k;
			l--;

			if(a[l] < k){
				cout<<-1<<" ";
				continue;
			}

			int r = n-1;
			int low =l;
			while(low <= r){
				int mid = low+(r-low)/2;

				if(and_range(pre, l, mid) >= k){
					low=mid+1;
				}else{
					r = mid-1;
				}
			}

			cout<<r+1<<" ";


		}

		cout<<endl;

	}

	return 0;
}