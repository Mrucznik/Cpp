#ifndef TABLICA_ASOCJACYJNA_ASSOCTAB_H
#define TABLICA_ASOCJACYJNA_ASSOCTAB_H

#include <cstring>

class Map
{
protected:
    struct Node
    {
        Node *next;
        char *key;
        int val;
        Node (const char*);;
        ~Node ();
        Node (const Node&);

        //assignment not allowed
        Node& operator=(const Node&) = delete;
    };

    Node *head;
    void insert (const char *key, int value);
    void clear ();
    Node *find (const char *key) const;
    void swap (Map & l);
    virtual bool compareNodesKey(const char*, const char*) const;

public:
    Map ();
    Map (const Map& map);
    ~Map();

    Map & operator= (const Map& map);
    int &operator[] (const char*);
};

class MapCaseInsensitive : public Map
{
private:
    bool compareNodesKey(const char*, const char*) const;

public:
};

class MapCaseSensitive : public Map
{
private:
    bool compareNodesKey(const char*, const char*) const;

public:
};

#endif //TABLICA_ASOCJACYJNA_ASSOCTAB_H
