

class CNode
{
    private:
        int data;
        CNode* next;
    friend class CicularList;
};


class CicularList
{
    private:
        CNode* cursor;
        static CNode* getNode(int data);
    
    public:
        CicularList();
        ~CicularList();
        bool empty() const;
        const int front() const; //Element at cursor
        const int back() const; //elemnt following cursor
        void advance();
        void add(int data); //add after cursor
        void remove();
};

