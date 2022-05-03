#include "../forras/std_lib_facilities.h"

//f1
template<typename T>
struct S {
        S (T vv = 0) : val{vv}{};
        //f5
        T& get();
        //f9
        void set(T new_t) {val = new_t;};
        //f10
        void operator=(const T& s){val = s;};
        //f11
        const T& get() const;
    private: //f7
        T val;
};

//f5 & f6
template<typename T>
T& S<T>::get(){
	return val;
}

//f11
template<typename T>
const T& S<T>::get() const{
	return val;
}

//f12
template<typename T>
void read_val(T& v){
	cin >> v;
}

//f14
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	os << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		os << v[i];
		if (i < v.size()-1)
		{
			os << ", ";
		}
	}
	os << "}";
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }
    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }
    return is;
}
int main(){

    //f3
    S<int> s;
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {3.2};
	S<string> ss{"Hello"};
	S<vector<int>> svi {vector<int>{1, 1, 2, 3, 5, 8, 9, 10}};

    //f4
    cout << "S<vector<int>> : ";
	for (auto& a: svi.get())
    {
        cout << a << ' ';
    }
    cout << endl;

    //f8
    sc.set('s');
	cout << "S<char> : " << sc.get() << endl;

    //f10
    sd = 42.1;
	cout << "S<double> : " << sd.get() << endl;

    //f13
    int ii;
	read_val(ii);
	S<int> si2 {ii};

	double dd;
	read_val(dd);
	S<double> sd2 {dd};

	string ss2;
	read_val(ss2);
	S<string> str {ss2};

	cout << "S<int> : " << si2.get() << endl;
	cout << "S<double> : " << sd2.get() << endl;
	cout << "S<string> : " << str.get() << endl;

    //f14
    cout << "Add a vector in this format {val, val, val}: ";
    vector<int> vint;
    read_val(vint);
	S<vector<int>> svi2 {vint};
    cout << "S<vector<int>> : " << svi2.get() << endl;

    return 0;
}