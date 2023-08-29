//
// test.h
// This header file is part of the ComRecord application.
// It contains functions which are used to test the application.
//
// Author: Tudor - Calin Radoni
// Version: 1.0
// Copyright (C) 2020 Tudor - Calin Radoni
//

#ifndef test_h
#define test_h

#include <stdio.h>
#include <stdbool.h>

#include "database.h"

void test_addRandomRecord(void);
bool test_addRndCntRecords(void);
bool test_delFirstRecord(void);
bool test_delThirdRecord(void);
bool test_saveDatabase(void);
void test_run(void);

void compact_print(Person*);

#endif /* test_h */
