#ifndef ICT_HOMEWORK_3_JOBOBJECT_H
#define ICT_HOMEWORK_3_JOBOBJECT_H

#include <string>
#include <fstream>

// файлы для бекапа
class JobObject {
public:
    JobObject(const std::string& name) {
        _name = name;
    }

    std::string string() {
        return _name;
    }

    bool operator==(const JobObject& rhs) {
        return _name == rhs._name;
    }
private:
    std::string _name;
};


#endif //ICT_HOMEWORK_3_JOBOBJECT_H
