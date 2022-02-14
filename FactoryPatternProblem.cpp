#include <iostream>
#include <thread>
#include <vector>
using namespace std;

enum struct mem_storage:int{
    FILE,
    DB,
    INVALID
};

class MemoryStorageType{
public:
    virtual void printMemoryType() = 0;
};

class Ram :public MemoryStorageType{
public:
    void printMemoryType()
    {
        cout << "Using RAM memory" << endl;
    }
};

class Rom :public MemoryStorageType{
public:
    void printMemoryType()
    {
        cout << "Using ROM memory" << endl;
    }
};

class MemoryType //Client invokes it
{
public:
    MemoryType(const mem_storage& type){
        if (type == mem_storage::FILE){
            memory_type = new Ram();
        }
        else if (type == mem_storage::DB){
            memory_type = new Rom();
        }
        else{
            memory_type = nullptr;
        }
    }

    MemoryStorageType* get_memType(){
        return memory_type;
    }

    ~MemoryType(){
        if (memory_type){
            delete[] memory_type;
            memory_type = nullptr;
        }
    }
private:
    MemoryStorageType* memory_type = nullptr;
};

int main()
{ 
    MemoryType m_type(mem_storage::FILE);
    MemoryStorageType* memory_type = m_type.get_memType();
    if (memory_type)
    {
        memory_type->printMemoryType();
    }    
    return 0;
}