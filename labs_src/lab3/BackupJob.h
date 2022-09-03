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

using namespace std;

class BackupJob {
public:
    BackupJob(const Repository& r) : _rep(r) {}

    void add(const JobObject& object);

    void remove(const JobObject& object);

    RestorePoint create_point();

    size_t size_points() const {
        return _restore_points.size();
    }

    size_t size_files() const {
        return _job_objects.size();
    }

private:
    vector<JobObject> _job_objects;
    vector<RestorePoint> _restore_points;
    Repository _rep;
};

#endif //ICT_HOMEWORK_3_BACKUPJOB_H
