#ifndef ICT_HOMEWORK_3_BACKUPJOB_H
#define ICT_HOMEWORK_3_BACKUPJOB_H

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <stdexcept>
#include "RestorePoint.h"
#include "JobObject.h"
#include "Storage.h"
#include "Repository.h"
#include <algorithm>

//using namespace std;

class BackupJob {
public:
    BackupJob(const string& backup_path = "/", const string& storage_type = "split");

    void add_object(const JobObject& object);

    void remove_object(const JobObject& object);

    RestorePoint run();

private:
    string _storage_type;
    vector<JobObject> _job_objects;
    vector<RestorePoint> _restore_points;
    Repository rep;
};

#endif //ICT_HOMEWORK_3_BACKUPJOB_H
