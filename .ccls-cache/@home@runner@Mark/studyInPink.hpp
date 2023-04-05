#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

bool numCheck(char c) {
    if (c<'0' || c>'9') return 0;
    return 1;
}
int charTo_Int(char a, char b, char c) {
    int x = a- '0';
    int y = b- '0';
    int z = c- '0';
    return x*100 + y*10 +z;
}
std::string notebook1(std::string name) {
    std::ifstream note1;
    note1.open(name, std::ios::out);

    char data[20];
    note1 >> data;
    char a1,a2,a3;
    int n1;
    //Freq/First/<n1>
    if (numCheck(data[11])&&numCheck(data[12])&&numCheck(data[13])) {
        n1= charTo_Int(data[11],data[12],data[13]);
    }
    else n1= -1;

    int datanum;
    int nums[10]= {0};
    std::string result="";
    int count=0;
    while (count<n1) {
        note1>> datanum;
        nums[datanum]++;
        count++;
    }
    for (int i=0; i<10; i++){
        result+= std::to_string(nums[i]%10);
    }
    note1.close();

    return result;
}

int countStr(std::string str, std::string s) {
    int cnt= 0;
    int Npos= str.find(s,0);
    while (Npos != std::string::npos) {
        cnt++;
        Npos= str.find(s, Npos+1);
    }
    return cnt;
}
std::string notebook2(std::string name) {
    std::ifstream note2;
    note2.open(name, std::ios::out);

    char data[10];
    note2>> data;
    int n2=0;
    //"0000n"
    for (int i=0; i<5; i++)
        if (!numCheck(data[i])) n2--;
    if (n2>-1) n2= charTo_Int(data[2],data[3],data[4]);
    if (n2<5 || n2>100) return "1111111111";

    std::string str;
    std::getline(note2, str,'\n');
    int cntP= 0;
    for (int i= 0; i < n2; i++) {
            std::getline(note2, str);
        cntP+= countStr(str, "pink") + countStr(str, "Pink");
    }
    
    std::string result="";
    if (cntP<100000) cntP= cntP*cntP;
    result+= std::to_string(cntP);
    for (int i=0; i<10; i++) {
        if (!result[i]) result+= "9";
    }
    note2.close();
    return result;
}

void toPrime(int &n) {
    if (n==0||n==1) n=2;
    if (n==2||n==3) return;
    for (int i=3; i*i<n; i++) {
        if (n%i==0) {
            n++;
            toPrime(n);
            break;
        }
    }
    return;
}
void toFibo(int &n, int pre=1, int cur=1) {
    if (n==0||n==1||n==2) return;
    int  carry;
    for (int i=1; i<n; i++) {
        carry= cur;
        cur+= pre;
        pre= carry;
        if (n == cur) return;
        if (n < cur) {
            n++;
            toFibo(n);
            break;
        }
    }
    return;
}
void swap(int &a, int &b) {
    int carry = a;
    a= b;
    b= carry;
    return;
}
std::string notebook3(std::string name) {
    std::ifstream note3;
    note3.open(name, std::ios::out);

    std::string str;
    int data[10][10];
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++) {
            std::getline(note3, str, '|');
            std::stringstream ss;
            ss << str;
            ss >> data[i][j];
            if (data[i][j]<0) data[i][j]= abs(data[i][j]);
        }
    for (int i= 0; i<10; i++) {
        for (int j= i+1; j<10; j++)
            toPrime(data[i][j]);
        for (int j=0; j<i; j++)
            toFibo(data[i][j]);
    }
    for (int i= 0; i<10; i++) {
        for (int j= 8; j<10; j++) {
            if (data[i][j-1]>data[i][j])
            swap(data[i][j-1],data[i][j]);
        }
    }
    std::string result="";
    for (int i=0; i<10; i++) {
        int index= 0;
        for (int j=1; j<10; j++) {
            if (data[i][index]<=data[i][j]) index= j;
        }
        result+= std::to_string(index);
    }
    return result;
}
std::string g(std::string p1, std::string p2) {
    std::stringstream ss;
    std::string group="";
    int n1, n2;
    int extra=0;
    for (int i=0; i<10; i++) {
        ss.clear();
        ss << p1[i];
        ss >> n1;
        ss.clear();
        ss << p2[i];
        ss >> n2;
        group+= std::to_string((n1+n2+extra)%10);
        extra= (n1+n2+extra)/10;
    }
    return group;
} 
std::string generateListPasswords(std:: string str1, std:: string str2, std:: string str3) {
    std::string str4= g(str1, str2);
    std::string str5= g(str1, str3);
    std::string str6= g(str2, str3);
    std::string str7= g(str4, str3);
    std::string str8= g(str1, str6);
    std::string str9= g(str4, str5);
    std::string result= "";
    result= str1 + "," + str2 + "," + str3 + "," + str4 + "," + str5  + "," + str6  + "," + str7  + "," + str8  + "," + str9;
    return result;
}
std::string enterLaptop(std::string name, std::string text) {
    std::ifstream lap;
    lap.open(name, std::ios::out);

    std::string str, temp, email;
    std::getline(lap, str);
    std::stringstream ss;
    ss << str;
    ss >> temp;
    ss >> email;

    int n3;
    std::getline(lap, str);
    ss.clear();
    ss << str;
    ss >> temp;
    ss >> n3;

    std::string pwdL;
    for (int i=0; i<n3; i++) {
        pwdL+= text;
    }
    return email + ";" + pwdL;
}