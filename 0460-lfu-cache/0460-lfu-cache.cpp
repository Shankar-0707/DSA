class LFUCache {
public:
    class Node {
    public:
        int key;
        int value;
        int count;

        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            count =
                1; // jb bhi nyi node bnegi uski frewquency ek se start krenge

            next = prev = nullptr;
        }
    };

    class List {
    public:
        int size;
        Node* head;
        Node* tail;

        List() {
            size = 0;

            head = new Node(-1,-1);
            tail = new Node(-1,-1);

            head->next = tail;
            tail->prev = head;
        }

        void addNode(Node* newNode) {
            Node* temp = head->next;
            head->next = newNode;
            temp->prev = newNode;

            newNode->next = temp;
            newNode->prev = head;

            size++; // jese hi ek node add kri h to uska size bdh gya h
        }

        void removeNode(Node* node) {
            Node* prevNode = node->prev;
            Node* nextNode = node->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            size--;
        }
    };

    unordered_map<int, List*> freqList;
    unordered_map<int, Node*> keyNode;
    int maxSize;
    int currSize;
    int minFreq;


    void updateFrequency(Node* node){
        int freq = node->count;

        // old list se remove
        freqList[freq]->removeNode(node);

        // agar old list empty ho gyi to 
        if(freq == minFreq && freqList[freq]->size == 0){
            minFreq++;
        }

        // frequency increase
        node->count++;

        // agar new frequency ki list exist nhi krti 
        if(freqList.find(node->count) == freqList.end()){
            freqList[node->count] = new List();
        }

        // new list me add
        freqList[node->count]->addNode(node);
    }

    LFUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        minFreq = 0;
    }

    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;

        Node* node = keyNode[key];
        updateFrequency(node);

        return node->value;
    }

    void put(int key, int value) {
        if(maxSize == 0) return;

        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];

            // value update 
            node->value = value;
            updateFrequency(node);
            return;
        }

        if(currSize == maxSize){
            List* minFreqList = freqList[minFreq];

            // us list ki LRU node
            Node* nodeToDelete = minFreqList->tail->prev;

            // List se remove;
            minFreqList->removeNode(nodeToDelete);

            // map se remove
            keyNode.erase(nodeToDelete->key);

            delete nodeToDelete;

            currSize--;
        }

        // Nya node bnao 
        Node* newNode = new Node(key, value);
        currSize++;

        // hr ek nya node freq ek se start hota h 
        minFreq = 1;

        // agar freq 1 ki list nhi bni 
        if(freqList.find(1) == freqList.end()){
            freqList[1] = new List();
        }

        freqList[1]->addNode(newNode);

        keyNode[key] = newNode;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */