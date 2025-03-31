#include <iostream>
#include <memory>
#include <fstream>
#include <string>

class File {
public:
    File(const std::string& filename) {
        file = std::make_unique<std::ofstream>(filename);
        if (!file->is_open()) {
            throw std::runtime_error("Failed to open file");
        }
        std::cout << "File opened: " << filename << std::endl;
    }

    ~File() {
        if (file && file->is_open()) {
            file->close();
            std::cout << "File closed." << std::endl;
        }
    }

    void write(const std::string& data) {
        if (file && file->is_open()) {
            *file << data << std::endl;
        }
        else {
            std::cerr << "File is not open for writing." << std::endl;
        }
    }

private:
    std::unique_ptr<std::ofstream> file;
};

int main() {
    try {
        File fileManager("problem3.txt");

        // запись и чтение
        fileManager.write("Hello, World!");
        fileManager.write("This is a test.");
        std::string filename = "problem3.txt";
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) { //читаем файл построчно
            std::cout << line << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

