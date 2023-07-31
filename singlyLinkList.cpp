#include<iostream>

using namespace std;


class node{
    public:
    int key;
    int data;
    node * next;


    node(){
        key = 0;
        data = 0;
        next = NULL;
    }

    node(int k, int d){
        key = k;
        data = d;
        
    }
};

class singlyLinkList{
    public:
    node * head;

    singlyLinkList(){
        head = NULL;
    }

    singlyLinkList(node * n){
        head = n;
    }

    //check if node exits using key value
    node * nodeExist(int k){
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

//append node to the list

    void appendNode(node * n){
        if(nodeExist(n -> key ) != NULL){
            cout<<"Node already exists with key value: "<<n -> key
            <<"append another node with different key value: "<<endl;
        }else{
            if(head == NULL){
                head = n;
                cout<<"Node appended"<<endl;
            }else{
                node * ptr = head;
                while(ptr -> next != NULL){
                    ptr = ptr-> next;
                }
                ptr -> next = n;
                cout<<"Node appended"<<endl;
            }
        }
    }

    // prepend node - atach a node at end

    void prependNode(node * n){
        if(nodeExist(n -> key)!= NULL){
            cout<<"node already exists with key value: "<<n->key
            <<" append another node with different key: "<<endl;
        }else{
            n->next = head;
            head = n;
            cout<<"node prepended"<<endl;
        }
    }

    //inser a node

    void insertNode(int k, node * n){
        node * ptr = nodeExist(k);
        if(ptr == NULL){
            cout<<"No node exists with key value: "<<k<<endl;
        }else{
            if(nodeExist(n->key)!= NULL){
                cout<<"node already exists with key value: "<<n->key<<" append another node "
                <<endl;

            }else{
                n-> next = ptr -> next;
                ptr -> next = n;
                cout<<"Node inserted "<<endl;
            }
        }
    }

    //delete node

    void deleteNode(int k){
        if(head == NULL){
            cout<<"Singly link list already empty. cant delete"<<endl;
            
        }else if(head != NULL){
            if(head ->key == k){
                head = head -> next;
                cout<<"Node unlinked with key value: "<<k<<endl;
            }else{
                node * temp = NULL;
                node * prevptr = head;
                node * currentptr = head -> next;
                while(currentptr != NULL){
                    if(currentptr ->key == k){
                        temp = currentptr;
                        currentptr = NULL;
                    }else{
                        prevptr = prevptr -> next;
                        currentptr = currentptr -> next;
                    }
                }
                if(temp != NULL){
                    prevptr -> next = temp -> next;
                    cout<<"Node unlinked with key value: "<<k<<endl;
                }else{
                    cout<<"node does not exist with key value: "<<k<<endl;
                }
            }

        }
    }

    //updata node
    void updateNode(int k, int d){
        node * ptr = nodeExist(k);
        if(ptr != NULL){
            ptr -> data = d;
            cout<<"node data updated successfully "<<endl;
        }else{
            cout<<"node does not exists with key value: "<<k<<endl;
        }
    }

    /// displaying, printing

    void printList(){
        if(head == NULL){
            cout<<"no nodes in singly link list ";
        }else{
            cout<<endl<<"singly link list values: ";
            node * temp = head;

            while(temp != NULL){
                cout<<"( "<<temp->key<<" , "<<temp->data<<" ) -->";

                temp = temp -> next;
            }
        }
    }

};

int main(){
    singlyLinkList s;
    int option;
    int key1, k1, data1;

    do{
        cout<<"What operation do you want to perform? select option Number, enter 0 to exit: "<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNode()"<<endl;
        cout<<"4. deleteNode()"<<endl;
        cout<<"5. updateNode()"<<endl;
        cout<<"6. printNode()"<<endl;
        cout<<"7. Clear screen"<<endl;

        cin>>option;

        node * n1 = new node();

        switch(option){
            case 0:
            break;


            case 1:
            cout<<"append node operation \n Enter key and data of node to be appended: "<<endl;
            cin>>key1;
            cin>>data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.appendNode(n1);
            break;


            case 2:
            cout<<"prepend node operation \n Enter key and data of the node to be prepended: "<<endl;
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1 -> data = data1;
            s.prependNode(n1);
            break;



            case 3:
            cout<<"Insert node after operation \n Enter key of existing node after which you want to inset this new node: "<<endl;
            cin>>key1;
            cout<<"Enter key and data of the new node first: "<<endl;
            cin>>key1;
            cin>>data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.insertNode(k1, n1);
            break;

            case 4:
            cout<<"Delete node by key operation - \n Enter key of the node to be deleted: "<<endl;
            cin>>k1;
            s.deleteNode(k1);
            break;


            case 5:
            cout<<"Update node by key operation -\n Enter key and new data to be updated: "<<endl;
            cin>>key1;
            cin>>data1;
            s.updateNode(key1, data1);

            break;


            case 6:
            s.printList();
            break;


            case 7:
            system("cls");
            break;


            default:
            cout<<"Enter proper option number: "<<endl;
        }
    }
    while(option != 0);
    return 0;
}