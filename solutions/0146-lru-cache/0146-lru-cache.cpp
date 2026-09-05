class LRUCache {
    struct DBL{
        int key;
        int val; 
        DBL* next;
        DBL* prev;

        DBL(int key, int val){
            this->key = key;
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    unordered_map<int, DBL*> memo;
    DBL* lru;
    DBL* mru;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        lru = nullptr;
        mru = nullptr;
    }
    
    int get(int key) {
        if(memo.find(key) != memo.end()){
            if(memo[key]->next != nullptr){
                update(key);
            }
            return memo[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(memo.find(key) != memo.end()){
            memo[key]->val = value;
            if(memo[key]->next != nullptr){
                update(key);
            }
            return;
        } 
        

        if(memo.size() == capacity){
            DBL* del = lru;
            lru = lru->next;
            del->next = nullptr;
            if(lru)
                lru->prev = nullptr;
            memo.erase(del->key);
            delete del;
        }

        if(memo.size() == 0){
            memo[key] = new DBL(key, value);
            lru = memo[key];
            mru = memo[key];
            return;
        }
        memo[key] = new DBL(key, value);
        memo[key]->next = nullptr;
        memo[key]->prev = mru;
        mru->next = memo[key];
        mru = memo[key];
    }

    void update(int key){
        if(!memo[key]->prev){
            mru->next = memo[key];
            mru = memo[key];
            lru = memo[key]->next;
            lru->prev = nullptr;
            return;
        }
        DBL* next = memo[key]->next;
        DBL* prev = memo[key]->prev;
        if(!prev){
            lru = next;
            mru = memo[key];
            return;
        }   
        if(prev){
            prev->next = next;
        }
        if(next){
            next->prev = prev;
        }
        mru = memo[key];
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */