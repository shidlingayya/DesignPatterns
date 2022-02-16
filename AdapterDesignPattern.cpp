#include <iostream>
class ProductMsgFrameWork{
public:
    virtual void msgProcessBasedOnXML() = 0;
};

class RefMsgFrameWork{
public:
    virtual void msgProcessBasedOnJSN()
    {
        std::cout << "Process the JSON Message" << std::endl;
    }
};

class Adaptor:public ProductMsgFrameWork, public RefMsgFrameWork{ //Adaptor
public:
    void msgProcessBasedOnXML()
    {
        //Convert from XML->JSON
        msgProcessBasedOnJSN();
    }
};

int main() //Client
{
    std::unique_ptr<ProductMsgFrameWork> msgProcess = std::make_unique<Adaptor>();
    msgProcess->msgProcessBasedOnXML();
    return 0;
}