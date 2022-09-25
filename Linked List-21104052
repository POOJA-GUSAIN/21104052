#include <iostream>
using namespace std;
struct Node {
   string member;
   string name;
   int age;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;
//insert data into the beginning of the doubly linked list
void insert(string newmember,string newname,int newage) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->member = newmember;
   newnode->name = newname;
   newnode->age = newage;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
   head->prev = newnode ;
   head = newnode;
}
void display() {
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->member <<" ";
      cout<<ptr->name <<" ";
      cout<<ptr->age<<" <---> ";
      ptr = ptr->next;
   }
   }
int main() {
   insert("father","kishan",48);
   insert("mother","manju",38);
   insert("son","kunal",14);
   insert("daughter","pooja",19);
   
   cout<<"The doubly linked list is: ";
   display();
   return 0;
}
