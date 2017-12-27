//
//  Copyright (c) 2017 Liming Shao <lmshao@163.com>
//

#include "CppSource.h"
#include <android/log.h>

jstring jni_getStringJNI(JNIEnv *env, jobject)
{
    std::string hello = "Hello from C++ via the JNI_OnLoad way";
    return env->NewStringUTF(hello.c_str());;
}

jint jni_getSumJNI(JNIEnv *env, jobject, jint x, jint y) {
    return x+y;
}

void jni_putCharArrayJNI(JNIEnv *env, jobject, jcharArray arr) {
    jchar *out = env->GetCharArrayElements(arr, NULL);
    int len = (int) env->GetArrayLength(arr);
    __android_log_print(ANDROID_LOG_DEBUG, "CppSource", "Get a Java char array, length = %d", len);
    for (int i = 0; i < len; ++i) {
        __android_log_print(ANDROID_LOG_DEBUG, "CppSource", "%d : %c", i, out[i]);
    }
}


