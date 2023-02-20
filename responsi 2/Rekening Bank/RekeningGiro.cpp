#include <bits/stdc++.h>
#include "RekeningGiro.h"

using namespace std;

RekeningGiro :: RekeningGiro (double saldo, double sukubunga) : Rekening :: Rekening(saldo){
    if(sukubunga > 0) this -> sukuBunga = sukubunga;
    else this -> sukuBunga = 0.0;
}
void RekeningGiro :: setSukuBunga (double sukubunga) {
    this -> sukuBunga = sukuBunga;
}
double RekeningGiro :: getSukuBunga() const {
    return this -> sukuBunga;
}
double RekeningGiro :: hitungBunga(){
    return this -> getSaldo() * this -> sukuBunga;
}