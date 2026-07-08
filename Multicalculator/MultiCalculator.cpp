#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <limits>
#include <stdexcept>
using namespace std;

// ---------- Expression Calculator ----------
int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/'||c=='%') return 2;
    return 0;
}

double apply(double a,double b,char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/':
            if(b==0) throw runtime_error("Divide by zero");
            return a/b;
        case '%':
            return (int)a%(int)b;
    }
    return 0;
}

double evaluate(string s){
    stack<double> val;
    stack<char> op;

    for(size_t i=0;i<s.size();){
        if(s[i]==' '){ i++; continue; }

        if(isdigit(s[i])||s[i]=='.'){
            string num;
            while(i<s.size() && (isdigit(s[i])||s[i]=='.'))
                num+=s[i++];
            val.push(stod(num));
        }
        else if(s[i]=='('){
            op.push(s[i++]);
        }
        else if(s[i]==')'){
            while(!op.empty() && op.top()!='('){
                double b=val.top(); val.pop();
                double a=val.top(); val.pop();
                val.push(apply(a,b,op.top()));
                op.pop();
            }
            if(!op.empty()) op.pop();
            i++;
        }
        else{
            while(!op.empty() && op.top()!='(' && prec(op.top())>=prec(s[i])){
                double b=val.top(); val.pop();
                double a=val.top(); val.pop();
                val.push(apply(a,b,op.top()));
                op.pop();
            }
            op.push(s[i++]);
        }
    }

    while(!op.empty()){
        double b=val.top(); val.pop();
        double a=val.top(); val.pop();
        val.push(apply(a,b,op.top()));
        op.pop();
    }
    return val.top();
}

void expressionCalculator(){
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string exp;
    cout<<"\nExpression Calculator\n";
    cout<<"Type 'back' to return.\n";
    while(true){
        cout<<"\nEnter expression: ";
        getline(cin,exp);
        if(exp=="back") break;
        try{
            cout<<"Result = "<<evaluate(exp)<<endl;
        }catch(exception &e){
            cout<<"Error: "<<e.what()<<endl;
        }
    }
}

// ---------- Scientific ----------
long long factorial(int n){
    if(n<0) return -1;
    long long f=1;
    for(int i=2;i<=n;i++) f*=i;
    return f;
}

void scientificCalculator(){
    int ch; double x,y;
    do{
        cout<<"\n--- Scientific Calculator ---\n";
        cout<<"1.Power\n2.Square\n3.Cube\n4.Square Root\n5.Cube Root\n6.Factorial\n7.Log10\n8.Natural Log\n9.Exponential\n10.Back\nChoice: ";
        cin>>ch;

        switch(ch){
            case 1: cin>>x>>y; cout<<pow(x,y)<<endl; break;
            case 2: cin>>x; cout<<x*x<<endl; break;
            case 3: cin>>x; cout<<x*x*x<<endl; break;
            case 4: cin>>x; cout<<sqrt(x)<<endl; break;
            case 5: cin>>x; cout<<cbrt(x)<<endl; break;
            case 6: int n; cin>>n; cout<<factorial(n)<<endl; break;
            case 7: cin>>x; cout<<log10(x)<<endl; break;
            case 8: cin>>x; cout<<log(x)<<endl; break;
            case 9: cin>>x; cout<<exp(x)<<endl; break;
        }
    }while(ch!=10);
}

// ---------- Statistics ----------
void statisticsCalculator(){
    int ch;
    do{
        cout<<"\n--- Statistics ---\n";
        cout<<"1.Mean\n2.Maximum\n3.Minimum\n4.Range\n5.Back\nChoice: ";
        cin>>ch;

        if(ch>=1 && ch<=4){
            int n;
            cout<<"How many numbers? ";
            cin>>n;

            vector<double> v(n);
            for(int i=0;i<n;i++) cin>>v[i];

            double sum=0;
            for(double x:v) sum+=x;

            double mx=*max_element(v.begin(),v.end());
            double mn=*min_element(v.begin(),v.end());

            if(ch==1) cout<<"Mean = "<<sum/n<<endl;
            if(ch==2) cout<<"Maximum = "<<mx<<endl;
            if(ch==3) cout<<"Minimum = "<<mn<<endl;
            if(ch==4) cout<<"Range = "<<mx-mn<<endl;
        }
    }while(ch!=5);
}

// ---------- Unit Converter ----------
void unitConverter(){
    int ch;
    double v;
    do{
        cout<<"\n--- Unit Converter ---\n";
        cout<<"1.Celsius -> Fahrenheit\n";
        cout<<"2.Fahrenheit -> Celsius\n";
        cout<<"3.Meter -> Kilometer\n";
        cout<<"4.Kilometer -> Meter\n";
        cout<<"5.Gram -> Kilogram\n";
        cout<<"6.Kilogram -> Gram\n";
        cout<<"7.Inch -> Centimeter\n";
        cout<<"8.Centimeter -> Inch\n";
        cout<<"9.Back\nChoice: ";
        cin>>ch;

        switch(ch){
            case 1: cin>>v; cout<<(v*9/5)+32<<endl; break;
            case 2: cin>>v; cout<<(v-32)*5/9<<endl; break;
            case 3: cin>>v; cout<<v/1000<<endl; break;
            case 4: cin>>v; cout<<v*1000<<endl; break;
            case 5: cin>>v; cout<<v/1000<<endl; break;
            case 6: cin>>v; cout<<v*1000<<endl; break;
            case 7: cin>>v; cout<<v*2.54<<endl; break;
            case 8: cin>>v; cout<<v/2.54<<endl; break;
        }
    }while(ch!=9);
}

int main(){
    int ch;
    do{
        cout<<"\n========== MULTI CALCULATOR ==========\n";
        cout<<"1.Expression Calculator\n";
        cout<<"2.Scientific Calculator\n";
        cout<<"3.Statistics Calculator\n";
        cout<<"4.Unit Converter\n";
        cout<<"5.Exit\n";
        cout<<"Choice: ";
        cin>>ch;

        switch(ch){
            case 1: expressionCalculator(); break;
            case 2: scientificCalculator(); break;
            case 3: statisticsCalculator(); break;
            case 4: unitConverter(); break;
            case 5: cout<<"Thank You!\n"; break;
            default: cout<<"Invalid Choice\n";
        }
    }while(ch!=5);
    return 0;
}
