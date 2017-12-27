//
// Created by shao.liming on 12/27/2017.
//

#ifndef JNI_STRUCTURE_CPPSOURCE_H
#define JNI_STRUCTURE_CPPSOURCE_H

#include <jni.h>

jobject jni_fillUserInfo(JNIEnv *env, jobject, jbyteArray id, jstring name, jint age, jboolean isBoy);

jstring jni_getUserProfile(JNIEnv *env, jobject, jobject obj);

#endif //JNI_STRUCTURE_CPPSOURCE_H
