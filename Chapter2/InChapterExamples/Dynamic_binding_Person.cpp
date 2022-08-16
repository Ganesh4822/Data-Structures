#include<iostream>

class Person
{
    private:
        std::string name;
        int age;
    public:
        
        Person(std::string _name, int _age):name(_name),age(_age){}
        virtual void print();
        std::string geName();

};



class Student : public Person
{
    private:
        std::string major;
        int gradYear;
    public:
        Student();
        Student(std::string _name, int _age, std::string _major, int _gradYear):Person(_name,_age),
        major(_major),
        gradYear(_gradYear)
        {

        }
        void print();
        void changeMajor();
        int getGradYear();
};

void Person::print()
{
    std::cout<<"Name is "<<this->name<<"and the age is "<<this->age<<std::endl;
}

void Student::print()
{
    Person::print();
    std::cout<<"Major subject is"<<this->major<<std::endl;
}


int main()
{
    Person person("Ganesh",22);
    Student student("A",28,"physics",2024);
    Person *pp[2];

    pp[0] =  new Person("HImanshiu",22);
    pp[1] = new Student("B",26,"maths",2045);
    person.print();//Person::print() will be called
    student.print();//student::print() will be called
    std::cout<<"------------------------------------------------"<<std::endl;
    pp[0]->print();//Person::print() will be called
    pp[1]->print();//derived::peint() will be called as it is declared as virtaul
    //dynamic binfing occures using the Vtable
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"size of student object is "<< sizeof(*(pp[1]))<<std::endl;
    //Vptr is included hence the size of object increases
    std::cout<<"size of Person object is "<< sizeof(*(pp[0]))<<std::endl;
    delete(pp[0]);
    delete(pp[1]);

//     The reason for this apparently anomalous behavior is called static binding—when
// determining which member function to call, C++’s default action is to consider an
// object’s declared type,


}