#include <iostream>
#include <variant>
class Animal
{
public:
    virtual void speak() = 0;
    static Animal* createAnimal(int type);
};

class Dog:public Animal
{
public:
    void speak()
    {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat :public Animal
{
public:
    void speak()
    {
        std::cout << "Meow!" << std::endl;
    }
};

Animal* Animal::createAnimal(int type)
{
    if (type == 1)
    {
        return new Dog();
    }
    else if (type == 2)
    {
        return new Cat();
    }
    else
    {
        nullptr;
    }
}

int main() 
{  
    Animal* dog = Animal::createAnimal(1);
    dog->speak();
    
    Animal* cat = Animal::createAnimal(2);
    cat->speak();
    return 0;
}
