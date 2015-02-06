struct Node{

    int key;

    int value;

    Node* next;

    Node* prev;

    Node(int k,int v): key(k),value(v),next(NULL),prev(NULL) {};

};



class LRUCache{

    unordered_map<int,Node*> cache;

    Node* head;

    int capacity;

    int size;

public:

    LRUCache(int capacity) {

        if (capacity < 1) return;

        this->capacity = capacity;

        this->head = NULL;

        this->size = 0;

    }



    int get(int key) {

        unordered_map<int,Node*>::iterator it = cache.find(key);

        if (it == cache.end())

            return -1;

        else {

            Node* cur = it->second;

            if (cur != this->head) {

                cur->next->prev = cur->prev;

                cur->prev->next = cur->next;

                putToHead(cur);

            }

            return cur->value;

        }

    }



    void set(int key, int value) {

        if (cache.find(key) != cache.end()) {

            Node* cur = cache[key];

            cur->value = value;

            if (cur != this->head){

                cur->next->prev = cur->prev;

                cur->prev->next = cur->next;

                putToHead(cur);

            }

        } else {

            if (this->size < this->capacity) {

                cache[key] = new Node(key,value);

                putToHead(cache[key]);

                this->size++;

            } else {

                cache[key] = new Node(key,value);

                putToHead(cache[key]);

                Node* tmp = this->head->prev;

                tmp->prev->next = tmp->next;

                tmp->next->prev = tmp->prev;

                cache.erase(tmp->key);

                delete tmp;

            }

        }

    }



    void putToHead(Node* p){

        if (this->size == 0){

            this->head = p;

            p->next = p;

            p->prev = p;

        } else {

            p->next = this->head;

            p->prev = this->head->prev;

            this->head->prev->next = p;

            this->head->prev = p;

            this->head = p;

        }

    }

};
