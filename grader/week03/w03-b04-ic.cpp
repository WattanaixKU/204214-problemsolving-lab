#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};
int main()
{
    int n,inp;
    bool started = false;
    string command;
    cin >> n;
    node* left,*right = NULL;
    for(int e=0;e<n;e++)
    {
        cin >> command;
        if(command[1] == 'i')
        {
            cin >> inp;
            node* newnode = new node;
            newnode->data = inp;
            newnode->prev = NULL;
            if(command[0] == 'l')
            {
                if(!started)
                {
                    newnode->next = NULL;
                    right = newnode;
                    started = true;
                }
                else
                {
                    newnode->next = left; 
                    left->prev = newnode;
                }
                left = newnode;
            }
            else 
            {
                if(!started)
                {
                    newnode->prev = NULL;
                    left = newnode;
                    started = true;
                }
                else
                {
                    newnode->prev = right;
                    right->next = newnode;
                }
                right = newnode;
            }
        }
        else
        {
            if(left == right)
                continue;
            if(command[0] == 'l')
            {
                right->next = left;
                left->prev = right;
                right = left;
                left=left->next;
            }
            else 
            {
                right->next = left;
                left->prev = right;
                left=right;
                right=right->prev;
            }
            right->next = NULL;
            left->prev = NULL;
        }
        
    }
    while(left!=NULL) 
    {
        cout << left->data << endl;
        left = left->next;
    }
    return 0;
}