#include <iostream>
#include <string>
#include <filesystem>

using namespace std;
using std::filesystem::directory_iterator;
namespace fs = std::filesystem;

int main() {
    string path = "";
    cout<<"Podaj scieznke: "; cin>>path;

    for (const auto & file : directory_iterator(path))
        cout << file.path()<<" "<<fs::file_size(file.path()) << endl;

    
}
