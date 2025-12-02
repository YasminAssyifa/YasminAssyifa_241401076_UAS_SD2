#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string noSpasi(string s) {
    s.erase( remove( s.begin(), s.end(), ' ' ), s.end() );
    s.erase( remove( s.begin(), s.end(), ',' ), s.end() );
    return s;
}

void Palindrom(string cek){

    cout<<"Hasil untuk '"<<cek<<"' : ";

    for(char &c : cek){
            c = toupper(c);
    }

    string temp = cek;
    int n = cek.length();

    for(int i = 0; i < n/2; i++){

            swap(cek[i], cek[n - i - 1]);
    }

    if (noSpasi(cek) == noSpasi(temp)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}

int main(){

    system("CLS");
    string cek;
    cout<<"Masukkan string yg ingin di periksa: "; getline(cin, cek);

    Palindrom(cek);
}