#ifndef HEWAN_H
#define HEWAN_H
#include <bits/stdc++.h>
using namespace std;


class Hewan {
    protected :
        string nama;
    
    public :
        Hewan(string nama){
            this -> nama = nama;
        }
        ~Hewan(){
            cout << "Hewan mati "<< this -> nama << endl;
        }
        virtual void print(){
            cout << "Hewan ini namanya " << this -> nama << endl;
        }

};

class Anjing : public Hewan {
    public :
        Anjing(string nama) : Hewan(nama){};
        ~Anjing(){
            cout << "Anjing mati " << this -> nama << endl;
        };
        void print(){
            cout << "Anjing ini namanya " << this -> nama << endl;
        }
};

class Kucing : public Hewan{
    public :
        Kucing(string nama) : Hewan(nama){};
        virtual ~Kucing(){
            cout << "Kucing mati "<< this -> nama << endl;
        }
        void print(){
            // cout << "Kucing ini namanya " << this -> nama << endl;
            Hewan :: print();
        }
};

class AnjingBulldog : public Anjing{
    private :
        string pemilik;
    
    public :
        AnjingBulldog(string name, string ownerName) : Anjing(name) {
            pemilik = ownerName;
        }
        ~AnjingBulldog(){
            cout << "Anjing bulldog mati " << this -> nama << endl;
        }
        void print() {
            cout << "Anjing bulldog ini namanya " << this -> nama << ". Pemiliknya adalah " << this -> pemilik << endl;
        }
};

class KucingAnggora : public Kucing{
    private :
        string pemilik;
    
    public : 
        KucingAnggora(string name, string ownerName) : Kucing(name){
            pemilik = ownerName;
        }
        ~KucingAnggora(){
            cout << "Kucing anggora mati " << this -> nama << endl;
        }
        void print(){
            cout << "Kucing anggora ini namanya " << this -> nama << ". Pemiliknya adalah " << this -> pemilik << endl;
        }
};

#endif