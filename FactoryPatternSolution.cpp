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
    static MemoryStorageType* getMemoryType(const mem_storage& mType);

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

MemoryStorageType* MemoryStorageType::getMemoryType(const mem_storage& mType)
{
    if (mType == mem_storage::FILE) {
        return new Ram();
    }
    else if (mType == mem_storage::DB) {
        return new Rom();
    }
    else {
        return nullptr;
    }
}

class MemoryType //Client invokes it
{
public:
    MemoryType(const mem_storage& type){
        memory_type = MemoryStorageType::getMemoryType(type);
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
    if (memory_type){
        memory_type->printMemoryType();
    } 
    else
    {
        cout << "memory type is nullptr" << endl;
    }
    return 0;
}