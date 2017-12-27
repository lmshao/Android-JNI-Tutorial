//
// Created by shao.liming on 8/28/2017.
//

#include "CppSource.h"

jstring jni_getStringFromJava(JNIEnv *env, jobject)
{
    jclass clazz = env->FindClass("com/example/jni_all/JavaSource");
    jmethodID methodID = env->GetStaticMethodID(clazz, "getStr", "()Ljava/lang/String;");
    jstring str = (jstring)env->CallStaticObjectMethod(clazz, methodID);

    const char *output = env->GetStringUTFChars(str, NULL);
    std::string tmp = output;
    env->ReleaseStringUTFChars(str, output);

    std::string hello = tmp + " via C++";

    return env->NewStringUTF(hello.c_str());;
}
