#include "Repository.h"

void Repository::save(const RestorePoint& restorePoint, const string& arch_name) {
    // создать папку
    if (mkdir((_path + arch_name).c_str(),0777) == -1)
        std::runtime_error("Folder exists");

    // сохранить бекап
    if (_storage_type == "single") {
        // в один архив
//        ZipArchive zf(_path + arch_name+"/"+arch_name+".zip");
//        zf.open(ZipArchive::Write);
//
//        vector<Storage> files = restorePoint.get_files();
//        for (int i = 0; i < files.size(); i++) {
//            Storage storage = files[i];
//
//            const char *textData = "Hello,World!"; // !
//            zf.addData(storage.get_name(), textData, 12);
//        }
//
//        zf.close();
    } else if (_storage_type == "split") {
        // каждый файл в свой .zip
        vector<Storage> files = restorePoint.get_files();
        for (int i = 0; i < files.size(); i++) {
            Storage storage = files[i];

//            ZipArchive zf(_path + arch_name+"/"+storage.get_name()+".zip");
//            zf.open(ZipArchive::Write);
//            const char* textData = "Hello,World!"; // !
//            zf.addData(storage.get_name(), textData, 12);
//            zf.close();
        }
    }
}