#include <jni.h>
#include <string>

#include "CppSource.h"

#ifdef __cplusplus
extern "C" {
#endif

static const JNINativeMethod gMethods[] = {
        {"nGetStudentInfo", "()Lcom/lmshao/jniexample/Student;", (void *) jniGetStudentInfo}
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {

    JNIEnv *env = NULL;
    jint result = -1;

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return result;
    }

    jclass clazz = env->FindClass("com/lmshao/jniexample/JniManager");
    if (clazz == NULL) {
        return result;
    }

    jint count = sizeof(gMethods) / sizeof(gMethods[0]);

    if (env->RegisterNatives(clazz, gMethods, count) != JNI_OK) {
        return result;
    }

    result = JNI_VERSION_1_6;

    return result;
}

#ifdef __cplusplus
}
#endif


