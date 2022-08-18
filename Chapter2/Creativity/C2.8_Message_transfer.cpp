/*
C-2.8 Write a set of C++ classes that can simulate an Internet application, where
one party, Alice, is periodically creating a set of packets that she wants to
send to Bob. The Internet process is continually checking if Alice has any
packets to send, and if so, it delivers them to Bob’s computer, and Bob is
periodically checking if his computer has a packet from Alice, and, if so,
he reads and deletes it.
*/

#include<iostream>
#include<dos.h>

class Alice
{
    private:
    friend class Bob;
    friend Bob* transfer_message(Alice* alice_object);
    std::string message;
    static int object_count;
    
    public:
        
        Alice(std::string _message):message(_message)
        {
            object_count++;
        }

        // std::string send_message()
        // {
        //     if(object_count > 0)
        //     {
        //         return message;
        //     }
        //     object_count--;
        //     delete(this);
        // }
        

};
int Alice:: object_count = 0;



class Bob
{
    private:
    std::string message;
    
    public:
    Bob(std::string _message):message(_message){}
    // Bob& get_message(Alice& alice_object)
    // {
    //     if(Alice::object_count > 0)
    //     {
    //         return Bob(alice_object.send_message());    
    //     }
    // }
    std::string read_message()
    {
        return message;
    }
};

Bob* transfer_message(Alice* alice_object)
{
    if(Alice::object_count > 0)
    {   
        std::string _message =  alice_object->message;
        Alice::object_count--;
        delete alice_object;
        alice_object = NULL;
        return new Bob(_message);

    }
    return NULL;
}


int main()
{
    static std::string  messgae;

       while(1)
       {
        std::cout<<"Enter the message Alice"<<std::endl;
        std::cin>>messgae;
        _sleep(1000);
        Alice* a = new Alice(messgae);
        _sleep(1000);
        Bob* b = transfer_message(a);
        std::cout<<"message received for Bob"<<std::endl;
        std::cout<<b->read_message()<<std::endl;
        delete(b);
        b = NULL;
        
       }

}