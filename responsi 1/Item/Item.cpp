#include<bits/stdc++.h>
#include "Item.hpp"
using namespace std;

int Item::totalItems = 0;
int Item::totalRevenue = 0;


Item::Item() : serialNum(this->totalItems+1){
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
    totalItems++;
}

Item::Item(int stock, int price) : serialNum(this->totalItems+1){
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems++;
}

Item:: Item(const Item &newItem) : serialNum(this->totalItems+1){
    this->stock = newItem.stock;
    this->price = newItem.price;
    this->sold = 0;
    totalItems++;
}

Item::~Item(){}

int Item::getSerialNum() const {
    return this->serialNum;
}

int Item::getSold() const {
    return this->sold;
}

int Item::getPrice() const {
    return this->price;
}

void Item::addStock(int addedStock){
    this->stock+=addedStock;
}

void Item::sell(int soldStock){
    if(this->stock < soldStock){
        this->sold += this->stock;
        totalRevenue += (this->stock * this->price);
        this->stock = 0;
    }
    else{
        this->sold += soldStock;
        totalRevenue += (soldStock * this->price);
        this->stock -= soldStock;
    }
}

void Item::setPrice(int newPrice){
    this->price = newPrice;
}