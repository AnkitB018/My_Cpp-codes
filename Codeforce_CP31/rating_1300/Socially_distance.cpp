#include<iostream>
#include<vector>


using namespace std;

int main(){
    int test;
    scanf("%d", &test);

    while(test--){
        int n;
        scanf("%d", &n);
        
        vector<int>perm(n);
        

        for(int i=0 ; i<n ; i++){
            cin>>perm[i];
        }

        vector<int>ans;
        ans.push_back(perm[0]);
        for(int i=1 ; i<n-1; i++){
            if(perm[i] > perm[i+1] && perm[i] > perm[i-1]){
                ans.push_back(perm[i]);
            }
            if(perm[i] < perm[i+1] && perm[i] < perm[i-1]){
                ans.push_back(perm[i]);
            }
        }
        ans.push_back(perm[n-1]);

        cout<<ans.size()<<endl;
        for(int i=0 ; i<ans.size() ; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }

    return 0;
}