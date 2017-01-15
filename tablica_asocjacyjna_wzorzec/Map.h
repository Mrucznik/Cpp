#ifndef TABLICA_ASOCJACYJNA_ASSOCTAB_H
#define TABLICA_ASOCJACYJNA_ASSOCTAB_H

#include <cstring>
#include <ostream>

template <typename KEY, typename TYPE> class Map
{
private:
    struct Node
    {
        Node* next;
        KEY key;
        TYPE val;

        Node(KEY key, TYPE val) :
                key(key), val(val), next(nullptr)
        {
        };

        Node(const Node& node) :
                key(node.key), val(node.val), next(nullptr)
        {
        };

        bool operator==(const Node& node) const
        {
            return node.key == key;
        }

        friend std::ostream &operator<<(std::ostream &os, const Node &node)
        {
            os << node.val;
            return os;
        }

        //assignment not allowed
        Node& operator=(const Node&) = delete;
    };

    Node *head;

    void clear ()
    {
        while(head != nullptr)
        {
            Node *node = head->next;
            delete head;
            head = node;
        }
    };

    void swap (Map<KEY, TYPE>&l)
    {
        Node* node = head;
        head = l.head;
        l.head = node;
    };

public:
    Map()
    {
        head = nullptr;
    };

    ~Map()
    {
        clear();
    };

    Map(const Map<KEY, TYPE>& map)
    {
        Node *src, **dst;
        head = nullptr;
        src = map.head;
        dst = &head;
        try
        {
            while (src)
            {
                *dst = new Node(*src);
                src = src->next;
                dst = &((*dst)->next);
            }
        }
        catch (...)
        {
            clear ();
            throw;
        };
    };

    Map<KEY, TYPE> & operator=(const Map& map)
    {
        if (&map == this)
            return *this;

        Map swapMap(map);
        swap(swapMap);
        return *this;
    };

    void add(KEY key, TYPE value)
    {
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        head->val = value;
    };

    TYPE* find (KEY key) const
    {
        Node *node = head;
        while (node)
        {
            if (node->key == key)
                return &node->val;
            node = node->next;
        };
        return nullptr;
    };

    TYPE &operator[] (KEY key)
    {
        Node *node = find(key);
        if (!node)
        {
            add(key, TYPE());
            node = head;
        };
        return node->val;
    };

    friend std::ostream &operator<<(std::ostream &os, const Map<KEY, TYPE> &map)
    {
        Node* node = map.head;
        while(node != nullptr)
        {
            Node *nextNode = node->next;
            os << "head: " << *node;
            node = nextNode;
        }
        return os;
    };
};

#endif //TABLICA_ASOCJACYJNA_ASSOCTAB_H
