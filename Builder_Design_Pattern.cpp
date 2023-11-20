/*
* File:builder.cpp
* This file is described the builder Design Pattern with help of example
* Author: Alpha Master
* Date: 17 April 2021
*/

//Header File
#include<iostream>
#include<memory>

//Engine
class Engine
{
    int m_Power;
public:
    void setPower(int pw) { m_Power = pw; }
    int getPower() { return m_Power; }
};

//Body
class Body
{
    int m_BodySize;
public:
    void setBody(int sz) { m_BodySize = sz; }
    int getBody() { return m_BodySize; }
};

//Wheel
class Wheel
{
    int m_WheelSize;
public:
    void setWheel(int sz) { m_WheelSize = sz; }
    int getWheel() { return m_WheelSize; }
};

//Car Class
class Car
{
    //Data member MUST BE PRIVATE  but here I am using as public for demo example
public:
    Engine m_eng;
    Body m_body;
    Wheel m_wh;
public:

};

//HyundaiCarBuilder
class IHyundaiCarBuilder
{
protected:
    std::unique_ptr<Car>m_car;
public:
    virtual void BuildEngine() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildWheel() = 0;
    virtual std::unique_ptr<Car> GetCar() = 0;
};

//Car_i10Builder
class Car_i10Builder : public IHyundaiCarBuilder
{
public:
    Car_i10Builder()
    {
        m_car.reset(new Car);
    }
    ~Car_i10Builder() {}
    void BuildEngine() { m_car->m_eng.setPower(1000); }
    void BuildBody() { m_car->m_body.setBody(100); }
    void BuildWheel() { m_car->m_wh.setWheel(10); }
    std::unique_ptr<Car> GetCar()
    {
        std::cout << "Car i10 is ready" << std::endl;
        return std::move(m_car);
    }
};

//Car_i20Builder
class Car_i20Builder : public IHyundaiCarBuilder
{
public:
    Car_i20Builder()
    {
        m_car.reset(new Car);
    }
    ~Car_i20Builder() {}
    void BuildEngine() { m_car->m_eng.setPower(2000); }
    void BuildBody() { m_car->m_body.setBody(200); }
    void BuildWheel() { m_car->m_wh.setWheel(20); }
    std::unique_ptr<Car> GetCar()
    {
        std::cout << "Car i20 is ready" << std::endl;
        return std::move(m_car);
    }
};


//Director
class Director
{
    std::unique_ptr<IHyundaiCarBuilder>m_builder;
public:
    Director()
    {}
    void SetBuilder(std::unique_ptr<IHyundaiCarBuilder>& build)
    {
        m_builder.reset(build.release());
    }
    void Construct()
    {
        m_builder->BuildEngine();
        m_builder->BuildBody();
        m_builder->BuildWheel();
    }
    std::unique_ptr<Car> GetCar()
    {
        std::cout << "Get Car in Director" << std::endl;
        return std::move(m_builder->GetCar());
    }
};

//Client
int main()
{
    std::cout << "Builder Design Pattern" << std::endl;
    std::cout << "Using i10 Builder for building i10" << std::endl;
    std::unique_ptr<IHyundaiCarBuilder>build{ new Car_i10Builder };
    std::unique_ptr<Director>dir{ new Director };
    dir->SetBuilder(build);
    dir->Construct();
    std::unique_ptr<Car>car{ dir->GetCar() };
    std::cout << "Engine Power:" << (*car).m_eng.getPower() << std::endl;
    std::cout << "Body Size:" << (*car).m_body.getBody() << std::endl;
    std::cout << "Wheel Size:" << (*car).m_wh.getWheel() << std::endl;

    std::cout << "Using i20 Builder for building i20" << std::endl;
    build.reset(new Car_i20Builder);
    dir->SetBuilder(build);
    dir->Construct();
    car.reset(dir->GetCar().release());
    std::cout << "Engine Power:" << (*car).m_eng.getPower() << std::endl;
    std::cout << "Body Size:" << (*car).m_body.getBody() << std::endl;
    std::cout << "Wheel Size:" << (*car).m_wh.getWheel() << std::endl;
    return 0;
}
