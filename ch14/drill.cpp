#include "../forras/std_lib_facilities.h"

class B1{
    public:
        virtual void vf(){
            cout << "B1::vf()" << endl;
        }
        void f(){
            cout << "B1::f()" << endl;
        }
        /*f5*/virtual void pvf()=0; //abstract függvény
};
class D1: public B1{
    public:
        virtual void vf(){
            cout << "D1::vf()" << endl;
        }
        void f(){
            cout << "D1::f()" << endl;
        }
};
class D2: public D1{
    public:
        void pvf(){ //a pvf() függvény többé nem abstract , mert megmondtuk neki hogy mit csináljon
            cout<<"D2::pvf()"<<endl;
        }
};
class B2{
    public:
	    virtual void pvf()=0; //tisztán virtuális ami jelzi hogy felül van írva, abstract
};
class D21 : public B2{
	public:
		string s;
		void pvf(){ //felülírja, nem lesz abstract
            cout<<s<<endl;
        }
};
class D22 : public B2{
	public:
		int n;
		void pvf(){ //felülírja, nem lesz abstract
            cout<<n<<endl;
        }
};
void f(B2& b2RefObject) //függvény aminek az argumentuma B2 referencia, referencia miatt meg lehet hívni a D21 és D22 osztályt
{
	b2RefObject.pvf();
}

int main(){

    /*
    //f1
    B1 b1Object;
    b1Object.vf();
    b1Object.f();
    
    //f2
    D1 d1Object;
    d1Object.vf();
    d1Object.f();

    //f3
    B1& b1RefObject = d1Object;
    b1RefObject.vf();
    b1RefObject.f();
    ////a virtual function miatt a függvényünk a referencia miatt a B1-ből fog referálni, de a sima function a D1-ből fog

    //f4
    d1Object.vf();
    d1Object.f();
    //Mostmár a D1-ben levő függvény fut le nem az ami a B1-ben van
    */

    //f6
    D2 d2Object;
    d2Object.f();
    d2Object.vf();
    d2Object.pvf();

    //f7
    D21 d21Object;
    d21Object.s = "D21 string";
    d21Object.pvf();

    D22 d22Object;
    d22Object.n = 22;
    d22Object.pvf();
    
    return 0;
}