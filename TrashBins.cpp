#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int z = t;
    while(t--){
        int n;
        int distCount= 0;
        cin>>n;
        char a[n];
        cin>>a;
        n = strlen(a);
        for(int i=0;i<n;i++){
            if(!a[i]){
                int status = 0;
                int q = 0;
                while(!status){
                    if((a[i-q]-48) && (i-q)>=0) status = 1;
                    else if((a[i+q]-48) && (i+q)<n) status = 1;
                    else q++;

                }
                distCount += q;
            }
        }
        cout<<"Case #"<<(z-t)<<": "<<distCount<<endl;
    }
}