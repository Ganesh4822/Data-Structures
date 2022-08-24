
class DNode
{
    private:
        DNode* next;
        DNode* prev;
        int data;
    friend class DLinkedList;
};


class DLinkedList
{
    private:
        DNode* head;
        DNode* tail;
        static void AddNode(DNode* prev, DNode* nodeToAdd, DNode* next);
        static void RemoveNode(DNode* NodeToRemove);
        static DNode* getNode(int data);
        DNode* searchNode(int sData);
    
    public:
        DLinkedList();
        ~DLinkedList();
        bool isempty();
        const int GetFront() const;
        const int GetBack() const;
        void InsertStart(int data);
        void InsertEnd(int data);
        int PopStart();
        int PopEnd();
        void AddAfter(int newData,int afterData);
        void ShowList() const;

};