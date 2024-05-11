#include<iostream>


using namespace std;

class queue{
    private:
    int front;
    int rear;
    int arr[5];

    public:
    queue(){
        front = -1;
        rear = -1;
        for(int i = 0;i<5;i++){
            arr[i] = 0;
        }
    }



    bool isEmpty(){
        if(front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    

    bool isFull(){
        if(rear == 4)
            return true;
        else
            return false;
    }



    void enqueue(int val){
        if(isFull()){
            cout<<"Queue full"<<endl;
            return;
        }else if(isEmpty()){
            rear = 0;
            front = 0;
            arr[rear] = val;
        }else{
            rear++;
            arr[rear] = val;
        }    
    }

    int dequeue(){
        int x= 0;
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return x;
        }else if(rear == front){
            x = arr[rear];
            rear = -1;
            front = -1;
            return x;
        }else{
            cout<<"front value: "<<front<<endl;
            x = arr[front];
            arr[front] = 0;
            front ++;
            return x;
        }
    }

    int count(){
        return (rear - front +1);
    }



    void display(){
        cout<<"all values in the queue are - "<<endl;
        for(int i=0; i<5;i++){
            cout<<arr[i]<<" ";
        }
    }

};

int main(){
    queue q1;
    int value, option;

    do{
        cout<<"\n\nWhat operation do you want to perform? select option . Enter 0 to exit"<<endl;

        cout<<"1. Enqueue()"<<endl;
        cout<<"2. Dequeue()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. Count()"<<endl;
        cout<<"6. Display()"<<endl;
        cout<<"7. Clear Screen()"<<endl;

        cin>>option;
        switch(option){
            case 0:
            break;


            case 1:
            cout<<"Enqueue operation \n Enter an item to Enqueue: "<<endl;
            cin>>value;
            q1.enqueue(value);
            break;


            case 2:
            cout<<"Dequeue operation \nDequeue an item: "<<q1.dequeue()<<endl;
            break;


            case 3:
            if(q1.isEmpty())
            cout<<"queue is Empty "<<endl;
            else
            cout<<"queue is not empty"<<endl;
            break;


            case 4:
            if(q1.isFull())
            cout<<"queue is full"<<endl;
            else
            cout<<"queue is not full"<<endl;
            break;


            case 5:
            cout<<"count operation \n count of items in queue "<<q1.count()<<endl;
            break;


            case 6:
            cout<<"Display functino called - "<<endl;
            q1.display();
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