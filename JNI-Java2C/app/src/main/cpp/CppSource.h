//
//  Copyright (c) 2017 Liming Shao <lmshao@163.com>
//

#ifndef JNI_JAVA2C_CPPSOURCE_H
#define JNI_JAVA2C_CPPSOURCE_H

#include <jni.h>
#include <string>

jstring jni_getStringJNI(JNIEnv *env, jobject);
jint jni_getSumJNI(JNIEnv *env, jobject, jint x, jint y);
void jni_putCharArrayJNI(JNIEnv *env, jobject, jcharArray arr);

#endif //JNI_JAVA2C_CPPSOURCE_H
