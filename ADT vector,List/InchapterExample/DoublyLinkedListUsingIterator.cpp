struct Node
{
    int val;
    Node* prev;
    Node* next;
};

class NodeList
{
    private:
        Node* head;
        Node* tail;
        int n;
    public:
        class Iterator
        {
            private:
                Node* v;
                Iterator(Node* u);
            public:
                int& operator*();
                bool operator ==(const Iterator& p) const;
                bool operator !=(const Iterator& p) const;
                Iterator& operator++();
                Iterator& operator--();
                friend class NodeList;
        };

    public:
        NodeList();
        int size() const;
        bool empty() const;
        Iterator begin() const;
        Iterator end() const;
        void insertfront(const int val);
        void insertback(const int val);
        void insert(const Iterator& p, const int e);
        void eraseFront();
        void eraseBack();
        void erase(const Iterator& e);
};

NodeList::Iterator::Iterator(Node* u)
{
    v = u;
}

int& NodeList::Iterator::operator*()
{
    return(v->val);
}

bool NodeList::Iterator::operator ==(const Iterator& p) const
{
    return(v == p.v);
}

bool NodeList::Iterator::operator !=(const Iterator& p) const
{
    return(v != p.v);
}

NodeList::Iterator& NodeList::Iterator::operator++()
{
    v = v->next;
    return *this;
}

NodeList::Iterator& NodeList::Iterator::operator--()
{
    v = v->prev;
    return *this;
}

NodeList::NodeList()
{
    
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;

}

int NodeList::size() const
{
    return n;
}

bool NodeList::empty() const
{
    return (n == 0);
}

NodeList::Iterator NodeList::begin() const
{
    return (NodeList::Iterator(head->next));
}

NodeList::Iterator NodeList::end() const
{
    return(NodeList::Iterator(head->prev));
}

void NodeList::insertfront(const int val)
{
    insert(begin(),val);
}

void NodeList::insertback(const int val)
{
    insert(end(),val);
}

void NodeList::insert(const Iterator& p, const int e)
{
    Node* u = p.v;
    Node* nNode = new Node;
    nNode->val = e;

    nNode->next = u->next;
    nNode->prev = u;
    u->next = nNode;
    u->next->prev = nNode;
}

void NodeList::eraseFront()
{
    erase(begin());
}

void NodeList::eraseBack()
{
    erase(--end());
}

void NodeList::erase(const Iterator& e)
{
    Node* deleteNode = e.v;
    deleteNode ->next->prev = deleteNode->prev;
    deleteNode->prev->next = deleteNode->next;

}