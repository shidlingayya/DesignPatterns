#include <iostream>
using namespace std;

class Singleton
{
public:
    //Singletons should not be cloneable.
    Singleton(Singleton& other) = delete;

    //Singletons should not be assignable
    void operator=(const Singleton&) = delete;

    static Singleton* getInstance(){
        if (!instance)
        {
            instance = new Singleton();
        }
        return instance;
    }

    void getClassService(){
        cout << "Class service given to clients" << endl;
    }

private:
    /**
     * The Singleton's constructor should be private to prevent direct construction 
     * calls with the `new` operator.
     */
    Singleton(){}
    
    static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* instance = Singleton::getInstance();
    if (instance)
    {
        cout << "Address of instance: " << instance << endl;
        instance->getClassService();
    }

    Singleton* instance1 = Singleton::getInstance();
    if (instance1)
    {
        cout << "Address of instance: " << instance1 << endl;
        instance1->getClassService();
    }
    return 0;
}