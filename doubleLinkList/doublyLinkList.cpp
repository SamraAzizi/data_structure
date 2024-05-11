#include<iostream>

using namespace std;

class node{
    public:
    int key;
    int data;
    node * next;
    node * previous;


    node(){
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }


    node(int k, int d){
        key = k;
        data = d;

    }
};

class doublyLinkList{
    public:
    node * head;


    doublyLinkList(){
        head = NULL;
    }

    doublyLinkList(node * n){
        head = n;
    }

    //1. check if node exits using key value

    node * nodeExists(int k){
        node * temp = NULL;
        node * ptr = head;


        while(ptr != NULL){
            if(ptr -> key == k){
                temp = ptr;
            }
            ptr = ptr -> next;
        }
        return temp;
    }

    //2.append a node to the list

    void appendNode(node * n){
        if(nodeExists(n -> key) != NULL){
            cout<<"Node already exists with key value : "<<n -> key<<
            "append another node with different key value"<<endl;
        }else{
            if(head == NULL){
                head = n;
                cout<<"Node appended as head node"<<endl;
            }else{
                node *ptr = head;
                while(ptr -> next != NULL){
                    ptr = ptr -> next;
                }
                ptr -> next = n;
                n -> previous = ptr;
                cout<<"Node appended"<<endl;
            }
        }
    }

    // 3.prepended node atatch node at the start

    void prependNode(node * n){
        if(nodeExists(n -> key) != NULL){
            cout<<"Node already exists with key value: "<<n->key<<
            " append another node with different key value "<<endl;
        }else{
            if(head == NULL){
                head = n;
                cout<<"node prepended as head node"<<endl;
            }else{
                head -> previous = n;
                n -> next = head;
                head = n;
                cout<<"node prepended"<<endl;
            }
        }
    }

    // 4. insert a node after a paticular node in list

    void insertNode(int k, node*n){
        node * ptr = nodeExists(k);
        if(ptr == NULL){
            cout<<"no node exists with key value: "<<k<<endl;
        }else{
            if(nodeExists(n-> key)  != NULL){
                cout<<"node already exists with key value: "<<n->key<<
                " append another node with different key value "<<endl;
            }else{
                node * nextNode = ptr -> next;
                if(nextNode == NULL){
                    ptr -> next = n;
                    n -> previous = ptr;
                    cout<<"node inserted at the END "<<endl;
                }else{
                    n -> next = nextNode;
                    nextNode -> previous = n;
                    n -> next = n;
                    cout<<"Node inserted in between"<<endl;
                }

            }
        }
    }

    // 5. delete node by unique key
    void deleteNode(int k){
        node *ptr = nodeExists(k);
        if(ptr == NULL){
            cout<<"No node exists with key value: "<<k<<endl;
        }else{
            if(head -> key == k){
                head = head -> next;
                cout<<"node UNLINKED with key value: "<<k<<endl;
            }else{
                node * nextNode = ptr -> next;
                node * prevNode = ptr -> previous;

                if(nextNode == NULL){
                    prevNode -> next = NULL;
                    cout<<"node delete at the END"<<endl;
                }else{
                    prevNode -> next = nextNode;
                    nextNode -> previous = prevNode;
                    cout<<"Node deleted in between "<<endl;
                }

            }
        }
    }

    // 6. update node
    void updateNode(int k, int d){
        node * ptr = nodeExists(k);
        if(ptr != NULL){
            ptr -> data = d;
            cout<<"Node data updated successfully "<<endl;
        }else{
            cout<<"Node does not exists with key value: "<<k<<endl;
        }
    }

    // 7. printing

    void printList(){
        if(head == NULL){
            cout<<"No Nodes in doubly link list";
        }else{
            cout<<endl<<"doubly link list value: ";
            node * temp = head;

            while(temp != NULL){
                cout<<"( "<<temp -> key<<" , "<<temp->data<<
                " ) <-->";
                temp = temp ->next;
            }
        }
    }
};
int main(){

    doublyLinkList obj;
    int option;
    int key1, k1, data1;
    do{
        cout<<"\n What  operation do you want to perform ? select Option Number. Enter 0 to exit"<<
        endl;

        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNode()"<<endl;
        cout<<"4. deleteNode()"<<endl;
        cout<<"5. updateNode()"<<endl;
        cout<<"6. printNode()"<<endl;
        cout<<"7. Clear screen"<<endl<<endl;

        cin>>option;
        node * n1 = new node();

        switch(option){
            case 0:
            break;


            case 1:
            cout<<"Append node operation \n Enter key and data of the node to be appended "<<endl;
            cin>>key1;
            cin>>data1;
            n1 -> key = key1;
            n1 -> data = data1;
            obj.appendNode(n1);
            break;


            case 2:
            cout<<"Prepend node operation \n Enter key and data of the node to be prepended"<<endl;
            cin>>key1;
            cin>>data1;
            n1 -> key = key1;
            n1 -> data = data1;
            obj.prependNode(n1);
            break;



            case 3:
            cout<<"Inset node after operation \n Enter key of existing node after which you want to inset this new node: "<<endl;
            cin>>k1;
            cout<<"Enter key and data of the new node first: "<<endl;

            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;

            obj.insertNode(k1, n1);
            break;



            case 4:
            cout<<"delete node by key operation \n Enter key of the node to be deleted: "<<endl;
            cin>>k1;
            obj.deleteNode(k1);
            break;


            case 5:
            cout<<"Update node by key operation - \n Enter key and new data to be updated: "<<endl;
            cin>>key1;
            cin>>data1;
            obj.updateNode(key1, data1);
            break;

            case 6:
            obj.printList();
            break;


            case 7:
            system("cls");
            break;

            default:
            cout<<"Enter proper option number: "<<endl;

        }

    }while(option != 0);
    return 0;

}