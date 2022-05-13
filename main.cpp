/*
    answered by:
        Ziyad Ashraf Ali                20200197
        Nouran Ahmed Abdelaziz          20200609
        Abdelrahman Mohamed Ramadan     20200293
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BigInt
{
private:
    string number;
    long long sum,carry;
public:





    /// Initialize from string
    BigInt (string decStr="")
    {
        number = decStr;
    }

    /// Initialize from integer
    BigInt (long long decInt)  //we use (long long) Until we were able to enter 18 digits
    {
        while(decInt>0)
        {

            number+=(decInt%10)+48;   //TO convert the number into  string using ASCII
            decInt/=10;
        }
        reverse(number.begin(),number.end());
    }


    BigInt operator+(BigInt num2)
    {
        BigInt num3;
        num3.number = "";
        num3.carry=0;
        for(int i =(number.length()-1);i>=0;i-- ){
            num3.sum = 0;
            num3.sum = (number[i]-48) + (num2.number[i]-48) + num3.carry;   //TO convert the number into  integer (subtract from char 0) using ASCII
            num3.carry=0;
            if(num3.sum>9){
                num3.sum-=10;
                num3.carry++;
            }

            num3.number+=num3.sum+48;       //TO convert the number into string using ASCII
        }
        if(num3.carry>0){
            num3.number+=num3.carry+48;
        }
        reverse(num3.number.begin(),num3.number.end());     //we should reverse number as string, So we store it inverted
        return num3;
    }




    BigInt operator-(BigInt num2)
    {
        BigInt num3;
        num3.number = "";
        num3.carry = 0;
        for(int i =(number.length()-1);i>=0;i-- )
        {
            num3.sum = 0;
            num3.sum = (number[i] - 48) - (num2.number[i] - 48) - num3.carry;  //TO convert the number into  integer (subtract from char 0) using ASCII
            num3.carry = 0;
            //cout<<num3.sum<<endl;
            if(num3.sum<0){
                num3.sum+=10;
                num3.carry++;
            }
            num3.number+=num3.sum+'0';
        }
        reverse(num3.number.begin(),num3.number.end());



        while(num3.number[0]=='0'){
            for(int i=0;i<num3.number.length();i++){
                num3.number[i]=num3.number[i+1];
            }

        }

        return num3;

    }

    BigInt operator= (BigInt num2)
    {
        number = num2.number;

        return BigInt(number);
    }



    //overwrite the << operator
    friend ostream& operator<<(ostream& out,BigInt obj)
    {
        cout<<obj.number;
    }

    //return number of digit
    int size()
    {
        return number.length();
    }


};

int main()
{
    ////cout<<121%10;
    //cout<<(123456%10)+'0';

    //cout<<char(54);

    /*string num = "";
    int decint = 123456;

    while(decint>0){

        num+=(decint%10)+'0';
        decint/=10;
    }
    cout<<num;

    //BigInt num1(235);    //Do not exceed 9 numbers
    //BigInt num2(127);    //Do not exceed 9 numbers
    //BigInt num3;
    //num3 = num1 - num2;
    //cout<<num1<<" - "<<num2<<" = "<<num3<<endl;



    //cout<<char()<<endl;*/




    /*string s = "357";
    int sum = 0;
    int i = 0;
    for (i = 0; i < s.length(); i++) {
        sum += s[i] - 48;
    }
    printf("Sum is %d", sum);*/




    BigInt num1(333365146515165);
    BigInt num2(222244987984884);
    cout<<num1<<" + "<<num2<<" = "<<num1+num2<<endl;
    cout<<num1<<" - "<<num2<<" = "<<num1-num2<<endl<<endl;


    BigInt num3("123456789012345678901234567890");
    BigInt num4("113456789011345678901134567890");
    cout<<num3<<" + "<<num4<<" = "<<num3+num4<<endl;
    cout<<num3<<" - "<<num4<<" = "<<num3-num4<<endl;
    /*cout<<"num3 + num4 = "<<num3 + num4<<endl;

    BigInt num5 = num3 + num4;

    cout<<num3<<" - "<<num4<<" = "<<num5<<endl;*/





    return 0;
}
