#include <bits/stdc++.h>
#include "RekeningTabungan.h"

using namespace std;

RekeningTabungan :: RekeningTabungan(double saldo, double biayatransaksi) : Rekening :: Rekening(saldo){
    if(biayatransaksi > 0) this -> biayaTransaksi = biayatransaksi;
    else this -> biayaTransaksi = 0.0;
}
void RekeningTabungan :: setBiayaTransaksi(double biayatransaksi){
    this -> biayaTransaksi = biayatransaksi;
}
double RekeningTabungan :: getBiayaTransaksi() const {
    return this -> biayaTransaksi;
}
void RekeningTabungan :: simpanUang(double uang){
    Rekening :: simpanUang(uang);
    setSaldo(this -> getSaldo() - this -> biayaTransaksi);
}
bool RekeningTabungan :: tarikUang(double tarik){
    if(Rekening::tarikUang(tarik)){
        setSaldo(this -> getSaldo() - this -> biayaTransaksi);
        return true;
    }
    else return false;
}
