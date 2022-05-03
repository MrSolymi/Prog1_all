#include "../forras/std_lib_facilities.h"

//f3
template<typename T, typename U>
void print(map<T,U>& m){
	for (const auto& i : m)
	{
		cout << i.first << '\t' << i.second << endl;
	}
}

//f5
template<typename T, typename U>
void read(map<T,U>& m, int l){
	string k;
    int v;  
    for (int i = 0; i < l; i++){

        cin >> k >> v;
        m.insert(make_pair(k, v));
    }
}

//f8
template<typename T, typename U>
int sum(map<T,U>& m){
	int s = 0;
	for (const auto& i : m)
	{
		s+=i.second;
	}
	return s;
}

int main(){

	//f1
	map<string,int> msi;

	//f2
	msi["Robert"] = 4;
	msi["Margret"] = 34;
	msi["Irene"] = 6;
	msi["Gregory"] = 38;
	msi["Lyle"] = 64;
	msi["Anne"] = 62;
	msi["Barbara"] = 33;
	msi["Young"] = 24;
	msi["Turk"] = 13;
	msi["Chloe"] = 9;

	//f3
	print(msi);
	cout << endl;

	//f4
	msi.erase(msi.begin(), msi.end());

	//f6
	cout << "Add 10 pair of key and value." << endl;
	read(msi, 10);
	cout << endl;

	//f7
	print(msi);
	cout << endl;

	//f8
	cout << "The sum of the msi values: " << sum(msi) << endl;
	cout << endl;

	//f9
	map<int,string> mis;

	//f10
	for (const auto& a : msi)
	{
	   	mis[a.second] = a.first;
	}

	//f11
	print(mis);

    return 0;
}