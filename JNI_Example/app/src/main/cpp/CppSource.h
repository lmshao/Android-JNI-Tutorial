//
// Created by shao.liming on 3/31/2018.
//

#ifndef CPPSOURCE_H
#define CPPSOURCE_H

#include <jni.h>

typedef struct{
    char name[10];
    int age;
    bool isBoy;

}Student;

jobject jniGetStudentInfo(JNIEnv *env, jobject object);

#endif //CPPSOURCE_H
