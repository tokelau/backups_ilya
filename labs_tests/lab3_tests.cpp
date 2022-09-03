#include <gtest/gtest.h>

#include "lab3/Repository.h"
#include "lab3/BackupJob.h"
#include <filesystem>

using namespace std;

TEST(BackupJob, TEST1) {
//    Cоздаю бекапную джобу. Указываю Split storages
    std::filesystem::path cwd = std::filesystem::current_path();
    std::string path = cwd.string();
    Repository repository(path, "split");
    BackupJob backupJob(repository);
//    Добавляю в джобу два файла
    JobObject FileA("File_A.txt"), FileB("File_B.txt");
    backupJob.add(FileA);
    backupJob.add(FileB);
//    Запускаю создание точки
    RestorePoint restorePoint_1 = backupJob.create_point();
//    Удаляю один из файлов
    backupJob.remove(FileA);
//    Запускаю создание
    RestorePoint restorePoint_2 = backupJob.create_point();
//    Проверяю, что создано две точки и один файл для бекапа
    ASSERT_TRUE(backupJob.size_points() == 2);
    ASSERT_TRUE(backupJob.size_files() == 1);
}

TEST(BackupJob, TEST2) {
//    Cоздаю бекапную джобу, указываю путь директории для хранения бекапов.  Указываю Single storage
    std::filesystem::path cwd = std::filesystem::current_path();
    std::string path = cwd.string();
    Repository repository(path, "split");
    BackupJob backupJob(repository);
//    Добавляю в джобу два файла
    JobObject FileA("File_A.txt"), FileB("File_B.txt");
    backupJob.add(FileA);
    backupJob.add(FileB);
//    Запускаю создание точки
    RestorePoint restorePoint_1 = backupJob.create_point();
//    Проверяю, что созданы директории и файлы
    ASSERT_TRUE(std::filesystem::is_directory(path+"/backup"));
    ifstream f1;
    f1.open(path+"/backup/File_A.txt_1.zip");
    ASSERT_TRUE(f1.is_open());
    ifstream f2;
    f2.open(path+"/backup/File_B.txt_1.zip");
    ASSERT_TRUE(f2.is_open());
}
