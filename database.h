//
// database.h
// This header file is part of the ComRecord application.
// It contains functions which work with files.
//
// Author: Tudor - Calin Radoni
// Version: 1.0
// Copyright (C) 2020 Tudor - Calin Radoni
//

#ifndef database_h
#define database_h

#include "recordlist.h"

#define MAX_FILENAME_LENGTH 20
#define MAX_LINE_LENGTH 80

bool lineToPerson(void);
bool readDatabase(char *filename);
bool stdinToPerson(void);
bool personToLine(Person *ps);
bool saveDatabase(char *filename);

#endif /* database_h */
