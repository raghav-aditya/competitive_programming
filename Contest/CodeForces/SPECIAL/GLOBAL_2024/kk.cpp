#include<bits/stdc++.h>
using namespace std;

int main()
{   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin>>t;
   while (t--)
   {
    int n;
    string s;
    cin>>n>>s;
    int onecnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            onecnt++;
        }
    }
    bool consec=false;
    for(int i=0;i<n;i++){
        if(s[i]=='1' && s[i+1]=='1'){
            consec=true;
        }
    }
    if(onecnt%2==1  ||  (onecnt==2 && consec)){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
   }
}