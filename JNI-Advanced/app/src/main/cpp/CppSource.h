//
// Created by shao.liming on 8/28/2017.
//

#ifndef JNI_ADVANCED_CPPSOURCE_H
#define JNI_ADVANCED_CPPSOURCE_H
#include <jni.h>
#include <string>

jstring jni_getStringFromJava(JNIEnv *env, jobject);

jstring jni_testInterfaceFunction(JNIEnv *env, jobject);

#endif //JNI_ADVANCED_CPPSOURCE_H
