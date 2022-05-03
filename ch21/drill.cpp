#include "../forras/std_lib_facilities.h"

//f1
struct Item{
    string name;
    int iid;
    double value;
     
    Item() : name("nothing"), iid(0), value(0) {}
    Item(const string& n, int i = 0, double v = 0.0) : name{ n }, iid{ i }, value{ v }{}
};
//f2
struct sort_by_name {
    bool operator() (const Item& a, const Item& b) const {
        return a.name < b.name;
    }
};
//f3
struct sort_by_id {
    bool operator()(const Item& a, const Item& b) const {
        return a.iid < b.iid;
    }
};
//f4
struct sort_by_value_decreasing {
    bool operator()(const Item& a, const Item& b) const {
        return a.value > b.value;
    }
};
//f6
class find_name{
private:
    string name;
public:
    find_name(const string& nn){name=nn;} //: name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};
//f7
class find_iid{
private:
    int iid;
public:
    find_iid(int id){iid=id;} //: iid{id} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};

template<typename C>
void print(const C& c, char sep = ' ') {
    for (const auto& i : c)
    {
        cout << i.name << sep << i.iid << sep << i.value << endl;
    }
    cout << endl;
}
istream& operator>>(istream& is, Item& it) {
    string n;
    int id;
    double v;
    is >> n >> id >> v;
    Item vii{ n, id, v };
    it = vii;
    return is;
}

int main(){

    //f1
    const string iname{"file.txt"};
    ifstream ifs {iname};
    if (!ifs){
        throw runtime_error("Could not read file: " + iname);
    }
    vector<Item> vi;
    for (Item d; ifs >> d;) {
        vi.push_back(d);
    }

    //f8
    list<Item> li (vi.size());
    copy(vi.begin(), vi.end(), li.begin());

    //f2
    sort(vi.begin(), vi.end(), sort_by_name());
    cout << "Items sorted by name: " << endl;
    print(vi);

    //f3
    sort(vi.begin(), vi.end(), sort_by_id());
    cout << "Items sorted by id: " << endl;
    print(vi);

    //f4
    sort(vi.begin(), vi.end(), sort_by_value_decreasing());
    cout << "Items sorted by value in descending order: " << endl;
    print(vi);

    //f5
    vi.push_back(Item{ "horse shoe", 99, 12.34 });
    vi.push_back(Item{ "Canon S400", 9988, 499.95 });
    cout << "Items: " << endl;
    print(vi);

    //f6
    vi.erase(find_if(vi.begin(), vi.end(), find_name("computer")));
    vi.erase(find_if(vi.begin(), vi.end(), find_name("tv")));
    cout << "Items deleted by name: " << endl;
    print(vi);

    //f7
    vi.erase(find_if(vi.begin(), vi.end(), find_iid(44)));
    vi.erase(find_if(vi.begin(), vi.end(), find_iid(37)));
    cout << "Items deleted by id: " << endl;
    print(vi);

    //f8

    cout << "List items: " << endl;
    print(li);

    li.sort(sort_by_name());
    cout << "List items sorted by name: " << endl;
    print(li);

    li.sort(sort_by_id());
    cout << "List items sorted by id: " << endl;
    print(li);

    li.sort(sort_by_value_decreasing());
    cout << "List items sorted by value descending: " << endl;
    print(li);

    li.push_back(Item{"horse shoe", 99, 12.34});
    li.push_back(Item{"Canon S400", 9988, 499.95});
    cout << "Items: " << endl;
    print(li);

    li.erase(find_if(li.begin(), li.end(), find_name("computer")));
    li.erase(find_if(li.begin(), li.end(), find_name("tv")));
    cout << "Items deleted by name: " << endl;
    print(li);

    li.erase(find_if(li.begin(), li.end(), find_iid(44)));
    li.erase(find_if(li.begin(), li.end(), find_iid(37)));
    cout << "Items deleted by id: " << endl;
    print(li);

    return 0;
}