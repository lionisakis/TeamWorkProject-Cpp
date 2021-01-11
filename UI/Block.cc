#include "Block.h"

Block::Block(string name_init){
    this->name = name_init;
}

Block::~Block(){
    while(this->heroes.size()){
        Hero* hero = this->heroes.back();
        this->heroes.pop_back();
    }
}

void Block::move(vector <Hero*> heroes){
    this->heroes = heroes;
}

void Block::print(void)const{
    for(int i = 0; i < this->heroes.size(); i++){
        cout << "Hero: " << i+1 << " is:" << endl; 
        this->heroes.at(i)->print();
    }
}

int Block::getSize(void)const{
    return this->heroes.size();
}

void Block::setName(string name){
    this->name = name;
}

string Block::getName(void)const{
    return this->name;
}

void Block::clear(void){
    this->heroes.clear();
}