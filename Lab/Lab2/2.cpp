#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class PrimeFactorization {
    private://to protect changes from outside the class
	    long long num1, num2, num1xnum2;
	    vector<int> num1_factor, num2_factor;
	
    public:
        int gcd;//can't initialize gcd=1 here...(row50)

	    PrimeFactorization() {
	    //default constructor
        }
	    PrimeFactorization(long long a, long long b) {
            num1=a;
            num2=b;
            num1xnum2=a*b;
            vector<int>num1_factor(1,0);//initialize the vector is much safer!
            vector<int>num2_factor(1,0);
	    }
	    void Get_Prime_Factorization() {
            for(int i=2;i<=num1;i++){
                while(num1%i==0){
                    num1_factor.push_back(i);
                    num1/=i;
                }
            }
            for(int i=2;i<=num2;i++){
                while(num2%i==0){
                    num2_factor.push_back(i);
                    num2/=i;
                }
            }
	    }

	    void Print_Prime_Factorization() {
            cout<<"num1_Prime_factor : \" ";// use escape character to print double quotes
            for(int i=0;i<num1_factor.size();i++){
                cout<<num1_factor[i]<<" ";
            }
            cout<<"\"\nnum2_Prime_factor : \" ";
            for(int i=0;i<num2_factor.size();i++){
                cout<<num2_factor[i]<<" ";
            }
            cout<<"\"\n";            
	    }

    	void Print_GCD() {
            gcd=1;// (row12)..., so we defined it here!
            for(int i=0;i<num1_factor.size();i++){
                for(int j=0;j<num2_factor.size();j++){
                    if(num1_factor[i]==num2_factor[j]){
                        gcd*=num1_factor[i];
                        num2_factor.erase(num2_factor.begin()+j);
                        break;
                    }
                }
            }
	    	cout<<"GCD : "<<gcd<<endl;
	    }

    	void Print_LCM() {// lcm(a,b)=|a*b|/gcd(a,b)
            cout<<"LCM : "<<num1xnum2/gcd<<endl;
	    }

    };

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;

		cout << "num1 = " << a << endl;
		cout << "num2 = " << b << endl;

		PrimeFactorization PF(a, b);

		PF.Get_Prime_Factorization();
		PF.Print_Prime_Factorization();
		PF.Print_GCD();
		PF.Print_LCM();

		cout << endl;

	}

	system("PAUSE");
	return 0;
}