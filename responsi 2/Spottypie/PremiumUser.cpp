#include <iostream>
using namespace std;

#include "PremiumUser.h"
#include <cstring>

PremiumUser::PremiumUser(char *namapengguna) : User(namapengguna){
    this->num_of_music_downloaded = 0;
    this->active = true;
}

PremiumUser::PremiumUser(const PremiumUser &other) : User(other.name){
    this->num_of_favourite_music = other.num_of_favourite_music;
    this->music_list = new char *[5000];

    for (int i = 0; i < other.num_of_favourite_music; i++){
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }

    this->num_of_music_downloaded = other.num_of_music_downloaded;
    this->active = other.active;
}

PremiumUser::~PremiumUser(){}

void PremiumUser::downloadMusic(char *music){
    if (this->active){
        this->num_of_music_downloaded++;
        cout << "Music Downloaded: " << music << endl;
    }else{
        cout << "Activate premium account to download music" << endl;
    }
}

void PremiumUser::inactivatePremium(){
    this->active = false;
}

void PremiumUser::activatePremium(){
    this->active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const{
    return this->num_of_music_downloaded;
}

bool PremiumUser::getPremiumStatus() const{
    return this->active;
}