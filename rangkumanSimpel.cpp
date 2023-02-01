#include <bits/stdc++.h>
using namespace std;

int main(){
    /*
    rangkuman penulisan kodingan

    format :
    - penulisan pada main
    - penulisan pada class
    */


    // Ambil contoh untuk program card pada praktikum oop 20/21

    Card *card1 = new Card(1);
    Card::Card(int n){} // berlaku juga tanpa parameter tidak usah parameter pada konstruktornya

    (*card0) = (*card1);
    Card &Card :: operator = (const Card &card){}

    (*card1).gesek();
    void Card :: gesek(){}; // 'gesek' bisa diganti apapun

    Card *card2 = new Card(*card2);
    Card::Card(const Card &card){}

    Card *card6 = card2
    // tidak perlu pembuatan konstruktor tambahan
    // langsung dideklarasi card6 isinya sama seperti card 2

    Card card10 = Card(10);
    // Ini sama saja seperti pada line 25, perbedaannya karena ini disimpan dalam stack maka 
    // jika terdapat destruktor langsung dihapus setelah melewati destruktor

    Card card7;
    Card :: Card() // konstruktor tanpa parameter

    card7 = card10;
    // Ini sama saja seperti pada line 19, perbedaannya karena ini disimpan dalam stack maka   
    // jika terdapat destruktor langsung dihapus setelah melewati destruktor

    delete card1;
    // fungsinya sama seperti destruktor tetapi untuk menghapus secara manual
}