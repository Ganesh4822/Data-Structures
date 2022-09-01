#include<iostream>
#include<stdexcept>

class GameEntry 
{
    private:
        std::string name;
        int score;
    
    public:
        GameEntry(const std::string& _name = " ", int n =0):name(_name), score(n){}
        std::string getName() const
        {
            return name;
        }

        int getScore() const
        {
            return score;
        }

};

class Scores
{
    private:
        int maxEntries;
        int numEntries;
        GameEntry* entries;
    
    public:
        Scores(int maxEnt = 10)
        {
            maxEntries = maxEnt;
            entries = new GameEntry[maxEntries];
            numEntries = 0;
        }

        ~Scores()
        {
            delete[] entries;
        }

        void add(const GameEntry& gameobj);
        GameEntry& remove(int i) throw(std::runtime_error);
};


void Scores::add(const GameEntry& gameobj)
{
    int new_score  = gameobj.getScore();
    if(numEntries == maxEntries)
    {
        if(new_score <= entries[maxEntries-1].getScore())
            return;
    }
    else numEntries++;

    int i = numEntries -2;
    while(i >= 0 && new_score > entries[i].getScore())
    {
        entries[i + 1] = entries[i];
        i--;
    }

    entries[i + 1] = gameobj;
}

GameEntry& Scores::remove(int i) throw(std::runtime_error)
{
    if(i< 0 && i >= numEntries)
    {
        throw(std::runtime_error("ArrayINdexOutOfBound"));
    }
    GameEntry e = entries[i];
    for(int j = i+ 1; j < numEntries ; j++)
    {
        entries[j -1] = entries[j];

    }
    numEntries--;
    return e;

}


int main()
{ 
    
}

