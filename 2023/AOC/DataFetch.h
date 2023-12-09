#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
using namespace std;
using namespace filesystem;

namespace DataFetch {

    static string readFileToString(int dayNr)
    {
        stringstream tempstrStream; 
        tempstrStream << dayNr;
        string strDayStream;
        tempstrStream >> strDayStream;

        path currPath = filesystem::current_path(); // Get the parent path of the current working directory
        path parentPath = currPath.parent_path();
        string dataFilePath = parentPath.string() + "\\data\\Day" + strDayStream + ".txt"; // Construct the path to the data file

        ifstream file(dataFilePath);

        if (!file.is_open()) {
            cerr << "Error opening file: " << dataFilePath << std::endl;
            return ""; // Return an empty string if the file cannot be opened
        }

        stringstream buffer;
        buffer << file.rdbuf(); // Read the entire file into the buffer

        return buffer.str(); // Return the content of the buffer as a string
    }
}