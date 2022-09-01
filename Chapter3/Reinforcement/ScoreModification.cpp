/*R-3.1 Modify the implementation of class Scores so that at most ⌈maxEnt/2⌉ of
the scores can come from any one single player.
*/

#include<iostream>
#include<stdexcept>

class CGameEntry
{
    private:
        std::string name;
        int score;
        int count;
    
    public:
        CGameEntry(const std::string& _name = "", int _score = 0)
        {
            name  = _name;
            score = _score;
            count = 0;
        }
        std::string getName() const
        {
            return (this->name);
        }

        int getScore()
        {
            return(this->score);
        }

        int getCount()
        {
            return (this->count);
        }

        void operator++()
        {
            (this->count)++;
        }

        void operator--()
        {
            (this->count)--;
        }
};

class CScores
{
    private:
        int maxEntries;
        int numEntries;
        CGameEntry* entries;
    
    public:
        CScores(int _maxEntries = 10)
        {
            maxEntries = 10 ;
            entries = new CGameEntry[10];
            numEntries = 0;
        }

        ~CScores()
        {

            delete[] entries;
        }

        void add(CGameEntry& obj)
        {
            if(obj.getCount() < (maxEntries/2))
            {
                int new_score = obj.getScore();
                if(numEntries == maxEntries)
                {
                    if(new_score <= entries[maxEntries -1].getScore())
                        return; 
                }
                else
                    numEntries++;
                int i = numEntries -2;
                while(i>=0 && new_score > entries[i].getScore())
                {
                    entries[i + 1] = entries[i];
                    i--;
                }

                entries[i+1] = obj;
                ++obj;

            }
        }

        CGameEntry& remove(int i)throw(std::runtime_error)
        {
            if(i< 0 && i >= numEntries)
            {
                throw(std::runtime_error("ArrayINdexOutOfBound"));
            }
            CGameEntry e = entries[i];
             for(int j = i+ 1; j < numEntries ; j++)
            {
                entries[j -1] = entries[j];

            }
            numEntries--;
            --e;
            return e;
        }

};

