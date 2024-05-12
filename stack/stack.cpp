#include<iostream>
#include<string>

using namespace std;

class stack{
    private:
    int top;
    int arr[5];

    public:
    stack(){
        top = -1;
        for(int i=0;i<5;i++){
            arr[i] = 0;

        }

    }

    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }

    bool isFull(){
        if(top == 4)
            return true;
        else
            return false;
    }

    void push(int val){
        if(isFull()){
            cout<<"stack overflow "<<endl;
        }else{
            top++;
            arr[top] = val;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"stack overflow "<<endl;
            return 0;

        }else{
            int popValue = arr[top];
            arr[top] = 0;
            top --;
            return popValue;
        }
    }

    int count(){
        return (top +1);
    }

    int peek(int pos){
        if(isEmpty()){
            cout<<"stack underflow"<<endl;
            return 0;
        }else{
            return arr[pos];
        }
    }

    void change(int pos, int val){
        arr[pos] = val;
        cout<<"value chaged at location "<<pos<<endl;
    }
    void display(){
        cout<<"all the values in the stack are: "<<endl;

        for(int i= 4; i>=0 ;i--){
            cout<<arr[i]<<endl;
        }
    }
    

};

int main(){
    stack s1;
    int option, position, value;

    do{
        cout<<"what operation do you want to perform? select option number. Enter 0 to exit."<<endl;

        cout<<"1. Push() "<<endl;
        cout<<"2. Pop() "<<endl;
        cout<<"3. isEmpty() "<<endl;
        cout<<"4. isFull() "<<endl;
        cout<<"5. Peek() "<<endl;
        cout<<"6. Count() "<<endl;
        cout<<"7. Change() "<<endl;
        cout<<"8. Display() "<<endl;
        cout<<"9. Clean screen() "<<endl;

        cin>>option;

        switch(option){
            case 0:
            break;

            case 1:
            cout<<"Enter an item to push in the stack: "<<endl;
            cin>>value;
            s1.push(value);
            break;

            case 2:
            cout<<"Pop function called - poped value: "<<s1.pop()<<endl;
            break;

            case 3:
            if(s1.isEmpty())
                cout<<"Stack is Empty "<<endl;
            else
                cout<<"Stack is not empty "<<endl;
            break;

            case 4:
            if(s1.isFull())
                cout<<"stack is full "<<endl; 
            else   
                cout<<"stack is not full"<<endl;

            break;

            case 5:
            cout<<"Enter position of item you wnat to peek: "<<endl;
            cin>>position;

            cout<<"peek function called - value at position "<<position<<" is "<<s1.peek(position) <<endl;
            break;

            case 6:
            cout<<"Count function called - Number of Items in the stack are "<<s1.count()<<endl;
            break;

            case 7:
            cout<<"change function called - "<<endl;
            cout<<"Enter position of item you want to change: ";
            cin>>position;
            cout<<endl;
            cout<<"Enter position of item you want to change: ";
            cin>>value;
            s1.change(position, value);
            break;


            case 8:
            cout<<"Display Function Called- "<<endl;
            s1.display();
            break;

            case 9:
            system("cls");
            break;

            default:
            cout<<"Enter Proper Option Number: "<<endl;


        }
        

    }

    while(option != 0);
    return 0;

}