//
//  main.cpp
//  CPPAlgorithm
//
//  Created by xujw on 15-4-3.
//  Copyright (c) 2015年 xujw. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include "Split.h"
#include "math.h"
#include "CCSVParse.h"
using namespace std;

//检测某个类型的最大最小值
#include <limits>
//插入排序
bool sortByinsert(vector<int>& arr)
{
    if (arr.empty())
    {
        cout<<"arr is empty"<<endl;
        return false;
    }
    if (arr.size()==1)
    {
        cout<<"size of arr is one"<<endl;
        return true;
    }
    int len = arr.size();
    for (int i=1; i<len; i++)
    {
        int value = arr.at(i);
        int j = i-1;
        //find the index of the value
        while (j>=0 && arr[j]>value)
        {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = value;
    }
    return true;
}
void sortByInsert2(int len,int*arr)
{
    for (int i = 1; i<len; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(vector<int>& arr)
{
    for (int index = 0; index<arr.size(); index++)
    {
        cout<<arr.at(index)<<endl;
    }
}
void printArray(int len,int*arr)
{
    for (int i=0; i<len; i++)
    {
        cout<<arr[i]<<endl;
    }
}

//递归算法1+2+3.....
int recursive_sum(int a)
{
    if (a<=1) {
        return a;
    }
    else{
        return a+recursive_sum(a-1);
    }
}
//阶乘
long factorial(long a)
{
    if (a<1)
    {
        cout<<"wrong number"<<endl;
        return -1;
    }
    if (a==1)
    {
        return 1;
    }
    else
    {
        return a*factorial(a-1);
    }
}

//查找质数
void findZhishu()
{
    
    int  n,m,flag,i,j,num=0;
    printf("n:");
    scanf("%d",&n);
    printf("从2到%d的质数如下：\n",n);
    clock_t bt = clock();
//    printf("===now time:%lu===",bt);
    for(i=2;i<=n;i++)//循环查找质数
    {
        flag=1;
        m=(int)sqrt(i);
        for(j=2;j<=m;j++)
        {
            if(i%j==0)//条件为真时表示不是质数，退出for循环
            {
                flag=0;
                break;
            }
        }
        
        if(flag==1)//条件为真时表示i是质数
        {
            num ++;
            printf("%4d\t",i);
            if(num%10==0)//每行最多输出10个数
                printf("\n");
        }
    }
    printf("\n");
    printf("===count:%d \n",num);
    printf("===used:%fS===",(float)(clock()-bt)/CLOCKS_PER_SEC);
    printf("\n");
}

//找出n以内质数
int Sieve()
{
    int n;
    clock_t bt = clock();
    printf("n:");
    scanf("%d",&n);
    int i, j;
    //素数数量统计
    int count = 0;
    // 分配素数标记空间，明白+1原因了吧，因为浪费了一个flag[0]
    char* flag = (char*)malloc( n+1 );
    // 干嘛用的，请仔细研究下文
    int mpLen = 2*3*5*7*11*13;
    char magicPattern[2*3*5*7*11*13]; // 奇怪的代码，why，思考无法代劳，想！
    for (i=0; i<mpLen; i++)
    {
        magicPattern[i++] = 1;
        magicPattern[i++] = 0;
        magicPattern[i++] = 0;
        magicPattern[i++] = 0;
        magicPattern[i++] = 1;
        magicPattern[i] = 0;
    }
    for (i=4; i<=mpLen; i+=5)
        magicPattern[i] = 0;
    for (i=6; i<=mpLen; i+=7)
        magicPattern[i] = 0;
    for (i=10; i<=mpLen; i+=11)
        magicPattern[i] = 0;
    for (i=12; i<=mpLen; i+=13)
        magicPattern[i] = 0;
    // 新的初始化方法,将2,3,5,7,11,13的倍数全干掉
    // 而且采用memcpy以mpLen长的magicPattern来批量处理
    int remainder = n%mpLen;
    char* p = flag+1;
    char* pstop = p+n-remainder;
    while (p < pstop)
    {
        memcpy(p, magicPattern, mpLen);
        p += mpLen;
    }
    if (remainder > 0)
    {
        memcpy(p, magicPattern, remainder);
    }
    flag[2] = 1;
    flag[3] = 1;
    flag[5] = 1;
    flag[7] = 1;
    flag[11] = 1;
    flag[13] = 1;
    // 从17开始filter，因为2,3,5,7,11,13的倍数早被kill了
    // 到n/13止的，哈哈，少了好多吧
    int stop = n/13;
    for (i=17; i <= stop; i++)
    {
        // i是合数，请歇着吧，因为您的工作早有您的质因子代劳了
        if (0 == flag[i]) continue;
        // 从i的17倍开始过滤
        int step = i*2;
        for (j=i*17; j <= n; j+=step)
        {
            flag[j] = 0;
        }
    }
    
    // 统计素数个数
    for (i=2; i<=n; i++)
    {
        if (flag[i]){
            count++;
            printf("%d|", i);
        }
    }
    
    // 因输出费时，且和算法核心相关不大，故略
    // 释放内存，别忘了传说中的内存泄漏
    free(flag);
    
    printf("===count:%d",count);
    printf("===used:%f",(float)(clock()-bt)/CLOCKS_PER_SEC);
    
    return count;
}



//冒泡排序
void sortBubble(vector<int> &arr)
{
    for (int i = 0; i<arr.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j<arr.size()-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                flag = true;
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        if (!flag)
        {
            //如果有一趟发现无需调换了，则不需要接下来的对比了
            //flag 起作用了，提前结束;
            break;
        }
    }
}

//二分查找
int binary_search(vector<int> &arr,int key)
{
    int left = 0;
    int right = arr.size()-1;
    while (left<=right)
    {
        int mid = (left+right)/2;
        if (key==arr[mid])
        {
            return mid;
        }
        if (key>=arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

void myLog(ostream &os = cout)
{
    os<<"my log..."<<endl;
}

template <class T>
void sortRandom(vector<T> &vec)
{
    srand((unsigned int)time(NULL));
    size_t size = vec.size();
    for (int i = 0; i<size; i++)
    {
        int r = rand() % size;
        swap(vec[i], vec[r]);
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, algorithm!\n";
    
    CCSVParse *parse = new CCSVParse();
    vector<vector<string>> s;
//    s = parse->parseCsvFile("/Users/xujw/xujwWork/CPPAlgorithm/CPPAlgorithm/test.csv",",");
//    parse->printParseData();
////
//    s = parse->parseCsvFile("/Users/xujw/xujwWork/CPPAlgorithm/CPPAlgorithm/test2.csv");
//    parse->printParseData();

    s = parse->parseCsvFile("/Users/xujw/xujwWork/CPPAlgorithm/CPPAlgorithm/machine.csv");
    parse->printParseData();
    
    std::map<std::string, std::map<std::string, std::string> > mapData = parse->parseCsvFileToMap("/Users/xujw/xujwWork/CPPAlgorithm/CPPAlgorithm/machine.csv");
    
    std::map<std::string, std::string> mapRow = mapData.at("21");
    std::string FID = mapRow.at("FID");
    std::string BelongedFarmMapType = mapRow.at("BelongedFarmMapType");
    std::string Name = mapRow.at("Name");
    std::string Type = mapRow.at("Type");
    std::string UnlockLevel = mapRow.at("UnlockLevel");
    std::string BuildCoins = mapRow.at("BuildCoins");
    std::string BuildTime = mapRow.at("BuildTime");
    std::string Remote = mapRow.at("Remote");
    std::string PayoutType = mapRow.at("PayoutType");
    std::string GenProduct = mapRow.at("GenProduct");
    std::string RemoteFileID = mapRow.at("RemoteFileID");
    std::string RewardType = mapRow.at("RewardType");
    
    cout<<FID<<endl;
    cout<<BelongedFarmMapType<<endl;
    cout<<Name<<endl;
    cout<<Type<<endl;
    cout<<UnlockLevel<<endl;
    cout<<BuildCoins<<endl;
    cout<<BuildTime<<endl;
    cout<<Remote<<endl;
    cout<<PayoutType<<endl;
    cout<<GenProduct<<endl;
    cout<<RemoteFileID<<endl;
    cout<<RewardType<<endl;

    
    delete parse;
    
    cout<<"------"<<endl;
    float xxx = 19890803.1;
    std::string sss = conToString(xxx);
    cout<<sss<<endl;;
    
    
    return 0;
    int numx = 0;
    while(1)
    {
        numx++;
        if (numx%2 == 1 &&
            numx%3 == 0 &&
            numx%4 == 1 &&
            numx%5 == 4 &&
            numx%6 == 3 &&
            numx%7 == 5 &&
            numx%8 == 1 &&
            numx%9 == 0)
        {
            //369
            printf("@@@@ x=%d @@@@ \n",numx);
            break;
        }
    }
    
    findZhishu();
    Sieve();
    
    vector<int> vecSort = {1,2,3,4,5};
    sortRandom(vecSort);
    for (int x : vecSort)
    {
        cout<<x<<endl;
    }
    
    string str = "abc,,dd,dd,www;eee;e;ee#ff;ee;";
    vector<string> vec = split(str, ",;#");
    for(string s : vec)
    {
        cout<<s<<endl;
    }
    
    cout<<"\n"<<endl;
    str = "ab,cd,ef,dsd,fe,w,3,444,,23,334,";
    vector<string> vecStl = splitWithStl(str, ",");
    for(string s : vecStl)
    {
        cout<<s<<endl;
    }
    
    
    
    vector<int> tmpArr{10,7,6,12,20,17};
    
    cout<<"--------pre--------"<<endl;
    printArray(tmpArr);
    cout<<"--------after------"<<endl;
    sortByinsert(tmpArr);
    printArray(tmpArr);
    
    int arr[]={2,4,12,13,5,21};
    cout<<"--------pre---------"<<endl;
    printArray(6, arr);
    sortByInsert2(6, arr);
    cout<<"--------after-------"<<endl;
    printArray(6, arr);
    
    cout<<"----冒泡-----"<<endl;
    vector<int> tmpArr2{10,7,6,12,20,17};
    cout<<"----pre----"<<endl;
    printArray(tmpArr2);
    sortBubble(tmpArr2);
    cout<<"---after---"<<endl;
    printArray(tmpArr2);
    
    cout<<"---递归求和---"<<endl;
    cout<<recursive_sum(10)<<endl;
    cout<<"---阶乘---"<<endl;
    cout<<factorial(4)<<endl;
    
    cout<<"---二分查找---"<<endl;
    vector<int> arr3{1,2,3,4,5,6};
    int x = binary_search(arr3,3);
    cout<<"x="<<x<<endl;
    
    
#pragma mark--检测某个类型的最大最小值
    int xm = numeric_limits<int>::max();
    int xs = numeric_limits<int>::min();
    cout<<"int 最大："<<xm<<"\t"<<"int 最小："<<xs<<endl;
    
    double dxm = numeric_limits<double>::max();
    double dxs = numeric_limits<double>::min();
    cout<<"double 最大："<<dxm<<"\t"<<"double 最小："<<dxs<<endl;
    
    myLog();
    ofstream of("/Users/xujw/Desktop/log.txt",ios::app);
    myLog(of);
    
    
    return 0;
}
