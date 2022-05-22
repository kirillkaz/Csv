#ifndef CSV_CSV_H
#define CSV_CSV_H

#include <vector>
#include <string>
#include <fstream>

using vector2str = std::vector<std::vector<std::string>>;

class Csv {
public:
    vector2str CsvArray;

    void parsing(std::string filename);

};


#endif //CSV_CSV_H
