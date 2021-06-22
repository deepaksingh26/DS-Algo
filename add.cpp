#include<iostream>
using namespace std;

class element{
public:    
int i,j,x;
};
class sparse{private:int m,n,num;
 element *e;     
 public:
sparse(int m,int n,int num){
    this->m=m;
    this->n=n;
    this->num=num;
   e=new element [this->num];
}
~sparse(){
delete []e;
}
 void read(){

     cout<<"Enter all non zero element";
    for(int i=0; i<num;i++){
        cin>>e[i].i>>e[i].j>>e[i].x;
    }
 }
 void display(){int k=0;
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
             if (e[k].i==i && e[k].j==j){
                 cout<<e[k++].x<<" ";
             }
             else {
                 cout<<"0 ";
             }   
           
         }   cout<<endl;
         }
 }
 sparse operator+(sparse &s){ 
     if(m!=s.m||n!=s.n){
     }
     else {int i,j,k;
           i=j=k=0;
           sparse *sum=new sparse(m,n,num+s.num);
         while(i<num &&j<s.num){
             if(e[i].i<s.e[j].i)
             sum->e[k++]=e[i++];
             else if (e[i].i>s.e[j].i)
             {
                  sum->e[k++]=e[j++];            
             }
             else{
                 if(e[i].j<s.e[j].j)
                 sum->e[k++]=e[i++];
                else if(e[i].j>s.e[j].j)
                 sum->e[k++]=s.e[j++];
                 else{
                     sum->e[k]=e[i];
                     sum->e[k++].x=e[i++].x+s.e[j++].x;
                 }
             }
            }
             for(;i<num;i++)sum->e[k++]=s.e[j++];
            for(;j<s.num;j++)sum->e[k++]=s.e[i++];
            sum->num=k;
            return *sum;
     }
  
     
 }
};

 main(){
    sparse s1(3,3,3);
    sparse s2(3,3,3);
    s1.read();
    s2.read();
    sparse sum=s1+s2;
    cout<<"FIRST MATRIX\n";
     s1.display();
     cout<<"SECOND MATRIX\n";
     s2.display();
     cout<<"SUM OF MATRIX\n";
     sum.display();
 }