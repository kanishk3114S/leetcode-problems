class LRUCache {

    class Node {

        public:
        int val , key;
        Node* next;
        Node* prev;
        Node(int key , int val) {
            this->val = val;
            this->key = key;
            next = nullptr;
            prev = nullptr;
        } 
    };

public:

    Node* Dummyhead = new Node(-1,-1);
    Node* Dummytail = new Node(-1,-1);
    int size , cap;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        Dummyhead->next = Dummytail;
        Dummytail->prev = Dummyhead;
    }

    unordered_map<int , Node*> mpp;

    void Addnode(int key , int val) {

        Node* newnode = new Node(key,val);
        //add that node to the top of the cache//

        Node* top = Dummytail->prev;

        top->next = newnode;
        newnode->prev = top;
        newnode->next = Dummytail;
        Dummytail->prev = newnode;
        mpp[key] = newnode;
    }

    void DeleteNode() {

        int key = Dummyhead->next->key;
        Node* temp = mpp[key];
        mpp.erase(key);
        Dummyhead->next->next->prev = Dummyhead;
        Dummyhead->next = Dummyhead->next->next;
        delete temp;

    }
    
    int get(int key) {
        if (size == 0 || !mpp.count(key)) return -1;
        int ans =  mpp[key]->val;

            Node* temp = mpp[key];
            
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            temp->next = nullptr;
            temp->prev = nullptr;

            delete temp;
            mpp.erase(key);

            Addnode(key , ans);

        return ans;

    }
    
    void put(int key, int value) {
        
        if (!mpp.count(key)) {

            //key does not exists//
            Addnode(key,value);
            size++;

        } else {

            Node* temp = mpp[key];
            
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            temp->next = nullptr;
            temp->prev = nullptr;

            delete temp;
            mpp.erase(key);

            Addnode(key , value);

        }

        if (size > cap) {

            DeleteNode();
            size--;

        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */