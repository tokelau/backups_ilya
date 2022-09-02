#ifndef ICT_HOMEWORK_3_RESTOREPOINT_H
#define ICT_HOMEWORK_3_RESTOREPOINT_H

#include <iostream>
#include <vector>
#include <string>
#include "Storage.h"

class RestorePoint {
public:
    RestorePoint(const int& number) : _number(number) {}

    void add_storage(const Storage& storage) {
        _files.push_back(storage);
    }

    std::vector<Storage> get_files() const {
        return _files;
    }
private:
    int _number;
    std::vector<Storage> _files; // список резервных копий объектов
};
#endif //ICT_HOMEWORK_3_RESTOREPOINT_H
