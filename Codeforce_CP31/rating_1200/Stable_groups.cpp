#include<iostream>
#include<vector>


using namespace std;

int main(){
    int n;
    long long k,x;
    cin>>n>>k>>x;
    vector<long long>vec(n);
    long long ans = 1;
    for(int i=0 ; i<n ; i++){
        cin>>vec[i];
    }

    sort(vec.begin(), vec.end());

    vector<long long>diffs;

    for(int i=0 ; i<n-1 ; i++){
        long long diff = vec[i+1] - vec[i];
        if(diff <= x){
            continue;
        }

        diffs.push_back(diff);
        ans++;
    }

    sort(diffs.begin(), diffs.end());
    
    for(int i=0 ; i<diffs.size() ; i++){
        if(!k){
            break;
        }
        long long need = ((diffs[i]+x-1)/x)-1;
        if(k>=need){
            k-=need;
            ans--;
        }else{
            break;
        }
    }



    cout<<ans<<endl;


    return 0;
}