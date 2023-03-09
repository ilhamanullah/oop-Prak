#include "sekretaris.h"
#include <iostream>

using namespace std;

Sekretaris::Sekretaris() {
	this -> energi = ENERGI_MAX;
	this -> tinta = TINTA_DEFAULT;
	this -> kertas = KERTAS_DEFAULT;
	this -> memoLength = 0;
	this -> memo = new Memo[100];
}

Sekretaris::Sekretaris(int kertas, int tinta) {
	this -> energi = ENERGI_MAX;
	this -> tinta = tinta;
	this -> kertas = kertas;
	this -> memoLength = 0;
	this -> memo = new Memo[100];
}

Sekretaris::~Sekretaris() {
    delete [] this -> memo;
}

void Sekretaris::buatMemo(string pesan, string untuk) {
	try {
		Memo temp(pesan, untuk);
		memo[memoLength] = temp;
		pakaiKertas();
		pakaiTinta(pesan.length());
		pakaiEnergi();
		memoLength++;
		cout << "Memo [" << memoLength << "] untuk " << untuk << " berhasil dibuat" << endl;
	} 
	catch (KertasHabisException e) {
		cout << e.what() << ", segera isi kertas" << endl; 
	}
	catch (TintaKurangException e) {
		batalPakaiKertas();
		cout << e.what() << ", segera isi tinta" << endl;
	} 
	catch (EnergiHabisException e) {
		batalPakaiKertas();
		batalPakaiTinta(pesan.length());
		cout << e.what() << ", segera istirahat" << endl;
	} 
}

void Sekretaris::pakaiKertas() {
    if (kertas > 0) kertas--;
	else throw KertasHabisException();
}

void Sekretaris::pakaiTinta(int num) {
    if (tinta-num >= 0) tinta -= num;
	else  throw TintaKurangException();
}

void Sekretaris::pakaiEnergi() {
    if (energi > 0) energi--;
	else throw EnergiHabisException();
	
}

void Sekretaris::batalPakaiKertas() {
    kertas++;
}

void Sekretaris::batalPakaiTinta(int num) {
    tinta += num;
}

void Sekretaris::batalPakaiEnergi() {
    energi++;
}

void Sekretaris::isiTinta(int num) {
    tinta += num;
}

void Sekretaris::isiKertas(int num) {
    kertas += num;
}

void Sekretaris::istirahat() {
    energi = ENERGI_MAX;
}

void Sekretaris::printStatus() {
	cout << "Status" << endl;
	cout << "  Energi : " << energi << endl;
	cout << "  Tinta : " << tinta << endl;
	cout << "  Kertas : " << kertas << endl;
	cout << "  Memo : " << memoLength << endl;
	for (int i = 0; i < memoLength; i++) {
		cout << "    Memo [" <<  i+1 << "]" << endl;
		cout << "      Pesan : " << memo[i].getPesan() << endl;
		cout << "      Untuk : " << memo[i].getUntuk() << endl;
	}
}