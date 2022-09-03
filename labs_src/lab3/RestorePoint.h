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
        _sources_names.push_back(storage.get_source_name());
    }

    std::vector<Storage> get_files() const {
        return _files;
    }

    std::vector<std::string> get_source_files() const {
        return _sources_names;
    }
private:
    int _number; // зачем?
    std::vector<Storage> _files; // список резервных копий объектов
    std::vector<std::string> _sources_names;
};
#endif //ICT_HOMEWORK_3_RESTOREPOINT_H
