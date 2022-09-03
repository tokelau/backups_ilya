#ifndef ICT_HOMEWORK_3_REPOSITORY_H
#define ICT_HOMEWORK_3_REPOSITORY_H

#include <fstream>
#include <string>
#include <filesystem>
#include "RestorePoint.h"
#include "zip-master/src/zip.h"

class Repository {
public:
    Repository(const std::string& path, const std::string& storage_type) : _storage_type(storage_type) {
        _path = path;
    }

    void change_type(const std::string& storage_type) {
        _storage_type = storage_type;
    }

    void compress(const RestorePoint& points) {
        std::vector<std::string> files = points.get_source_files();
        std::vector<Storage> entry_names = points.get_files();
        if (_storage_type == "single") {
            // Single storage - все вместе
            struct zip_t *zip = zip_open("backup.zip", ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');
            {
                for (int i = 0; i < files.size(); i++) {
                    zip_entry_open(zip, entry_names[i].get_name().c_str());
                    {
                        // открыть и прочитать файл
                        std::string file_path = _path + "/" + files[i];
                        std::ifstream in(file_path);
                        std::string tp;
                        if (in.is_open()) {
                            while (getline(in, tp)) { //read data from file object and put it into string.
                                std::cout << tp << "\n"; //print the data of the string
                            }
                        } else {
                            std::cout << "Can't find " << files[i] << ". Create empty entry" << std::endl;
                        }
                        in.close(); //close the file object.

                        // записать файл в архив
                        zip_entry_write(zip, tp.c_str(), tp.size());
                    }
                    zip_entry_close(zip);
                }
            }
            zip_close(zip);
        }
        else if (_storage_type == "split") {
            // Split
            // сначала удалить бекап, если он существует
            std::filesystem::remove_all(_path + "/backup");
            // потом создать заново
            std::filesystem::create_directory(_path + "/backup");
            for (int i = 0; i < files.size(); i++) {
                std::string zip_path = _path + "/backup/" + entry_names[i].get_name() + ".zip";
                struct zip_t *zip = zip_open(zip_path.c_str(), ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');
                {
                    zip_entry_open(zip, entry_names[i].get_name().c_str());
                    {
                        // открыть и прочитать файл
                        std::string file_path = _path + "/" + files[i];
                        std::ifstream in(file_path);
                        std::string tp;
                        if (in.is_open()) {
                            while (getline(in, tp)) { //read data from file object and put it into string.
                                std::cout << tp << "\n"; //print the data of the string
                            }
                        }
                        in.close(); //close the file object.

                        // записать файл в архив
                        zip_entry_write(zip, tp.c_str(), tp.size());
                    }
                    zip_entry_close(zip);

                }
                zip_close(zip);
            }
        } else {
            throw std::runtime_error("Unsupported storage type");
        }
    }

private:
    std::string _path;
    std::string _storage_type;
};


#endif //ICT_HOMEWORK_3_REPOSITORY_H
