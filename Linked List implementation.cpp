#include <iostream>

using namespace std;

class linked_list{
    
public:
    //getters 
    float get_item(){return item;}
    linked_list *get_next(){return next;}
    linked_list *get_pre(){return pre;}
    //setters
    void set_item(float i){item=i;}
    void set_next(linked_list *i){next=i;}
    void set_pre(linked_list *i) {pre=i;}
    void add_front(float i);
    void add_back (float i);
    void insert (float  i,int j);
    bool isEmpty();
    int count ();
    void reverse ();
    float get_avr();
    void printList();
private:
    float item;
    int itemNum;
    linked_list *next=nullptr , *pre=nullptr;
    };
    
linked_list *first=nullptr;
linked_list *last=nullptr;

void linked_list:: printList(){
    if (isEmpty()){cout << "The List Is Empty!!!\n";}
    else {
        
        linked_list *ptr=first;
    while (ptr != nullptr){cout << ptr->get_item() << endl; ptr=ptr->get_next();}
    
        
        }
    
    }

void linked_list::add_front(float i){//addFront
        
            linked_list *newItem= new linked_list();
            newItem->set_item(i);
            if (first==nullptr){first=newItem;last=newItem;}
            else {newItem -> set_next(first);first->set_pre(newItem);first = newItem;}
    
    }//end fun
    
void linked_list ::add_back(float i){
        
            linked_list *newItem= new linked_list();
            newItem->set_item(i);
            if (first==nullptr){first=newItem;last=newItem;}
            else {last->set_next(newItem);newItem->set_pre(last);last=last->get_next();}
        
        }
        
void linked_list :: insert(float i,int j){
    
            linked_list *newItem= new linked_list();
            linked_list *ptr=nullptr;
            int counter=0;
            newItem->set_item(i);
            if (first==nullptr){first=newItem;last=newItem;}
            else {
            ptr=first;
            while (ptr != nullptr && counter< j){//while
                
                    ptr=ptr->get_next();
                    counter++;
                    
            }//end While 
            if (ptr!= nullptr){
                
                newItem->set_pre(ptr->get_pre());
                newItem->set_next(ptr);
                ptr->set_pre(newItem);
                ptr=ptr->get_pre();
                ptr=ptr->get_pre();
                ptr->set_next(newItem);
                
            }
            else {//else #1
                
                    last->set_next(newItem);
                    newItem->set_pre(last);
                    last=last->get_next();
                
            }//Else #2
                
        }//end else
    
        }//end fun
        
void linked_list :: reverse(){
    if (isEmpty()){cout << "The List Is Empty!!!\n";}
    else {
        
    linked_list *temp=new linked_list();
    linked_list *ptr=nullptr;
    temp=last;
    first=last;
    while (temp->get_pre()!= nullptr){
        
        ptr=temp->get_next();
        temp->set_next(temp->get_pre());
        temp->set_pre(ptr);
        temp=temp->get_next();
        }
    last=temp;
    ptr=temp->get_next();
    temp->set_next(temp->get_pre());
    temp->set_pre(ptr);
    
        
        }//else
    
    }
    
 bool linked_list :: isEmpty(){
     
     if (first == nullptr)return true;
     return false;
     
     }

int linked_list :: count (){
    
    linked_list *ptr=first;
    int i=0;
    while (ptr != nullptr){
        
        i++;
        ptr=ptr->get_next();
        
        }
    return i;
    }
    
float linked_list :: get_avr(){
    if (isEmpty()){cout << "The List Is Empty!!!\n";return 0;}
    else {
        
        int i = count();
    float total=0;
    linked_list *ptr=first;
    while (ptr != nullptr){
        
        total+=ptr->get_item();
        ptr=ptr->get_next();
        
        }
    total/=float (i);
    return total;
    
        }
    
    }
int main (){//begin main 
    
    linked_list myList;
    float item;
    char selectI;
    cout << "Please Select An Operation From List Below\n(a)Add Front\n(b)Add back\n"; 
    cout <<"(c)Add At certain Position\n(d)Reverce List\n(e)Print List\n(f)Calculate Average\n";
    cout <<"(g)Get size\n(h)Check If The List Is Empty\n(q)Quit\n";
    cout <<"**********************************************************************\n";
    cin>>selectI;
while (selectI != 'q'){
    
      switch( selectI )
{
case 'a':
    cout << "Enter A Number: ";
    cin >>item;
    myList.add_front(item);
break;
case 'b':
    cout << "Enter A Number: ";
    cin >>item;
    myList.add_back(item);
break;
case 'c':
    int j;
    cout << "Enter A Number: ";
    cin >>item;
    cout << "Enter The Position: ";
    cin>>j;
    myList.insert(item,j);
break;
case 'd':
    myList.reverse();
break;
case 'e':
    myList.printList();
break;
case 'f':
    cout << myList.get_avr()<<endl;
break;
case 'g':
    cout << myList.count()<<endl;
break;
case 'h':
    if (myList.isEmpty()){cout << "The List Is Empty\n";}
    else {cout <<"The List Is Not Empty\n";}
break;
}
    cin>>selectI; 
    }
  
    
    
}//end main 

