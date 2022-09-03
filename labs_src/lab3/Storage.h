#ifndef ICT_HOMEWORK_3_STORAGE_H
#define ICT_HOMEWORK_3_STORAGE_H

#include <string>
#include "JobObject.h"

// файлы-копии
class Storage {
public:
    Storage(JobObject jobObject, int storage_number) {
        _name = jobObject.string() + "_" + std::to_string(storage_number);
        _source_name = jobObject.string();
    }

    std::string get_name() const {
        return _name;
    }

    std::string get_source_name() const {
        return _source_name;
    }
private:
    std::string _name;
    std::string _source_name;
};
#endif //ICT_HOMEWORK_3_STORAGE_H
