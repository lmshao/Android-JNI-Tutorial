//
// Created by shao.liming on 8/28/2017.
//

#include "CppSource.h"
#include <android/log.h>

JNIEnv *gEnv;

jstring jni_getStringFromJava(JNIEnv *env, jobject)
{
    jclass clazz = env->FindClass("com/example/jni_advanced/JavaSource");
    jmethodID methodID = env->GetStaticMethodID(clazz, "getStr", "()Ljava/lang/String;");
    jstring str = (jstring)env->CallStaticObjectMethod(clazz, methodID);

    const char *output = env->GetStringUTFChars(str, NULL);
    std::string tmp = output;
    env->ReleaseStringUTFChars(str, output);

    std::string hello = tmp + " via C++";

    return env->NewStringUTF(hello.c_str());
}


typedef struct callbackStruct{
    int in;
    void (*doSth)(int);
}CallStrcut;

void callOnStatus(int n){
    JNIEnv *env = gEnv;

    jclass clazz = env->FindClass("com/example/jni_advanced/JavaSource");
    jfieldID fieldID = env->GetStaticFieldID(clazz, "mInterClass", "Lcom/example/jni_advanced/JavaSource$InterClass;");

    jobject object = env->GetStaticObjectField(clazz, fieldID);

    // get (interface InterClass) of (class JavaSource)
    jclass clazz2 = env->FindClass("com/example/jni_advanced/JavaSource$InterClass");
    jmethodID methodID = env->GetMethodID(clazz2, "onStatus", "(I)V");

    gEnv->CallVoidMethod(object,methodID, n);
}

void doJavaCallback(CallStrcut *pFun){
    __android_log_print(ANDROID_LOG_DEBUG, "CppSource", "enter doJavaCallback");

    pFun->doSth(100);

    __android_log_print(ANDROID_LOG_DEBUG, "CppSource", "leave doJavaCallback");
}



jstring jni_testInterfaceFunction(JNIEnv *env, jobject) {
    gEnv = env;
    /*
     jclass clazz = env->FindClass("com/example/jni_advanced/JavaSource");
     jfieldID fieldID = env->GetStaticFieldID(clazz, "mInterClass", "Lcom/example/jni_advanced/JavaSource$InterClass;");

     jobject object = env->GetStaticObjectField(clazz, fieldID);

     // get (interface InterClass) of (class JavaSource)
     jclass clazz2 = env->FindClass("com/example/jni_advanced/JavaSource$InterClass");
     jmethodID methodID = env->GetMethodID(clazz2, "onStatus", "(I)V");

     env->CallVoidMethod(object,methodID, 9);
     */

    CallStrcut callStrcut;
    callStrcut.doSth = callOnStatus;

    doJavaCallback(&callStrcut);

    std::string tmp = "Call JavaSource$InterClass onStatus(9)";

    __android_log_print(ANDROID_LOG_DEBUG, "CppSource", "Call JavaSource$InterClass onStatus(9)");

    return env->NewStringUTF(tmp.c_str());
}