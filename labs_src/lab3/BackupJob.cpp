#include "BackupJob.h"

void BackupJob::add(const JobObject& object) {
    _job_objects.push_back(object);
}

void BackupJob::remove(const JobObject& object) {
    auto found = find(_job_objects.begin(), _job_objects.end(), object);
    if (found != _job_objects.end()) {
        _job_objects.erase(found);
    } else {
        throw runtime_error("Can't remove. Job doesn't exists."); // если нечего удалять, то ошибка
    }
}

RestorePoint BackupJob::create_point() {
    int backup_number = _restore_points.size() + 1;
    RestorePoint restorePoint(backup_number);
    for(int i = 0; i < _job_objects.size(); i++) {
        Storage storage(_job_objects[i], backup_number);
        restorePoint.add_storage(storage);
    }
    _restore_points.push_back(restorePoint);
    _rep.compress(restorePoint);
//    rep.save(restorePoint, "backup_"+ to_string(backup_number)+"_"+_storage_type); // backup_1_split.zip
    return restorePoint;
}
