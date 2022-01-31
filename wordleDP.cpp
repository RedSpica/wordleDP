#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<tuple>
#include<vector>
#include<cassert>
#include<cstdlib>
#include<cstdint>
#include<stdio.h>
#include<cmath>
#include<limits>
#include<iomanip> 
#include<ctime>
#include<climits>
#include<random>
#include<queue>
#include<deque>
#include<map>
#include<time.h>
#include<set>


using namespace std;

template <class T> using V = vector<T>;

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}


const long long INF = 1LL << 60;
const double pi=acos(-1);

using ll = long long;
using vll = V<ll>;
using vvll = V<V<ll>>;
using vpll =V<pair<ll,ll>>;
using graph = V<V<ll>>;
using mp = map<ll,ll>;


#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define bgn begin()
#define en end()
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).bgn,(a).en)
#define fi first
#define se second
#define gcd(a,b) __gcd(a,b)
#define ALL(a)  (a).begin(),(a).end()


template<typename T>
std::vector<T> make_vec(size_t n){
  return std::vector<T>(n);
}

template<typename T, class... Args>
auto make_vec(size_t n, Args... args){
  return std::vector<decltype(make_vec<T>(args...))>(n,make_vec<T>(args...));
}





void Solve();


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(20)<<fixed;
  
  Solve();
}


/****************************************\
| Thank you for viewing my code:)        |
| Written by RedSpica a.k.a. RanseMirage |
| Twitter:@asakaakasaka                  | 
\****************************************/

void Solve(){
  ll up=67108864;
  ll n;
    cin>>n;
  vector<string> S(n);

  FOR(i,0,n){
    cin>>S[i];
  }

  vector<char> dict={'q','x','j','z','v','w','f','k','b','g',
                    'h','m','p','c','y','d','u','n','t','l',
                    'i','r','o','a','e','s'};


  vector<vector<ll>> dp(up,vector<ll>(2LL,200LL));

  dp[0][0]=0;
  FOR(i,0,n){
    string t=S[i];
    ll key=0;
    
    FOR(j,0,5LL){
      ll pos=t[j]-'a';
      key|=((1LL)<<pos);
    }

    FOR(s,0,up){
      if((s & key)!=0){
        continue;
      }

      if(dp[s|key][0]>dp[s][0]+1){
        dp[s|key]={dp[s][0]+1};
        FOR(j,1,dp[s][0]+1){
          dp[s|key].push_back(dp[s][j]);
        }
        dp[s|key].push_back(i);
        continue;
      }
    }
  }

  ll res=0;
  FOR(s,0,up){
    if(dp[s][0]==5LL){
      ll cur=s;
      ll cnt=0;
      while(cur>0){
        cnt+=cur%2;
        cur/=2;
      }
      if(cnt==25){
        cout<<cnt<<"\n";
        FOR(i,1,6){
          cout<<S[dp[s][i]]<<" ";
        }
        cout<<"\n";
        
      }
      chmax(res,cnt);
    }
  }

  cout<<res<<"\n";

  return;
}