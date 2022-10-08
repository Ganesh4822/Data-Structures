/*
P-3.3 Write a class that maintains the top 10 scores for a game application, implementing the add and remove functions of Section 3.1.1, but use a singly
linked list instead of an array.
*/
#include<iostream>
#include<stdexcept>
#include<forward_list>
#include<string>

class GameEntry
{
    private:
        std::string name;
        int score;
    
    public:
        GameEntry(std::string _name = "" , int _score = 0):name(_name),score(_score){}

        std::string getName() const
        {
            return name;
        }

        int getScore() const
        {
            return score;
        }

};

bool compare(GameEntry& obj1, GameEntry& obj2 )
{
    // std::cout<<"ob1.getscore()"<<obj1.getScore()<<std::endl;
    // std::cout<<"ob2.getscore()"<<obj2.getScore()<<std::endl;
    return (obj1.getScore() < obj2.getScore()) ? true : false; 
}

typedef GameEntry& (*COMPARE)(GameEntry&, GameEntry&);
class scores
{
    private:
        int numEntries ;
        int maxEntries;
        std::forward_list<GameEntry>* gameEntry;
        GameEntry& (*COMPARE)(GameEntry&,GameEntry&);
        

    public:
        scores(int _maxEntries = 10)
        {
            numEntries = 0;
            maxEntries = _maxEntries;
            gameEntry = new std::forward_list<GameEntry>();
            
        }

        void add(const GameEntry &obj)
        {
            int new_score  = obj.getScore();
            if(numEntries == maxEntries &&  (new_score <= gameEntry->front().getScore()))
                return;
            else 
                numEntries++;
            if(numEntries > maxEntries)
            {
                gameEntry->pop_front();
            }
            gameEntry->push_front(obj);

            std::cout<<"done"<<"data "<<obj.getScore()<<"isadded"<<std::endl;
            if(numEntries > 2)
               gameEntry->sort(&compare);

        }

        GameEntry& remove(int i) throw(std::runtime_error)
        {
            if(i < 0 || i > numEntries)
            {
                throw(std::runtime_error("ArrayIndexOutOfBound"));
            }
            std::forward_list<GameEntry>::iterator iter = gameEntry->begin();
            for(int j = 0 ; j < (i-1) ; ++j, ++iter);
            std::cout<<"Element to erase"<< (*iter).getScore()<<std::endl;
            gameEntry->erase_after(iter);
            numEntries--;
            

             
        }

        // void ShowAllScore()
        // {
        //     int i = 0;
        //     std::cout<<"front ::"<<gameEntry->front().getScore()<<std::endl;
        //     for(std::forward_list<GameEntry>::iterator iter = gameEntry->begin(); (iter != gameEntry->end() && i < numEntries);++iter,i++)
        //     {
        //         std::cout<<(*iter).getName() << "-"<<(*iter).getScore()<<" ";
        //     }
        //     std::cout<<std::endl;
        // }


         void ShowAllScore()
        {
            int i = 0;
            
            for(std::forward_list<GameEntry>::iterator iter = gameEntry->begin(); iter != gameEntry->end();++iter)
            {
                std::cout<<(*iter).getName() << "-"<<(*iter).getScore()<<" ";
            }
            std::cout<<std::endl;
        }
        
        

};


int main()
{
    scores s(10);

    GameEntry G1("ganesh",100);
    GameEntry G2("Nikita",121);
    GameEntry G3("satej", 10);
    GameEntry G4("Shan", 67);
    GameEntry G5("Ajinkya", 69);
    GameEntry G6("A",343);
    GameEntry G7("sdad", 62343);
    GameEntry G8("Adasd", 231);
    GameEntry G9("Aasdasd", 23);
    GameEntry G10("Asdasd", 6342);
    GameEntry G11("Asdasd", 50);
    s.add(G1);
    s.add(G2);
    s.add(G3);
    s.add(G4);
    s.add(G5);
    // s.add(G2);
    // s.add(G2);
    s.add(G6);
    s.add(G7);
    s.add(G8);
    s.add(G9);
    s.add(G10);
    s.add(G11);
    s.ShowAllScore();
    s.remove(2);

    s.ShowAllScore();
}
