#include <iostream>
using namespace std;

class Superhero
{
public:
    static Superhero *instance();

    Superhero(Superhero const&) = delete;
    void operator=(Superhero const&) = delete;

    string get_name();

private:
    Superhero();
    ~Superhero();

    string name;
};

//constructor
Superhero::Superhero() 
{
    name = "Superman";
}

//destructor
Superhero::~Superhero()
{}

Superhero* Superhero::instance() {
    
    static Superhero instance;

    return &instance;
}

string Superhero::get_name() {
    return name;
}

int main()
{
    cout << "The only superhero is "<< Superhero::instance()->get_name() << endl;
    return 1;
}
