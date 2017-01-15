#include "Map.h"

Map::Node::Node(const char *k) : next(nullptr)
{
    key = new char[strlen (k) + 1];
    strcpy (key, k);
}

Map::Node::~Node()
{
    delete[]key;
}

Map::Node::Node(const Node &s) : next(nullptr)
{
    if (s.key == nullptr)
        key = nullptr;
    else
    {
        key = new char[strlen (s.key) + 1];
        strcpy(key, s.key);
    }
    val=s.val;
}

//------------------------------Map-------------------------------------

Map::Map()
{
    head = nullptr;
}

Map::Map(const Map &map)
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
}

Map::~Map()
{
    clear();
}

void Map::insert(const char *key, int value)
{
    Node* newNode = new Node(key);
    newNode->next = head;
    head = newNode;
    head->val = value;
}

void Map::clear()
{
    while(head != nullptr)
    {
        Node *node = head->next;
        delete head;
        head = node;
    }
}

Map::Node *Map::find(const char *key) const
{
    Node *node = head;
    while (node)
    {
        if (compareNodesKey(node->key, key))
            return node;
        node = node->next;
    };
    return nullptr;
}

void Map::swap(Map &l)
{
    Node* node = head;
    head = l.head;
    l.head = node;
}

bool Map::compareNodesKey(const char* key1, const char* key2) const
{
    return !strcmp(key1, key2);
}

Map &Map::operator=(const Map &map)
{
    if (&map == this)
        return *this;

    Map swapMap(map);
    swap(swapMap);
    return *this;
}

int &Map::operator[](const char *key)
{
    Node *node = find(key);
    if (!node)
    {
        insert (key, 0);
        node = head;
    };
    return node->val;
}

bool MapCaseInsensitive::compareNodesKey(const char *key1, const char *key2) const
{
    return !stricmp(key1, key2);
}

bool MapCaseSensitive::compareNodesKey(const char *key1, const char *key2) const
{
    return !strcmp(key1, key2);
}
