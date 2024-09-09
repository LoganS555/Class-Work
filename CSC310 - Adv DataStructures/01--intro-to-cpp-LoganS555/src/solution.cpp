#include <iostream>

using namespace std;

//template <typename T>
struct node {
    int data;
    struct node *next;
    node(){
        this->data = 0;
        this->next = nullptr;
    }
    void insert_back(int data, struct node *LLP);
    void insert_front(int data, struct node *LLP);
    void print_list(struct node *LLP);
    struct node *search_list(int data, struct node *LLP);
    void remove_back(struct node *LLP);
    void remove_front(struct node *LLP);
};

void node::insert_back(int data, struct node *LLP){
    struct node* newNode = new node;
    struct node* tmp = LLP;
    newNode->data = data;
    newNode->next = nullptr;
    if (LLP == nullptr){
        LLP = newNode;
        cout << "inserted" << LLP->data << endl;
        return;
    }
    while (tmp->next != nullptr)
        tmp = tmp->next;
    tmp->next = newNode;
    cout << "inserted" << tmp->next->data << endl;
}

void node::insert_front(int data, struct node *LLP){
    struct node *tmp = new node;
    tmp->data = data;
    tmp->next = nullptr;
    if (LLP == nullptr){
        LLP = tmp;
        cout << "inserted" << LLP->data << endl;
        return;
    }
    tmp->next = LLP;
    LLP = tmp;
    cout << "inserted" << LLP->data << endl;
}

void node::print_list(struct node *LLP){
    node *tmp = LLP;
    while(tmp != nullptr){
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

struct node *node::search_list(int data, struct node *LLP){
    struct node *tmp = LLP;

    while (tmp != nullptr)
    {
        if (tmp->data == data)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void node::remove_back(struct node *LLP){
    struct node *tmp = LLP;
    while (tmp->next->next != nullptr){
        tmp = tmp->next;
    }
    delete(tmp->next->next);
    tmp->next = nullptr;
}

void node::remove_front(struct node *LLP){
    struct node* tmp = LLP;
    LLP = LLP->next;
    delete (tmp);
}

int main() {
        node* ll = nullptr;
        node* newNode = new node;
        newNode->data = 1;
        newNode->next = nullptr;
        ll = newNode;
        ll->print_list(ll);
        ll->insert_back(1, ll);
        ll->insert_back(2, ll);
        ll->insert_back(3, ll);
        ll->print_list(ll);

        struct node* sll = ll->search_list(4, ll);
        if (sll == nullptr)
        {
            printf("Value not found\n");
        }
        else
        {
            printf("Value was found\n");
        }
        ll->print_list(ll);
        ll->remove_back(ll);
        ll->remove_back(ll);
        ll->remove_back(ll);
        ll->print_list(ll);
        
        return 0;
}
