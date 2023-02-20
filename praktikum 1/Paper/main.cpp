#include <bits/stdc++.h>
#include "Paper.hpp"
using namespace std;

int main(){
	Paper *a = new Paper('A');
	Paper *b = new Paper('B');
	Paper *c = new Paper('C');
	Paper *Cc = new Paper(*c);
	a->fold();
	b->fold();
	c->fold();
	c->glue();
	c->setName('X');
	Cc->fold();
	Cc->glue();
	delete Cc;
	delete c;
	delete b;
	delete a;
}