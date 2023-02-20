#include <bits/stdc++.h>
#include "Rekening.h"

using namespace std;

Rekening :: Rekening (double saldo) {
    if (saldo > 0) this -> saldo = saldo;
    else this -> saldo = 0.0;
}
void Rekening :: setSaldo (double saldo) {
    this -> saldo = saldo;
}
double Rekening :: getSaldo() const {
    return this -> saldo;
}
void Rekening :: simpanUang(double uang) {
    this -> saldo += uang;
}
bool Rekening :: tarikUang(double tarikuang){
    if(this -> saldo >= tarikuang){
        this -> saldo -= tarikuang;
        return true;
    }
    else return false;
}