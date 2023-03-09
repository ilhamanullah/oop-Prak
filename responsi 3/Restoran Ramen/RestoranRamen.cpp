#include <iostream>
#include <map>
#include "RestoranRamen.hpp"
using namespace std;

void RestoranRamen::tambahOrder(int n, int p){
    daftarMeja[n] += p;
}

int RestoranRamen::tutupOrder(int n){
    int total = daftarMeja[n];
    daftarMeja.erase(n);
    return total;
}

int RestoranRamen::cekTotal(int n){
    return daftarMeja[n];
}

int RestoranRamen::totalMeja(){
    return daftarMeja.size();
}

void RestoranRamen::cetakMeja(){
    if (daftarMeja.size() == 0){
        cout << "Restoran kosong" << endl;
    }
    else{
        for (auto it = daftarMeja.begin(); it != daftarMeja.end(); it++){
            cout << "Meja " << it->first << " = " << it->second << endl;
        }
    }
}