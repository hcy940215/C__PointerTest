#include <iostream>
#include <cstring>

void pointerTest();//函数声明

void swap1(int *p1, int *p2);//声明

void swap3(int *a, int *b);

void swapTest();

void arrTest();

void pointerFun();

void backPointerFun();

void pointerArr();

void structTest();

void newDelectTest();

struct Student {
    char name[10];
    float score;
};
using namespace std;

typedef int a;

int main() {
    //pointerTest();
    //swapTest();
    //arrTest();
    //pointerFun();
    //backPointerFun();
    //pointerArr();
    //structTest();
    
    newDelectTest();

//    int a = 2;
//    int &b = a;
//    cout << &b;
    return 0;
}
void newDelectTest() {
    Student *p;
    p = new Student;
    //p->name = "hahahhhhh";
    p->score = 8.0;
    cout<<p->name <<p->score<<endl;
    delete p;

}
/**
 * 结构体练习
 */
void structTest() {
    void printStruct(Student &);
    Student s2 = {"haha", 89.0};
    printStruct(s2);

}

void printStruct(Student &s1) {
    cout << s1.name << " 分数" << s1.score << endl;
}

void pointerArr() {
    void sort(char *name[], int);
    void print(char *name[], int n);
    char *name[] = {const_cast<char *>("C++"), const_cast<char *>("BASIC"), const_cast<char *>("C"),
                    const_cast<char *>("JAVA")};
    int n = 4;
    sort(name, n);
    print(name, n);
}

void sort(char *name[], int n) {
    char *temp;
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(name[k], name[j]) > 0) {
                k = j;
            }
            if (k != i) {
                temp = name[i];
                name[i] = name[k];
                name[k] = temp;
            }
        }
    }
}

void print(char *name[], int n) {
    for (int i = 0; i < n; i++) {
        cout << name[i] << endl;
    }
}

/**
 * 返回指针的指针函数
 */
void backPointerFun() {
    int *add(int, int);
    int *p;
    p = add(3, 4);

    cout << *p;
}

int *add(int x, int y) {
    int *p, z;
    z = x + y;
    p = &z;
    return p;
}

/**
 * 指向指针的函数
 */
void pointerFun() {
    int a, b, m;
    int max(int, int);
    //指向函数的指针
    int (*p)(int, int);
    p = reinterpret_cast<int (*)(int, int)>(max);
    m = max(4, 5);
    cout << m;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void arrTest() {
    int arr[5];
    int *p = arr;
    for (int i = 0; i < 5; ++i) {
        //指针法
        cin >> *(arr + i);
    }
    cout << endl;

    for (int i = 0; i < 5; ++i) {
        //下标法
        cout << arr[i];
    }
    cout << endl;
}

/**
 * 指针变量做形参
 */
void swapTest() {
    int *p1, *p2, a, b;
    cin >> a >> b;
    p1 = &a;
    p2 = &b;
    cout << "调用前 a = " << a << " b = " << b << endl;
    cout << "调用前 max = " << *p1 << " min =" << *p2 << endl;
    if (a < b) {

        swap(a, b);
    }
    cout << "调用后 a = " << a << " b = " << b << endl;
    cout << "调用后 max = " << *p1 << " min =" << *p2 << endl;
}

void swap3(int *a, int *b) {
    int *temp;
    temp = a;
    a = b;
    b = temp;
    cout << "正在调用。。。a = " << *a << " b =" << *b << endl;
}

void swap(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap1(int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/**
 * 指针与变量练习
 */
void pointerTest() {
    int *p1, *p2, *p, a, b;

    cin >> a >> b;
    p1 = &a;
    p2 = &b;
    if (a < b) {
        p = p1;
        p1 = p2;
        p2 = p;
    }

    cout << "a=" << a << " b=" << b << endl;
    cout << "max=" << *p1 << " min=" << *p2 << endl;
}