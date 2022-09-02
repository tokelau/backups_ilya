#pragma once

#include <fstream>
#include <filesystem>
#include "lab3/BackupJob.h"
#include "zlib.h"

TEST(BackupJob, EasyBackupJob) {
//1. Cоздаю бекапную джобу. Указываю Split storages
    std::string path = std::filesystem::current_path().string()+"/";
    BackupJob backupJob(path, "single");
//3. Добавляю в джобу два файла
    JobObject FileA("FILE_A"), FileB("FILE_B");
    backupJob.add_object(FileA);
    backupJob.add_object(FileB);
//4. Запускаю создание точки
    RestorePoint restorePoint_1 = backupJob.run();
//5. Проверяю, что созданы директории и файлы
    ASSERT_TRUE(std::filesystem::is_directory(path+"backups"));
    ASSERT_TRUE(std::filesystem::is_directory(path+"backups/backup_1_single"));
    ifstream f;
    f.open(path+"backups/backup_1_single/backup_1_single.zip");
//    ASSERT_TRUE(f.is_open());
}