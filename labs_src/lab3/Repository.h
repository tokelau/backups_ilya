#ifndef ICT_HOMEWORK_3_REPOSITORY_H
#define ICT_HOMEWORK_3_REPOSITORY_H

#include <fstream>
#include <string>
#include <sys/stat.h>
#include "RestorePoint.h"
#include "Storage.h"
//#include "../libzippp-master/src/libzippp.h"


using namespace std;
//using namespace libzippp;

class Repository {
public:
    void set_path(const string& backup_path) {
        _path = backup_path + "backups/"; // C/Users/123/backups/
//        cout << (_path) << endl;
        if (mkdir((_path).c_str(), 0777) == -1) {
            throw runtime_error("Folder exists");
        }
    }

    void set_type(const string& storage_type) {
        _storage_type = storage_type;
    }

    void save(const RestorePoint& restorePoint, const string& arch_name);

private:
    string _path;
    string _storage_type;
};


#endif //ICT_HOMEWORK_3_REPOSITORY_H
