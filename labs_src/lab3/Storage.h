#ifndef ICT_HOMEWORK_3_STORAGE_H
#define ICT_HOMEWORK_3_STORAGE_H

#include <string>
#include "JobObject.h"

//using namespace std;

// файлы-копии
class Storage {
public:
    Storage(const JobObject& jobObject, const int& storage_number) {
        _name = jobObject.get_name() + "_" + std::to_string(storage_number);
    }

    std::string get_name() const {
        return _name;
    }
private:
    std::string _name;
};
#endif //ICT_HOMEWORK_3_STORAGE_H
