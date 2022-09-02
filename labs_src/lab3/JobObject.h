#ifndef ICT_HOMEWORK_3_JOBOBJECT_H
#define ICT_HOMEWORK_3_JOBOBJECT_H

#include <string>

// файлы для бекапа
class JobObject {
public:
    JobObject(std::string name) : _name(name) {}

    std::string get_name() const {
        return _name;
    }

    bool operator==(const JobObject& rhs) {
        return _name == rhs._name;
    }
private:
    std::string _name;
};


#endif //ICT_HOMEWORK_3_JOBOBJECT_H
