
#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
class Node{
public:

T value;
Node* next;
Node(T value){
    Node::value=value;
     next=nullptr;
}

};
template<class T>
class LinkedList{
private:
    int length;
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList(){
    length=0;
    head=nullptr;
    tail=nullptr;
    }

    int size(){
    return length;
    }
    bool empty(){
    return length==0;
    }
    void append(T value){
      Node<T>* newNode=new Node<T>(value);
      if(length==0){
        head=tail=newNode;

      }
      else{
        tail->next=newNode;
        tail=newNode;
         tail->next=nullptr;
      }
      length++;
    }
    void pop(){
        if(length==1){
        delete head;
           head=tail=nullptr;

        }
        else{

           Node<T>*  iterator=head;
           while(iterator->next!=tail){
             iterator= iterator->next;
           }
            delete tail;
           tail=iterator;
           tail->next=nullptr;

        }
      length--;
    }
     void insert(int index,T value){
           assert(index>=0 && index<=length);

            if(index==0){
            Node<T>* newNode=new Node<T>(value);
             newNode->next=head;
             head=newNode;
                 length++;
            }
            else if(length+1==index){
          append( value);
            }
            else{
            Node<T>* newNode=new Node<T>( value);
              Node<T>*  iterator=head;
              for(int i=0;i<index-1;i++){
              iterator= iterator->next;

                }
                newNode->next=iterator->next;
              iterator->next=newNode;
               length++;
            }

            }

          void erase(int index){
             assert(index>=0 && index<=length-1);
             if(index==0){
               Node<T>* temp=head->next;
             delete head;
             head=temp;
              length--;
             }
            else if(length-1==index){
             pop();
              }
            else{
                Node<T>* iterator=head;
              for(int i=0;i<index-1;i++){
                iterator=iterator->next;

              }
               Node<T>* nodeDelete=iterator->next;
               Node<T>* nodeAfter=iterator->next->next;
                delete nodeDelete;
                iterator->next=nodeAfter;
                length--;

            }

          }
    void Print(){
     Node<T>* iterator=head;
     while(iterator != nullptr){
        cout<<iterator->value<<" ";
        iterator=iterator->next;


     }
    }

};
int main() {


LinkedList<int> l;
l.append(5);
l.append(2);
l.append(8);
l.append(3);
l.append(7);
l.insert(2,20);
l.Print();
l.erase(3);
cout<<endl;
l.Print();
l.pop();
cout<<endl;
l.Print();
l.append(30);
cout<<endl;
l.Print();


}


