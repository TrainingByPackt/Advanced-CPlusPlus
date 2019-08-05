
int sum(int a, int b) {
    return a + b;
}

int callSum() {
    return sum(4, 5);
}

class MyClass {
private:
    int a = 5;
    int myPrivateFunc(int i) {
        a = 4;
        return i + a;
    }
public:
    int b = 6;
    int myFunc(){ 
        return sum(1, myPrivateFunc(b));
    }
};

MyClass myObject;

int main() {
    myObject.myFunc();
}


