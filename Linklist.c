#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
   struct node *next;
}*first=NULL,*z=NULL;
void create(int a[],int n){
    int i;struct node *t,*last;
    first=(struct node*)malloc (sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct node*)malloc (sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }    
}
void display(struct node *p){
 if(p) { printf("%d ",p->data);
 display(p->next);
 }
}
int sum(struct node *p){int x=0;
    while(p){
        x+=p->data;
        p=p->next;
    }
    return x;
}
int Rsum(struct node *p){
   if(p)
    return Rsum(p->next)+p->data;
    else return 0;
}
int count (struct node *p){int k=0;
    while(p)
  {  k++;
    p=p->next;
    }
    return k;
}
int Rcount (struct node *p){int k=0;
 if(p) return (Rcount(p->next)+1);
    else return 0;
}
  void find(struct node *p,int n){
    while(p){
        if(p->data==n)
       { printf("\n element is found");
        break;}
        p=p->next;
    }
    if(!p){
  printf("\n element does not exist ");
    }
}

int Rfind(struct node *p,int n){
   if(p) {
        if(p->data==n)
     {   printf("element is found");
     return 0;}
    }
    else {
    printf("element does not found");
    return 0;}
    Rfind(p->next,n);   
}
int Max(struct node *p){
    int k=p->data;p=p->next;
    while(p){
        if(p->data>k)
       { k=p->data;p=p->next;}
       else if(p->data>k){p=p->next; }
       else{ p=p->next;}
    }
    return k;
}
void Qfind(struct node *p,int n){struct node *q=NULL;
    while(p){
        if(p->data==n)
       { printf("\n element is found");
         q->next=p->next;
         p->next=first;
         first=p; 
        break;}
      else{  q=p;
        p=p->next;}
    }
    if(!p){
  printf("\n element does not exist ");
    }
}
void insert(struct node*p){int i,data;
    printf("Enter the value of index and data");
    scanf("%d%d",&data,&i);
    if(i==0){
        struct node *t=(struct node*)malloc(sizeof(struct node));
        t->data=data;
        t->next=first;
        first=t;
    }
    else{
       struct node *t=(struct node*)malloc(sizeof(struct node));
         t->data=data;
         struct node*l=first;
         for(int k=0;k<i-1;k++){
             l=l->next;
         } t->next=l->next;
         l->next=t;
    }
}
void lcreate(int x){struct node *last,*t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=NULL;
    if(first==NULL){
       
        last=first=t;
    }
    else{
        last->next=t;
        last=t;
    }
}
void sortinsert(struct node*p,int key){
    struct node *q,*t=(struct node*)malloc(sizeof(struct node));
    t->data=key;
    t->next=NULL;
   if(first==NULL){
       first=t;
   }
    else{
        while(key>p->data&&p){
            q=p;
            p=p->next;
             } if(p==first){
                 t->next=first;
                 first=t;
             }
             else{t->next=q->next;
                 q->next=t;
             }
            
    }
}
int Delete(struct node *p,int index){
struct node*q=NULL;int x=-1,i;
if(index<1||index>count(p))
return -1;
if(index==1){
    q=first;
    x=first->data;
    first=first->next;
    free (q);
    return x;

}
else{
for(i=0;i<index-1;i++){
q=p;
p=p->next;}q->next=p->next;x=p->data;
free(p);
return x;
}
}
int sortknow(struct node *p){int x=-65536;
    while (p!=NULL){
    if(p->data<x)
    return 0;
     x=p->data;
     p=p->next;
     }  
     return 1;
}
void Ksortknow(struct node *p){struct node *q;
q=p->next;
   while(q!=NULL) { if(q->data!=p->data){
         p=q;
             q=q->next;
     }
     else{
         p->next=q->next;
         free(q);
          q=p->next;
     }}
}
void Recursivereverse(struct node *q,struct node *p){
    if(p!=NULL)
   { Recursivereverse(p,p->next);
    p->next=q;}
    else{
        first=q;
    }
}
void reverse2(struct node *p){
    struct node *q,*r;
    q=NULL;r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;  //printf("%d",p->data);
        q->next=r;//printf("%d",q->data);
    }
    first=q;
  
}

int main()
{int n=5;
 int a[]={10,20,30,40,50};
 create(a,n);
//display(first);
//printf("\ntotal number of element present in arrey is %d\n",count(first));
//printf("\nsum of this arrey is %d\n",sum(first));
//printf("\ntotal number of element present in arrey is %d\n",Rcount(first));
//printf("\nsum of this arrey is %d\n",Rsum(first));
//find(first,5);
//Rfind(first,500);
//printf("%d", Max(first));
//Qfind(first,3330);
//insert(first);
//lcreate(2);
{//sortinsert(first,16);
{/**sortinsert(first,6);        //messive doubt in this function yet to solve
sortinsert(first,25);**/}}
//printf("\n%d\n",Delete(first,4));
//printf("\n%d\n",sortknow(first));
//Ksortknow(first);
//Recursivereverse(NULL,first);
reverse2(first);
display(first);
return 0;
};