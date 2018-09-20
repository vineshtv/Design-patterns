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
    static std::unique_ptr<SuperHero> spawn(int choice);
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

std::unique_ptr<SuperHero> SuperHero::spawn(int choice)
{
    if (choice == superman){
        return std::make_unique<Superman>();
    } else if (choice == batman){
        return std::make_unique<Batman>();
    } else {
        return std::make_unique<Ironman>();
    }
}

int main()
{
    vector<std::unique_ptr<SuperHero>> heros;
    heros.push_back(std::move(SuperHero::spawn(superman)));
    heros.push_back(std::move(SuperHero::spawn(batman)));
    heros.push_back(std::move(SuperHero::spawn(ironman)));
    
    for (auto& hero: heros)
    {
        hero->who();
    }

    return 1;
}
