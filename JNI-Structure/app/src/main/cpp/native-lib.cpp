#include <jni.h>
#include <string>
#include "CppSource.h"

#ifdef __cplusplus
extern "C" {
#endif

// ([BLjava/lang/String;IZ)Lcom/example/jni_structure/MainActivity$UserInfo;

static JNINativeMethod method[] = {
        {"fillUserInfo","([BLjava/lang/String;IZ)Lcom/example/jni_structure/MainActivity$UserInfo;", (void *) jni_fillUserInfo},
        {"getUserProfile","(Lcom/example/jni_structure/MainActivity$UserInfo;)Ljava/lang/String;",   (void *) jni_getUserProfile}
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    jint result = -1;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return result;
    }

    jclass clazz = env->FindClass("com/example/jni_structure/MainActivity");

    jint count = sizeof(method) / sizeof(method[0]);

    if (env->RegisterNatives(clazz, method, count) != JNI_OK) {
        return result;
    }
    result = JNI_VERSION_1_6;
    return result;
}

#ifdef __cplusplus
}
#endif