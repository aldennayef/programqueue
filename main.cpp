#include<iostream>
using namespace std;
#define MAX 5

struct Antrian {
    int data[MAX];
    int head = -1;
    int tail = -1;
};

Antrian antre;
void create();
bool isEmpty();
bool isFull();
void enqueue(int);
void dequeue();
void tampil();
void Clear();

int main(){
    int pilih,urut,p=1;
    do{
        cout << "=== ANTRIAN PUSKESMAS BATANG I ===" << endl;
        cout << "==================================" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Panggil Antrian" << endl;
        cout << "3. Lihat Daftar Antrian" << endl;
        cout << "4. Clear Antrian" << endl;
        cout << "5. Exit" << endl;
        cout << "==================================" << endl;
        cout << "Pilih = ";
        cin >> pilih;
        cout << endl;
        if(pilih==1){
            if(isFull()){
                cout << "Antrian udah penuh" << endl;
            }
            else{
                urut = p;
                enqueue(urut);
                cout << "No. Antrian " << p << " Silakan Mengantri\nMenunggu " << antre.tail << " Antrian" << endl;
                p++;
            }
        }
        else if(pilih==2){
            cout << "No. Antri " << antre.data[antre.head];
            dequeue();
            cout << " Silakan dipanggil" << endl;
        }
        else if(pilih==3){
            tampil();
        }
        else if(pilih==4){
            Clear();
            cout << "Antrian dikosongkan" << endl;
        }
        else if(pilih==5){

        }
        else{
            cout << "Eror" << endl;
        }
    }while(pilih!=5);
    return 0;
}

void create(){
    antre.head = antre.tail =-1;
}

bool isEmpty(){
    if(antre.tail == -1){
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(){
    if(antre.tail == MAX - 1){
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int data){
    if(isEmpty()){
        antre.head = antre.tail = 0;
        //antre.data[antre.tail] = data;
    }
    else
    {
        antre.tail++;
    }
    antre.data[antre.tail] = data;
    cout<<data<<" dimasukkan ke antrian\n";
}

void dequeue(){
    if(isEmpty()){
        cout << "Antriannya kosong !!!" << endl;
    }
    else{
        int i;
        //int e = antre.data[antre.head];
        for(i = antre.head;i < antre.tail;i++){
            antre.data[i] = antre.data[i+1];
        }
        antre.tail--;
        //return e;
    }
}

void tampil(){
    if(!isEmpty()){
        for(int i = antre.head;i <= antre.tail;i++){
            cout<< "Antrian no. " << antre.data[i] << endl;
        }
    }
    else{
        cout<<"Antrian kosong" << endl;;
    }
}
void Clear(){
    antre.head=antre.tail=-1;
}
