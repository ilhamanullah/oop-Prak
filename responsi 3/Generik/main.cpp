#include "Generik.cpp"
#include <iostream>
using namespace std;

int main(){
    int i = 65;
    int a = 4;
    func(i,a);
    // func
    func<char,int> (i,a);
}