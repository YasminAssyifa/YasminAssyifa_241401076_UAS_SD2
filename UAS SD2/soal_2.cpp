#include <iostream>
#include <string>
using namespace std;

struct pesanan{
    string nama;
    int berat;
    int urutan;
    int jenis;
};

#define MAX 50
int queue[MAX];
int front = -1, rear = -1;

int n;
pesanan *Pesanan = nullptr;

void enqueue(int value){
    if(rear == MAX -1){
        cout << "Queue penuh !\n";
        return;
    } else {
        if (front == -1)front = 0;

        rear++;
        queue[rear] = value;

        cin.ignore();

        cout<<"Pesanan "<< value+1 << endl;
        cout<<"Nama: ";  getline(cin, Pesanan[value].nama);
        cout<<"Berat: "; cin>>Pesanan[value].berat;
        Pesanan[value].urutan = value+1;
        cout<<"Jenis Layanan (1=reguler, 2=express): "; cin>>Pesanan[value].jenis;
        cout<<endl;

    }
}

void totalWaktu(int n){
    int totWaktu = 0;
    for (int i=0; i<n; i++){
        if (Pesanan[i].jenis == 1){
            totWaktu += (Pesanan[i].berat * 10);
        }
        else if (Pesanan[i].jenis == 2){
            totWaktu += (Pesanan[i].berat * 5);
        }

    }
    cout<< totWaktu;
}

void sortPesanan(int n){
    for (int i=0; i < n - 1; i++){
        for (int j = 0; j < n - 1; j++){
            if(Pesanan[j].jenis < Pesanan[j+1].jenis){
                pesanan temp = Pesanan[j];
                Pesanan[j] = Pesanan[j + 1];
                Pesanan[j + 1] = temp;
            }
        }    
    }
}

int main(){
    system("CLS");
    cout << "Masukkan jumlah pelanggan: "; cin >> n;

    Pesanan = new pesanan[n];

    for (int i=0; i<n; i++){
        enqueue(i);
    }

    sortPesanan(n);
    
    cout<< "urutan: ";
    for (int i=0; i<n; i++){
        cout<<Pesanan[i].nama<<" ";
    }
    cout<<endl;

    cout<<"total waktu: "; totalWaktu(n); cout<<" menit";
}