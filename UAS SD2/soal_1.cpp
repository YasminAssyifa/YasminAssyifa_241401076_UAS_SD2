#include <iostream>
#include <string>
using namespace std;

int sublim(int x, int n){
    int total = 0;
    for (int i=1; i<=n; i++){
        if ( i % 2 == 0){
            total -= x;
        }
        else{
            total += x;
        }
    }

    return total;
}

int main(){
    system("CLS");
    int n;
    cout<<"t: "; cin>>n;
    cout<<endl;

    int arr[n];

    for (int i=1; i<=n; i++){
        int x,n;
        cout<<"x: "; cin>>x;
        cout<<"n: "; cin>>n;
        cout<<endl;
        arr[i]=sublim(x, n);
    }

    for (int i=1; i<=n; i++){
        cout<<arr[i];
        cout<<endl;
    }
}