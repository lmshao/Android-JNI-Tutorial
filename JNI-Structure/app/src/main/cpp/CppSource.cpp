//
// Created by shao.liming on 12/27/2017.
//

#include "CppSource.h"
#include <stdlib.h>
#include <string.h>
#include <string>

jobject
jni_fillUserInfo(JNIEnv *env, jobject, jbyteArray id, jstring name, jint age, jboolean isBoy) {

    jclass clazzInfo = env->FindClass("com/example/jni_structure/MainActivity$UserInfo");

    jfieldID idField = env->GetFieldID(clazzInfo, "ID", "[B");
    jfieldID nameField = env->GetFieldID(clazzInfo, "name", "Ljava/lang/String;");
    jfieldID ageField = env->GetFieldID(clazzInfo, "age", "I");
    jfieldID boyField = env->GetFieldID(clazzInfo, "isBoy", "Z");
    jfieldID commField = env->GetFieldID(clazzInfo, "comments", "Ljava/lang/String;");

    jobject objectInfo = env->AllocObject(clazzInfo);

    env->SetObjectField(objectInfo, idField, id);
    env->SetObjectField(objectInfo, nameField, name);
    env->SetIntField(objectInfo, ageField, age);
    env->SetBooleanField(objectInfo, boyField, isBoy);

    std::string comments = "Hello World";

    env->SetObjectField(objectInfo, commField, env->NewStringUTF(comments.c_str()));

    return objectInfo;
}

jstring jni_getUserProfile(JNIEnv *env, jobject, jobject obj) {

    jclass clazzInfo = env->GetObjectClass(obj);

    jfieldID idField = env->GetFieldID(clazzInfo, "ID", "[B");
    jfieldID nameField = env->GetFieldID(clazzInfo, "name", "Ljava/lang/String;");
    jfieldID ageField = env->GetFieldID(clazzInfo, "age", "I");
    jfieldID boyField = env->GetFieldID(clazzInfo, "isBoy", "Z");
    jfieldID commField = env->GetFieldID(clazzInfo, "comments", "Ljava/lang/String;");

    // jbyteArray -> char array
    jbyteArray id = (jbyteArray) env->GetObjectField(obj, idField);
    jbyte *idByte = env->GetByteArrayElements(id, NULL);
    jsize idLen = env->GetArrayLength(id);

    char *idBuff = (char*)malloc((size_t) (idLen + 1));
    memcpy(idBuff, (const char *) idByte, idLen);
    idBuff[idLen] = '\0';

    std::string idStr(idBuff, (unsigned long) idLen);
    free(idBuff);

    //jstring -> string
    jstring name = (jstring) env->GetObjectField(obj, nameField);
    const char *nameChar = env->GetStringUTFChars(name, NULL);
    std::string nameStr = nameChar;
    env->ReleaseStringChars(name, (const jchar *) nameChar);

    // jint -> int
    int age = (int) env->GetIntField(obj, ageField);
    char ageStr[3] = {0};
    sprintf(ageStr,"%d",age);

    // jboolean -> bool
    bool boy = (bool) env->GetBooleanField(obj, boyField);

//    commStr =
    jstring comm = (jstring) env->GetObjectField(obj, commField);
    const char *commChar = env->GetStringUTFChars(comm, NULL);
    std::string commStr = commChar;
    env->ReleaseStringChars(comm, (const jchar *) commChar);


    std::string retStr = "Hello, ";
    retStr += "My name is " + nameStr;
    retStr += ", and my id is " + idStr;
    retStr += ".\nI am a " + std::string(boy?"boy":"girl");
    retStr += ", and I am " + std::string(ageStr) + " years old.\n";
    retStr += "Comments: " + commStr;

    return env->NewStringUTF(retStr.c_str());
}
