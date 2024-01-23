#include<bits/stdc++.h>
#include <cmath>
using namespace std;

template<typename T>
class calculator{
    
    T number;
    T result;
    
public:
    calculator(){

        cout<<"Enter a number:";
        cin>>result;
    }

    int reset(){

        cout<<"\nResetting the value to 0\n";
        number = 0;
        result = 0;
        return 0;
    }

    T input(){
        cout << "Enter a number : ";
        cin >> number;
        return number;
    }
    
    T add(){
        result += number;
        return result;
    }
    
    T subtract(){
        result -= number;
        return result;
    }
    
    T multiply(){
        result *= number;
        return result;
    }
    
    T division(){
        if (number == 0) {
            cout << "Cannot divide by zero!\n" << endl;
            throw true;
        }
        result /= number;
        return result;
    }
    
    T exponent(){
        result = pow(result, number);
        return result;
    }
    
    
    T modulus(){
        result = fmod(result,number);
        return result;
    }
    
    long factorial(long number=0){
        if(number==0){
            number=this->number;
        }
        if (number == 1) {
            return 1;
        }
        result=number * factorial(number - 1);
        return result;
        
    }

    T output(){
        cout << "\nResult = " << result << endl;
        return result;
    }
};

int main(){

    try{
        
       
 
        mark_reset:
        cout << "ENTER: \n+ TO ADD\n- TO SUBTRACT\n* TO MULTIPLY \n/ TO DIVISION \n^ TO EXPONENT \n! TO FACTORIAL \n% TO MODULUS\nc TO RESET" << endl;
        calculator<double> calc;
        marker:
        calc.input();

        
        char operation;
        cout<<"ENTER OPERATION";
        cin >> operation;
        

        switch(operation){
            case '+':
                cout << calc.add()<<endl;
                goto marker;
            case '-':
                cout << calc.subtract()<<endl;
                goto marker;
            case '*':
                cout << calc.multiply()<<endl;
                goto marker;
            case '/':
                cout << calc.division()<<endl;
                goto marker;
            case '^':
                cout << calc.exponent()<<endl;
                goto marker;
            case '%':
                cout << calc.modulus()<<endl;
                goto marker;
            case '!':
                cout << calc.factorial()<<endl;
                goto marker;
            case 'c':
                calc.reset();
                goto mark_reset;
            default:
                cout<<calc.output()<<endl;
                break;
        }
    } catch(const bool e){
        if (e == true) {
            cout << "ERROR: WRONG INPUT" << endl;
        }
    }


    return 0;
}
