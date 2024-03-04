#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cassert>
#include <cstring>
#include <list>
using namespace std;

int findKey(map<int, int>& Map, int key) {

    // Traverse the map
    for (auto& it : Map) {

        // If mapped value is K,
        // then print the key value
        if (it.second == key) {
            return it.first;
        }
    }

    // If there is not key mapped with K,
    // then print -1
    return -1;
}

int main() {
    map<int, string> boys2012;
    map<int, string> girls2012;
    map<int, string> boys2022;
    map<int, string> girls2022;

    ifstream instream;

    instream.open("C:\\Users\\doggl\\Desktop\\CSC2034-HAllen\\babynames\\babynames2012.txt");
    if (!instream.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        assert(false);
    }

    int number;
    string name1, name2;

    while (instream >> number >> name1 >> name2) {
        boys2012[number] = name1;
        girls2012[number] = name2;
    }
    instream.close();

    instream.open("C:\\Users\\doggl\\Desktop\\CSC2034-HAllen\\babynames\\babynames2022.txt");
    if (!instream.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        assert(false);
    }

    while (instream >> number >> name1 >> name2) {
        boys2022[number] = name1;
        girls2022[number] = name2;
    }
    instream.close();

    // Displaying the contents of map1
    std::cout << "\n2012:\n";
    for (const auto& entry : boys2012) {
        std::cout << entry.first << ": " << entry.second << " / " << girls2012[entry.first] << endl;
    }
    std::cout << "\n2022:\n";
    for (const auto& entry : boys2022) {
        std::cout << entry.first << ": " << entry.second << " / " << girls2022[entry.first] << endl;
    }

    list<string> ls;
    for(const auto& entry : boys2012){
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
    ls.sort();
    ls.unique();
    for(const auto& name : ls){
        cout << name << " ";
    }
    cout << ls.size();
    for(const auto& name : ls){
        cout << name <<
    }


    return 0;
}
