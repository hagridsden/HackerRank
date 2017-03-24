#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node
{
    int n;
    struct node * left;
    struct node * right;
}node;

typedef struct queuenode
{
    node * nd;
    int level;
    struct queuenode * next;
}queuenode;

queuenode * enqueue(queuenode * end, node * n, int lev)
{
    end->next = new queuenode();
    end->next->nd = n;
    end->next->level = lev+1;
    end->next->next = NULL;
       
    return end->next;    
}

queuenode * dequeue(queuenode * front)
{
    return front->next;
}

queuenode * insertnode(int l, int r, queuenode * f, queuenode * e)
{
    node * ptr = f->nd;
   
    if(l == -1 && r == -1)
        return e;
    else
    {
       if(l != -1)
        {
            ptr->left = new node();
            ptr->left->n = l;
            ptr->left->left = NULL;
            ptr->left->right = NULL;
            e = enqueue(e,ptr->left, f->level);            
        }   
        if(r != -1)
        {    
            ptr->right = new node();
            ptr->right->n = r;
            ptr->right->left = NULL;
            ptr->right->right = NULL;
            e = enqueue(e,ptr->right, f->level);   
        }
    }    
    return e;
}

void inorder(node * root)
{
    if(root->left)
        inorder(root->left);
        
    cout<<root->n<<" ";
    
    if(root->right)
        inorder(root->right);
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    node * root=NULL;
    node * ptr;
    int N, T, l, r;
    queuenode * front = new queuenode();
    queuenode * end;
    queuenode * frontcopy, * p;
 
    cin>>N;
    
    if(N>0)
    {   root = new node();
        root->n = 1;
        root->left=NULL;
        root->right = NULL;
        
        front->nd = root;
        front->level = 1;
        front->next = NULL;  
        end = front;
        frontcopy = front;
    }
    
    for(int i=1;i<=N;i++)
    {
        cin>>l>>r;
        end = insertnode(l,r,front,end);
        front = front->next;
    }
    
     cout<<"\nTree before Swapping : ";
     inorder(root);
     cout<<"\n";
     cin>>T;
     int k[T]; 
     
     for(int j =0; j<T; j++)
    {
        cin>>k[j];
    }
    
    for(int j =0; j<T; j++)
    {
        p = frontcopy;
        int x = 1;
        while(p)
        {
            if(p->level > (k[j]*x) )
                x++;
        //    cout<<"\n x="<<x;
        
            if(p->level == k[j]*x )
            {
                    ptr = p->nd->left;      //SWAPPING
                    p->nd->left = p->nd->right;
                    p->nd->right = ptr;
            }
            p = p->next;
        }    
    cout<<"\n";
    inorder(root);  
    }   
    
    return 0;
}
