#include<iostream>
#include<stdlib.h>
using namespace std;
class complex{
    public:
        char oper;
        int a,b,c,d,x,y;
        void print(int x,int y){
            if(y==0)
                cout<<x<<endl;
            else if(x==0 and y==1)//the sequence is important here...
                cout<<"i"<<endl;
            else if(x==0 and y==-1)
                cout<<"-i"<<endl;
            else if(x==0 and y!=0)//...and here!
                cout<<y<<"i"<<endl;
            else if(x!=0 and y==1)
                cout<<x<<"+i"<<endl;
            else if(x!=0 and y==-1)//remember to deal with case "y==-1"
                cout<<x<<"-i"<<endl;           
            else if(x!=0 and y<0)
                cout<<x<<"-"<<-y<<"i"<<endl;
            else//(x!=0 and y>0)
                cout<<x<<"+"<<y<<"i"<<endl;
        }

        void calculate(char oper){
            switch(oper){
                case '+':{
                    cin>>a>>b>>c>>d;
                    x=a+c;
                    y=b+d;
                    print(x,y);
                    break;
                }
                case '*':{
                    cin>>a>>b>>c>>d;
                    x=a*c-b*d;
                    y=a*d+b*c;
                    print(x,y);
                    break;
                }
                case 'p':{
                    cin>>a>>b;
                    x=a;
                    y=b;
                    print(x,y);
                    break;
                }
                default:
                    break;
            }
        }      
};

int main(){
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        complex data;
        cin>>data.oper;
        data.calculate(data.oper);
    }
    system("pause");
    return 0;
}