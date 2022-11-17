

#ifndef __TEST_DATA_H
#define __TEST_DATA_H


#define NUM_TESTING_STUDENTS 8



char* TESTING_NAMES[] = {
    "Luke Skywalker",
    "Leia Organa",
    "Rey",
    "Han Solo",
    "Lando Calrissian",
    "Darth Vader",
    "Finn",
    "R2-D2"
};



int TESTING_IDS[] = {
    933111111,
    933222222,
    933333333,
    933444444,
    933555555,
    933666666,
    933777777,
    933888888
};



float TESTING_GPAS[] = {
    3.75,
    4.0,
    3.9,
    2.5,
    3.67,
    1.33,
    3.25,
    3.9
};



struct student 
{
    char* name;
    int id;
    float gpa;
};


int compare_students(void* a, void* b) 
{
    struct student* s_a = a, * s_b = b;
    return s_a->id - s_b->id;
}

#endif
