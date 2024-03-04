#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cassert>
#include <list>
#include <iomanip>
#include <algorithm>
using namespace std;

string findKey(const map<int, string>& t_map, const string &key) {
    for (auto& it : t_map) {
        if (it.second == key) {
            return to_string(it.first);
        }
    }
    return "N/A";
}

void print_debug_one(const string &name, map<int, string> &map1, map<int, string> &map2, map<int, string> &map3, map<int, string> &map4){
    string brank2012 = findKey(map1, name);
    string grank2012 = findKey(map2, name);
    string brank2022 = findKey(map3, name);
    string grank2022 = findKey(map4, name);

    cout << setw(16) << left << name << setw(16) << left << brank2012
            << setw(16) << left << grank2012
            << setw(16) << left << brank2022
            << setw(16) << left << grank2022
            << endl;

}

[[maybe_unused]] void print_debug_all(list<string> &list, map<int, string> &map1, map<int,string> &map2, map<int, string> &map3, map<int,string> &map4){
    cout << setw(16) << left << "Name"
         << setw(16) << left << "Boys 2012 rank"
         << setw(16) << left << "Girls 2012 rank"
         << setw(16) << left << "Boys 2022 rank"
         << setw(16) << left << "Girls 2022 rank" << endl;
    cout << string(16*4, '-');
    for(const auto& name : list){
        print_debug_one(name, map1, map2, map3, map4);
    }
}

void pretty_print_name(const list<string>& names_list, const string& name, const map<int, string>* ranks_maps){
    if(std::find(names_list.begin(), names_list.end(), name) != names_list.end()){
        string rank = findKey(ranks_maps[0], name);

        string res = findKey(ranks_maps[0], name);
        string rank1 = res != "N/A" ? ("ranked " + res + " in popularity among boys in 2012") : "not ranked among the top 1000 names for boys in 2012.";
        res = findKey(ranks_maps[1], name);
        string rank2 = res != "N/A" ? ("ranked " + res + " in popularity among girls in 2012") : "does not rank among the top 1000 names for girls in 2012.";

        res = findKey(ranks_maps[2], name);
        string rank3 = res != "N/A" ? (res + " in popularity among boys in 2022") : "not ranked among the top 1000 names for boys in 2022.";
        res = findKey(ranks_maps[3], name);
        string rank4 = res != "N/A" ? (res + " in popularity among girls in 2022") : "does not rank among the top 1000 names for girls in 2022.";

        cout << name << " is " << rank1 << " and " << rank3 << endl;
        cout << name << " is " << rank2 << " and " << rank4 << endl;
    }
}

int main() {
    map<int, string> boys2012;
    map<int, string> girls2012;
    map<int, string> boys2022;
    map<int, string> girls2022;


    int number;
    string name1, name2;

    ifstream instream;

    /* Read 2012 names */
    instream.open(".\\babynames2012.txt"); // same dir as .exe
    if (!instream.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        assert(false);
    }

    /* Store 2012 names */
    while (instream >> number >> name1 >> name2) {
        boys2012[number] = name1;
        girls2012[number] = name2;
    }
    instream.close();
    /* Read 2022 names */
    instream.open(".\\babynames2022.txt"); // same dir as .exe
    if (!instream.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        assert(false);
    }
    /* Store 2022 names */
    while (instream >> number >> name1 >> name2) {
        boys2022[number] = name1;
        girls2022[number] = name2;
    }
    instream.close();

    list<string> ls;

    /* add all names to 1 list */
    for(const auto& entry :boys2012){
        ls.push_back(entry.second);
    }
    for(const auto& entry : girls2012){
        ls.push_back(entry.second);
    }
    for(const auto& entry : boys2022){
        ls.push_back(entry.second);
    }
    for(const auto& entry : girls2022){
        ls.push_back(entry.second);
    }
    ls.sort(); // required to deduplicate
    ls.unique(); // deduplicate

    /* i don't want to have to pass 4 maps to functions */
    map<int, string> maps[] = { boys2012, girls2012, boys2022, girls2022};

    string inname;
    cout << "Enter name (capitalize first letter):" << endl;
    cin >> inname;
    pretty_print_name(ls, inname, maps);

    /* write all ranked names to CSV file */
    ofstream outfile;
    outfile.open(".\\compareNames.txt", ios::out);
    if(outfile.is_open()) {
        outfile << "NAME,BOYS 2012 RANK,GIRLS 2012 RANK,BOYS 2022 RANK,GIRLS 2022 RANK" << endl;
        for (const auto &name: ls) {
            outfile << name
                    << "," << findKey(boys2012, name)
                    << "," << findKey(girls2012, name)
                    << "," << findKey(boys2022, name)
                    << "," << findKey(girls2022, name)
                    << endl;
        }
    }
    outfile.close();

    return 0;
}
