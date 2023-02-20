#include <bits/stdc++.h>
#include "Kompleks.h"
using namespace std;

int Kompleks :: n_kompleks = 0;

Kompleks::Kompleks(){
	this->real = 0;
	this->imaginer = 0;
	n_kompleks++;
}

Kompleks::Kompleks(int real, int imaginer){
	this->real = real;
	this->imaginer = imaginer;
	n_kompleks++;
}

int Kompleks::GetReal() const{
	return this->real;
}

int Kompleks::GetImaginer() const {
	return this->imaginer;
}

void Kompleks::SetReal(int a){
	real = a;
}

void Kompleks::SetImaginer(int a){
	imaginer = a;
}

Kompleks operator+ (const Kompleks& a, const Kompleks& b ){
	Kompleks res;
	res.SetReal(a.GetReal() + b.GetReal());
	res.SetImaginer(a.GetImaginer() + b.GetImaginer());
	return res;
}

Kompleks operator- (const Kompleks& a, const Kompleks& b){
	Kompleks res;
	res.SetReal(a.GetReal() - b.GetReal());
	res.SetImaginer(a.GetImaginer() - b.GetImaginer());
	return res;
}

Kompleks operator* (const Kompleks& a, const Kompleks& b){
	Kompleks res;
	int v = a.GetReal(), w = a.GetImaginer(), x = b.GetReal(), y = b.GetImaginer();
	res.SetReal(v*x - w*y);
	res.SetImaginer(w*x + v*y);
	return res;
}

Kompleks operator* (const Kompleks& a, const int b){
	Kompleks res;
	res.SetReal(a.GetReal() * b);
	res.SetImaginer(a.GetImaginer() * b);
	return res;
}

Kompleks operator* (const int a, const Kompleks& b){
	Kompleks res;
	res.SetReal(b.GetReal() * a);
	res.SetImaginer(b.GetImaginer() * a);
	return res;
}

int Kompleks::CountKompleksInstance(){
	return n_kompleks;
}

void Kompleks::Print(){
	cout<<this->real;
	if(this->imaginer >= 0){
		cout << "+" << this->imaginer << "i\n";
	}
	else cout << this->imaginer << "i\n";
}