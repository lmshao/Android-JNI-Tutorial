//
//  Copyright (c) 2017 Liming Shao <lmshao@163.com>
//

#include <jni.h>
#include <string>
#include "CppSource.h"

extern "C" {

// 1st method to call C from Java
JNIEXPORT jstring JNICALL
Java_com_example_jni_1java2c_MainActivity_stringFromJNI(JNIEnv *env, jobject)
{
    std::string hello = "Hello from C++ via the default way";
    return env->NewStringUTF(hello.c_str());;
}



static JNINativeMethod method[] = {
        {"getStringFromJNI", "()Ljava/lang/String;", (void *) jni_getStringJNI},
        {"getSumFromJNI", "(II)I", (void *) jni_getSumJNI},
        {"putCharArrayToJNI", "([C)V", (void *) jni_putCharArrayJNI}
};

// 2nd method to call C from Java
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    jint result = -1;

    // get env
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return result;
    }

    jclass clazz = env->FindClass("com/example/jni_java2c/MainActivity");
    jint count = sizeof(method) / sizeof(method[0]);
    if (env->RegisterNatives(clazz, method, count) != JNI_OK) {
        return result;
    }
    result = JNI_VERSION_1_6;
    return result;
}

}