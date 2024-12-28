// Problem Link : https://leetcode.com/problems/lru-cache/description/

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key, int val) : key(key), value(val), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    unordered_map<int, Node*> addressMap;
    Node* head=NULL;
    Node* tail=NULL;
    int capacity=0;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
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

    void extractNode(Node* node) {
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
            node->value = value;
            insertAtFront(node);
        } 
        else {
            if(addressMap.size()>=this->capacity){
                Node* node = tail->prev;
                extractNode(node);
                addressMap.erase(node->key);
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
