class LRUCache {
public:
class Node{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key_, int val_){
        key = key_;
        value = val_;
    }    
};


int cap;
unordered_map<int, Node*>mpp;
Node* head;
Node* tail;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head; 
    }

    void addnode(Node* newnode){
        Node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deletenode(Node* delnode){
        Node* delprev = delnode -> prev;
        Node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;

    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* resnod = mpp[key];
            int res = resnod -> value;
            mpp.erase(key);
            deletenode(resnod);
            addnode(resnod);
            mpp[key] = head -> next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* existingnode = mpp[key];
            mpp.erase(key);
            deletenode(existingnode);
        }
        if(mpp.size() == cap){
            mpp.erase(tail -> prev -> key);
            deletenode(tail -> prev);
        }
        Node* newn = new Node(key, value);
        addnode(newn);
        mpp[key] = newn;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */