class LRUCache {
public:

    class Node{
        public:
        int key, value;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k;
            value = v;
            next = prev = nullptr;
        }
    };
    
    Node* head = new Node(-1, -1);  // dummy nodes to prevent edge cases
    Node* tail = new Node(-1, -1);

    // ab hme baar baar do chize krni h add or delet to unka aek function bna lete h 

    void addNode(Node* newNode){
        // head ke baad insert krenge 
        Node* oldNext = head->next;
        head->next = newNode;

        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* newNode){
        Node* oldNext = newNode->next;
        Node* oldPrev = newNode->prev;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;

    }

    unordered_map<int, Node*> mp;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head; 
        // yha se ll kis starting krdi
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1; // mtlb key hi nhi h 

        // yha per key h 
        Node* ansNode = mp[key];
        int value = ansNode->value;

        mp.erase(key);
        delNode(ansNode);
        mp[key] = ansNode;
        addNode(ansNode);

        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            // mtlb already h 
            Node* oldNode = mp[key];
            mp.erase(key);
            delNode(oldNode);
        }

        if(mp.size() == limit){
            // delet krenge least recently used node
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }

        // ab yha add krenge or map me rkhenge
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */