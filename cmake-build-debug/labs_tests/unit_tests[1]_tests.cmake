add_test( BackupJob.EasyBackupJob /Users/anastasialobkina/Desktop/KirillovaVika-homework-3-main/cmake-build-debug/bin/unit_tests [==[--gtest_filter=BackupJob.EasyBackupJob]==] --gtest_also_run_disabled_tests)
set_tests_properties( BackupJob.EasyBackupJob PROPERTIES WORKING_DIRECTORY /Users/anastasialobkina/Desktop/KirillovaVika-homework-3-main/cmake-build-debug/labs_tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==] LABELS unit)
add_test( CreateBackups.TwoRestorePointsAndThreeStoragesCreated /Users/anastasialobkina/Desktop/KirillovaVika-homework-3-main/cmake-build-debug/bin/unit_tests [==[--gtest_filter=CreateBackups.TwoRestorePointsAndThreeStoragesCreated]==] --gtest_also_run_disabled_tests)
set_tests_properties( CreateBackups.TwoRestorePointsAndThreeStoragesCreated PROPERTIES WORKING_DIRECTORY /Users/anastasialobkina/Desktop/KirillovaVika-homework-3-main/cmake-build-debug/labs_tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==] LABELS unit)
set( unit_tests_TESTS BackupJob.EasyBackupJob CreateBackups.TwoRestorePointsAndThreeStoragesCreated)