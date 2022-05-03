#include "../forras/std_lib_facilities.h"

template<typename C>
void print(const C& c, char sep = '\n'){
	cout << "Container elements: " << endl;
	for (const auto elem: c)
	{
		cout << elem << sep;
	}
	cout << endl;
}

//f5
template<typename C>
double sum(const C& c){
	double s;
	for(const auto elem: c){
		s += elem;
	}
	return s;
}

int main(){

	//f1
	const string iname {"file.txt"};
	ifstream ifs {iname};
	if(!ifs) {
        throw runtime_error("Could not read file: "+iname);
    }
	vector<double> vd;
	for (double d; ifs >> d;)
	{
		vd.push_back(d);
	}

	//f2
	print(vd);

	//f3
	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());

	//f4
	for (int i = 0; i < vd.size(); ++i)
	{
		cout << vd[i] << '\t' << vi[i] << endl;
	}
	cout << endl;

	//f5
	cout << "Sum of vd: " << sum(vd);
	cout << endl;

	//f6
	cout << "Difference between the sum of vd and vi: " << sum(vd) - sum(vi);
	cout << endl;

	//f7
	reverse(vd.begin(), vd.end());
	print(vd);

	//f8
	double vd_mean = sum(vd)/vd.size();
	cout << "Mean value of vd is: " << vd_mean << endl;

	//f9
	vector<double> vd2;
	for(auto i: vd){
		if (i < vd_mean)
		{
			vd2.push_back(i);
		}
	}
	print(vd2);

	//f10
	sort(vd.begin(),vd.end());
	print(vd);
}