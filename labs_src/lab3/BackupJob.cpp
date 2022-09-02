#include "BackupJob.h"

BackupJob::BackupJob(const string& backup_path, const string& storage_type) {
    if (storage_type == "split" or storage_type == "single") {
        _storage_type = storage_type;
    } else {
        throw runtime_error("Неподдерживаемый тип хранения");
    }
    rep.set_path(backup_path);
    rep.set_type(_storage_type);
}

void BackupJob::add_object(const JobObject& object) {
    _job_objects.push_back(object);
}

void BackupJob::remove_object(const JobObject& object) {
    auto found = find(_job_objects.begin(), _job_objects.end(), object);
    if (found != _job_objects.end()) {
        _job_objects.erase(found);
    } else {
        throw runtime_error("Невозможно удалить"); // если нечего удалять, то ошибка
    }
}

RestorePoint BackupJob::run() {
    int backup_number = _restore_points.size() + 1;
    RestorePoint restorePoint(backup_number);
    for(int i = 0; i < _job_objects.size(); i++) {
        Storage storage(_job_objects[i], backup_number);
        restorePoint.add_storage(storage);
    }
    _restore_points.push_back(restorePoint);
    rep.save(restorePoint, "backup_"+ std::to_string(backup_number)+"_"+_storage_type); // backup_1_split
    return restorePoint;
}
