//
// Created by shao.liming on 8/28/2017.
//

#include "CppSource.h"
#include <android/log.h>

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

jstring jni_testInterfaceFunction(JNIEnv *env, jobject) {
    jclass clazz = env->FindClass("com/example/jni_advanced/JavaSource");
    jfieldID fieldID = env->GetStaticFieldID(clazz, "mInterClass", "Lcom/example/jni_advanced/JavaSource$InterClass;");

    jobject object = env->GetStaticObjectField(clazz, fieldID);

    // get (interface InterClass) of (class JavaSource)
    jclass clazz2 = env->FindClass("com/example/jni_advanced/JavaSource$InterClass");
    jmethodID methodID = env->GetMethodID(clazz2, "onStatus", "(I)V");
    env->CallVoidMethod(object,methodID, 9);

    std::string tmp = "Call JavaSource$InterClass onStatus(9)";

    __android_log_print(ANDROID_LOG_DEBUG, "CppSource", "Call JavaSource$InterClass onStatus(9)");

    return env->NewStringUTF(tmp.c_str());
}
