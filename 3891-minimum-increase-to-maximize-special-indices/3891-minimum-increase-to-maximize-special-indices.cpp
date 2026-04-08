class Solution {
    using ll=long long;
public:
    long long minIncrease(vector<int>&a) {
        ll n=a.size();

        ll result=0;
        if(n%2==1){
            for(ll i=1; i<n-1; i+=2){
                ll mx=max(a[i-1],a[i+1]);
                ll res=mx>=a[i] ? (mx-a[i])+1 : 0;
                result+=res;
            }
        }else{
            ll m=(n-2)/2;
            vector<ll>pre(m), suf(m);
            ll j=0;
            ll sum=0;
            for(ll i=1; i<n-1; i++){
                if(i%2==1){
                    ll mx=max(a[i-1],a[i+1]);
                    ll res=mx>=a[i] ? (mx-a[i])+1 : 0;
                    sum+=res;
                    pre[j]=sum;
                    j++;
                }
            }
            sum=0;
            j=m-1;
            for(ll i=n-2; i>1; i--){
                if(i%2==0){
                    ll mx=max(a[i-1],a[i+1]);
                    ll res=mx>=a[i] ? (mx-a[i])+1 : 0; 
                    sum+=res;
                    suf[j]=sum;
                    j--;
                }
            }

            result=min(pre[m-1],suf[0]);

            for(ll i=0; i<m-1; i++){
                result=min(result,pre[i]+suf[i+1]);
            }
        }
        return result;
    }
};

// 2, 3, 4, 5, 6, 2, 3, 4, 5, 7
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

// [1, 3, 5, 7]
// [1, 4, 6, 8]
// [1, 3, 6, 8]
// [1, 3, 5, 8]
// [2, 4, 6, 8]

// [0, x, y, z, d]
// [0, p, q, r, s]

// k=1
// if(k>0){
//    ans=min({ans,f(i+3, k-1),f(i+2, k)});  
// }
// else{
//    ans=min(ans,f(i+2, k)) 
// }

// diff=max(a[i-1],a[i+1])
// if(diff>a[i]) res+=(diff-a[i])+1;
