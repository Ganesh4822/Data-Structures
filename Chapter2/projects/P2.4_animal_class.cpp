/*
P-2.4 Write a simulator as in the previous project, but add a Boolean gender
field and a floating-point strength field to each Animal object. Now, if
two animals of the same type try to collide, then they only create a new
instance of that type of animal if they are of different genders. Otherwise,
if two animals of the same type and gender try to collide, then only the
one of larger strength survives.
*/
#include<iostream>
#include<ctime>

class Animal
{
    private:
        int type;
        bool gender; //0 - female 1 - male
        float strength;
    
    public:
        Animal(int _type,bool _gender, float _strength):type(_type),gender(_gender),strength(_strength){}

        static Animal* collide(Animal** obj1, Animal** obj2)
        {
            if((*obj1)->type != (*obj2)->type)
            {
                throw "Animals of different type connot collide";
            }
            else{
                if((*obj1)->gender != (*obj2)->gender)
                {   srand(time(0));
                    return new Animal((*obj1)->type,rand() & 1,(((*obj1)->strength + (*obj2)->strength)/2));
                }
                else{
                    if((*obj1)->strength > (*obj2)->strength)
                    {
                        delete (*obj2);
                        (*obj2) = 0;
                        std::cout<<"other Animal is dead"<<std::endl;
                    }
                    else
                    {
                        delete (*obj1);
                        (*obj1) = 0;
                        std::cout<<"Animal obj1 is dead"<<std::endl;
                    
                    }
                }
            }

            return NULL;
            
        }

        void show_animal_info()
        {
            std::cout<<"type :: "<<this->type<<" gender :: "<<this->gender<<" strnegth :: "<<this->strength;
        }
};


int delete_object(Animal** obj)
{
   
        if(obj != 0)
        {
            std::cout<<"here"<<std::endl;
            delete (*obj);
            *obj = 0;
            return 1;
        }
        else{
            return 0;
        }
         
}


int main(void)
{
    Animal* A1 =  new Animal(1,0,5.0);
    Animal* A2 =  new Animal(1,0,7.0);
    Animal* A3 = Animal::collide(&A1,&A2);
    if(A3 != 0)
    {
        A3->show_animal_info();
    }

    std::cout<<A1<<std::endl;
    std::cout<<A2<<std::endl;
    std::cout<<A3<<std::endl;
    
    delete_object(&A1);
    delete_object(&A2);
    delete_object(&A3);

    std::cout<<"SUCCESS"<<std::endl;



}