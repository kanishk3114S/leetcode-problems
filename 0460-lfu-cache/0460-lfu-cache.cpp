class LFUCache {
    class Node {

        public:
        int val , key , freq;
        Node* next;
        Node* prev;
        Node(int key , int val , int freq) {
            this->val = val;
            this->key = key;
            next = nullptr;
            prev = nullptr;
            this->freq = freq;
        } 
    };

    unordered_map<int,Node*> mpp;

    class DLL {
        public:
            Node* head;
            Node* tail;

            DLL() {
                head = new Node(-1, -1 , 1);
                tail = new Node(-1, -1 , 1);

                head->next = tail;
                tail->prev = head;
            }

            void add(Node* newnode){
                //adding a node//

                tail->prev->next = newnode;
                newnode->prev = tail->prev;
                newnode->next = tail;
                tail->prev = newnode;

            }
            void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            }
            Node* removeFront(){
                Node* temp = head->next;
                remove(temp);
                return temp;
                
            }
            bool isEmpty() {

                return head->next->val == -1;

            }
        };   
public:

    int minFreq;
    unordered_map<int,DLL*> freq;
    int sz , cap ;
    LFUCache(int capacity) {

        DLL* newdll = new DLL();
        freq[1] = newdll;
        sz = 0;
        cap = capacity;
        minFreq = 0;

    }

         

    int get(int key) {
        
        if (sz == 0 || !mpp.count(key)) return -1;

        //if key do exist in the cache//

        int oldFreq = mpp[key]->freq;
        mpp[key]->freq += 1;
        freq[oldFreq]->remove(mpp[key]);
        int newFreq = mpp[key]->freq;
        if (!freq.count(newFreq)) {
            DLL* newdll = new DLL();
            freq[newFreq] = newdll;
        }
        freq[newFreq]->add(mpp[key]);
        if (oldFreq == minFreq && freq[oldFreq]->isEmpty())
        minFreq++;

        return mpp[key]->val;
    }
    
        void put(int key, int value) {
            // 1. If key exists, update value and just return (let the update logic handle it)
            if (mpp.count(key)) {
                mpp[key]->val = value;
                get(key); // This handles the frequency increment and re-ordering
                return;
            }

            // 2. If key doesn't exist, check capacity BEFORE adding
            if (sz == cap) {
                Node* removed = freq[minFreq]->removeFront();
                mpp.erase(removed->key);
                delete removed;
                sz--;
            }

            // 3. Now add the new node
            Node* newnode = new Node(key, value, 1);
            mpp[key] = newnode;
            freq[1]->add(newnode);
            minFreq = 1; 
            sz++;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */