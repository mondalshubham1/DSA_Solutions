// Problem Link : https://leetcode.com/problems/lru-cache/description/

class Node {     // Double LinkedList is maintained with recent elements at the front and old elements at the back.
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key, int val) : key(key), value(val), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    unordered_map<int, Node*> addressMap;        // stores the key and the corresponding node's address
    Node* head=NULL;
    Node* tail=NULL;
    int capacity=0;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);    // dummy nodes
        tail = new Node(-1,-1);  
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(addressMap.find(key) == addressMap.end())
            return -1;
        Node* node = addressMap[key];
        extractNode(node);
        insertAtFront(node);
        return node->value;
    }

    void insertAtFront(Node* node) {
        Node* tmp = head->next;
        node->next = tmp;
        node->prev = head;
        head->next = node;
        tmp->prev = node;
    }

    void extractNode(Node* node) {       // remove the node from that place
        Node* nextNode = node->next;
        Node* prevNode = node->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        node->next = NULL;
        node->prev = NULL;
    }
    
    void put(int key, int value) {
        if(addressMap.find(key) != addressMap.end()) {
            Node* node = addressMap[key];
            extractNode(node);
            node->value = value;     // change the value
            insertAtFront(node);
        } 
        else {
            if(addressMap.size()>=this->capacity){      // If the capacity of the cache is full, delete the oldest node (tail->prev)
                Node* node = tail->prev;
                extractNode(node);
                addressMap.erase(node->key);            // as I'm deleting, also remove it from map
                delete node;
            }
            Node* node = new Node(key, value);
            addressMap[key] = node;
            insertAtFront(node);    
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
