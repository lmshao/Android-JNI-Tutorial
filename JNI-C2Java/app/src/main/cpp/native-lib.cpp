//
//  Copyright (c) 2017 Liming Shao <lmshao@163.com>
//

#include <jni.h>
#include <string>

extern "C" {

// C call JAVA class static method
JNIEXPORT jstring JNICALL
Java_com_example_jni_1c2java_MainActivity_getStrFromJNI(
        JNIEnv *env, jobject) {
    jclass clazz = env->FindClass("com/example/jni_c2java/Example");
    jmethodID methodID = env->GetStaticMethodID(clazz, "getStr", "()Ljava/lang/String;");
    jstring str = (jstring)env->CallStaticObjectMethod(clazz, methodID);
    return str;
}

// C call JAVA class static method
JNIEXPORT jint JNICALL
Java_com_example_jni_1c2java_MainActivity_getSumFromJNI(
        JNIEnv *env, jobject, jint x, jint y) {
    jclass clazz = env->FindClass("com/example/jni_c2java/Example");
    jmethodID methodID = env->GetStaticMethodID(clazz, "getSum", "(II)I");
    jint sum = env->CallStaticIntMethod(clazz, methodID, x, y);
    return sum;
}

// C call JAVA class non-static method
void getStrFromJava(JNIEnv *env, char *in, char *out){
    jclass clazz = env->FindClass("com/example/jni_c2java/Example");
    jmethodID methodID = env->GetMethodID(clazz, "printMsg", "(Ljava/lang/String;)Ljava/lang/String;");
    // get object for non-static method
    jobject object = env->NewObject(clazz, methodID);
    // char* -> jstring
    jstring input = env->NewStringUTF(in);
    jstring str = (jstring)env->CallObjectMethod(object, methodID, input);

    // jstring -> char*
    const char *output = env->GetStringUTFChars(str, NULL);
    strcpy(out, (char *)output);
    env->ReleaseStringUTFChars(str, output);
}

// C call JAVA class non-static method
// learn
JNIEXPORT jstring JNICALL
Java_com_example_jni_1c2java_MainActivity_printMsgFromJNI(
        JNIEnv *env, jobject instance) {
    char *in = (char *) "C++ msg";
    char out[30] = {0};
    getStrFromJava(env, in, out);
    return env->NewStringUTF(out);
}

}