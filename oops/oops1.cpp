#include<iostream>
// #include "Hero.cpp"
using namespace std;

class Hero {
    // properties
    private:
        int health;

    public:
        char name[100];
        char level;

    Hero() {
        cout<<"Constructor called"<<endl;
    }

    // parameterized constructor
    Hero(int health){
        this->health = health;
    }

    int getHealth() {
        return health;
    }

    void setHealth(int h) {
        health = h;
    }
};

int main() {
    cout<<"hi"<<endl;
    Hero h1;
    cout<<"size :"<<sizeof(h1)<<endl;
    // h1.health = 70;
    // h1.level = 'A';
    h1.setHealth(70);
    cout<<"h1 health is<< "<<h1.getHealth()<<endl;
    cout<<"h1 level is "<<h1.level<<endl;
    return 0;
} 