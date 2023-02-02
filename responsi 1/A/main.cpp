#include <bits/stdc++.h>
#include "A.hpp"
using namespace std;

int main(){
    A* satu = new A('1');
    A* dua = new A('2');
    A* csatu = new A (*satu);
    (*csatu) = (*dua);
    (*csatu).show();
    delete(csatu);
    delete(dua);
    delete(satu);

}