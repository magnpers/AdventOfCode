#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

std::string readFileToString(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return ""; // Return an empty string if the file cannot be opened
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); // Read the entire file into the buffer

    return buffer.str(); // Return the content of the buffer as a string
}

std::string getCurrentWorkingDirectory() {
    namespace fs = std::filesystem;

    try {
        // fs::current_path() returns the current working directory as a fs::path object
        fs::path currentPath = fs::current_path();

        // Convert the fs::path object to a string
        return currentPath.string();
    }
    catch (const std::exception& e) {
        std::cerr << "Error getting current working directory: " << e.what() << std::endl;
        return ""; // Return an empty string on error
    }
}

int main() {
    std::string filename = "example.txt"; // Replace with the actual file name
    std::string fileContent = readFileToString(filename);

    if (!fileContent.empty()) {
        std::cout << "File content:\n" << fileContent << std::endl;
    }

    return 0;
}