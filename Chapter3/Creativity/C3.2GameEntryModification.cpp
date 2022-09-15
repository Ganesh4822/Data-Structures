/*
C-3.2 Give C++ code for performing add(e) and remove(i) functions for game
entries stored in an array a, as in class Scores in Section 3.1.1, except this
time, don’t maintain the game entries in order. Assume that we still need
to keep n entries stored in indices 0 to n − 1. Try to implement the add
and remove functions without using any loops, so that the number of steps
they perform does not depend on n.
*/

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
    int new_score = gameobj.getScore();
    if(this->numEntries == this->maxEntries)
    {
        return;
    }
    else
    {
        numEntries++;
        entries[numEntries - 1] = gameobj;

    }
}

GameEntry& Scores::remove(int i) throw(std::runtime_error)
{
    if(i< 0 && i >= numEntries)
    {
        throw(std::runtime_error("ArrayINdexOutOfBound"));
    }
    GameEntry e = entries[i];
    entries[i] = entries[numEntries - 1];
    numEntries--;
    return e;

}


int main()
{ 
    
}

