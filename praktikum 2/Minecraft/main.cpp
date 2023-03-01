#include <bits/stdc++.h>
#include "Tool.hpp"
#include "ReinforcedAxe.hpp"
#include "Pickaxe.hpp"

using namespace std;

int main(){
    Pickaxe *p1 = new Pickaxe();
    p1->use();
    p1->enchant();
    Pickaxe *p2 = new Pickaxe(*p1);
    Pickaxe *p3 = new Pickaxe();
    *p3 = *p3;
    ReinforcedAxe *a1 = new ReinforcedAxe();
    a1->use();
    ReinforcedAxe *a2 = new ReinforcedAxe(*a1);
    a2->enchant();
    ReinforcedAxe *a3 = new ReinforcedAxe(*a1 + *a2);
    a3->repair();
    delete a1;
    delete a2;
    delete a3;
    delete p1;
    delete p2;
}