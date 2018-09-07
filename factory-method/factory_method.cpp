#include<iostream>
#include<vector>
using namespace std;

enum{
    superman,
    batman,
    ironman
};

class SuperHero
{
public:
    //Super hero factory method
    static SuperHero *spawn(int choice);
    virtual void who() = 0;
};

class Superman : public SuperHero
{
public:
    void who() override 
    {
        cout <<"I am Superman\n";
    }
};

class Batman : public SuperHero
{
public:
    void who() override 
    {
        cout <<"I am Batman\n";
    }
};

class Ironman : public SuperHero
{
public:
    void who() override 
    {
        cout <<"I am Ironman\n";
    }
};

SuperHero *SuperHero::spawn(int choice)
{
    if (choice == superman){
        return new Superman;
    } else if (choice == batman){
        return new Batman;
    } else {
        return new Ironman; 
    }
}

int main()
{
    vector<SuperHero*> heros;

    heros.push_back(SuperHero::spawn(superman));
    heros.push_back(SuperHero::spawn(batman));
    heros.push_back(SuperHero::spawn(ironman));

    for(SuperHero* hero : heros)
    {
        hero->who();
    }

    return 1;
}
