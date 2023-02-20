#include <bits/stdc++.h>
#include "Polinom.hpp"
using namespace std;

Polinom :: Polinom(){
    this -> derajat = 0;
    this -> koef = new int[0];
}
Polinom :: Polinom(int n){
    this -> derajat = n;
    this -> koef = new int[n + 1];
}
Polinom :: Polinom(const Polinom &newPolinom){
    this -> derajat = newPolinom.derajat;
    this -> koef = new int[newPolinom.derajat];
    if(this -> derajat > 0){
        for(int i=0; i <= this -> derajat; i++){
            this -> koef[i] = newPolinom.koef[i];
        }
    }
    else this -> koef[0] = newPolinom.koef[0];
}
Polinom :: ~Polinom(){
    delete[] this -> koef;
}

Polinom& Polinom :: operator=(const Polinom& newPolinom){
    this -> derajat = newPolinom.derajat;
    delete[] this -> koef;
    this -> koef = new int[newPolinom.derajat + 1];
    if(this -> derajat > 0){
        for(int i=0; i <= this -> derajat; i++){
            this -> koef[i] = newPolinom.koef[i];
        }
    }
    else this -> koef[0] = newPolinom.koef[0];
    return *this;
}

int Polinom :: getKoefAt(int idx) const {
    return this-> koef[idx];
}

int Polinom :: getDerajat() const {
    return this -> derajat;
}

void Polinom :: setKoefAt(int idx, int val) {
    this -> koef[idx] = val;
}

void Polinom :: setDerajat(int n){
    this -> derajat = n;
    delete[] this -> koef;
    this -> koef = new int[this -> derajat + 1];
}

void Polinom :: input(){
    for(int i=0; i <= this -> derajat; i++){
        int n;
        cin >> n;
        this -> koef[i] = n;
    }
}

void Polinom :: printKoef(){
    for(int i = 0; i<= this -> derajat; i++){
        cout << this -> koef[i] << endl;
    }
}

int Polinom :: substitute(int n){
    int ans = this -> koef[0];
    for(int i=1; i <= this -> derajat; i++){
        int temp = n;
        for(int j=1; j<i; j++){
            temp *= n;
        }
        ans += temp * this -> koef[i];
    }
    return ans;
}

void Polinom :: print(){
    bool a = false;
    for(int i=0; i<= this -> derajat; i++){
        if(i == 0){
            if(this -> koef[i] != 0) {
                cout << this -> koef[i];
                a = true;
            }
        }
        else{
            if(this -> koef[i] != 0){
                if(a){
                    if(this -> koef[i] > 0){
                        cout << "+" << this -> koef[i] << "x^"<<i;
                    }
                    else if(this -> koef[i] < 0){
                        cout << this -> koef[i] << "x^"<<i;
                    }
                }
                else {
                    if(this -> koef[i] > 0){
                        cout << this -> koef << "x^"<<i;
                        a = true;
                    }
                    else if(this -> koef[i] < 0){
                        cout << this -> koef << "x^"<<i;
                        a = true;
                    }
                }
            }
        }
    }
    if(!a) cout << "0";
    cout << endl;
}