#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

struct Contact {
    std::string name;
    std::string email;
    std::string number;
};

std::vector<std::pair<std::string, struct Contact>> read_contacts(std::string filename) {

    std::fstream csv_file(filename);
    std::vector<std::pair<std::string, struct Contact>> data;
    std::string column, line;
    std::vector<std::string> row;

    if (csv_file.good()) {
        std::getline(csv_file, line);
        std::stringstream ss(line);

        while (std::getline(ss, column, ',')) {
            // discard column names row
        }
        
    }

    while (std::getline(csv_file, line)) {
        row.clear();
        std::stringstream ss(line);
        int column_index = 0;


        while (std::getline(ss, column, ',')) {
            row.push_back(column);
        }
        struct Contact ct;
        ct.number = row[0];
        ct.name = row[1];
        ct.email = row[2];
        data.push_back({row[0], ct});

    }

    csv_file.close();
    return data;
}