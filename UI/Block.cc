#include "Block.h"

Block::Block(string name_init){
    this->name = name_init;
}

Block::~Block(){
    while(this->heroes.size()){
        Hero* hero = this->heroes.back();
        this->heroes.pop_back();
        delete hero;
    }
}

void Block::move(vector <Hero*> heroes){
    this->heroes = heroes;
}

void Block::print(void){
    for(int i = 0; i < this->heroes.size(); i++){
        cout << "Hero: " << i+1 << " is:" << endl; 
        this->heroes.at(i)->print();
    }
}

int Block::getSize(void){
    return this->heroes.size();
}

void Block::setName(string name){
    this->name = name;
}

string Block::getName(void){
    return this->name;
}

void Block::clear(void){
    this->heroes.clear();
}