//
// Created by shao.liming on 3/31/2018.
//

#include "CppSource.h"

// method: Student nGetStudentInfo();
// signature: ()Lcom/lmshao/jniexample/Student;
jobject jniGetStudentInfo(JNIEnv *env, jobject object){
    jobject studentObject = NULL;
    jclass studentClass = env->FindClass("com/lmshao/jniexample/Student");

    // Get all members fieldID
    jfieldID nameField  = env->GetFieldID(studentClass, "mName", "Ljava/lang/String;");
    jfieldID idField    = env->GetFieldID(studentClass, "mId", "Ljava/util/UUID;");
    jfieldID boyField   = env->GetFieldID(studentClass, "mIsBoy", "Z");
    jfieldID ageField   = env->GetFieldID(studentClass, "mAge", "I");
    jfieldID scoreField = env->GetFieldID(studentClass, "mScore", "Lcom/lmshao/jniexample/CourseScore;");

    // Alloc Student Object
//    jmethodID constructorMethod = env->GetMethodID(studentClass, "<init>", "()V");
//    studentObject = env->NewObject(studentClass, constructorMethod);
    studentObject = env->AllocObject(studentClass);

    // Set name of Student
    jstring nameJS = env->NewStringUTF("XiaoMing");
    env->SetObjectField(studentObject, nameField, nameJS);

    // Set id of Student
    jclass uuidClass = env->FindClass("java/util/UUID");
    jmethodID randomMethod = env->GetStaticMethodID(uuidClass, "randomUUID", "()Ljava/util/UUID;");
    jobject uuidObject = env->CallStaticObjectMethod(uuidClass, randomMethod);
    env->SetObjectField(studentObject, idField, uuidObject);

    // Set isBoy of Student
    env->SetBooleanField(studentObject, boyField, JNI_TRUE);

    // Set age of Student
    env->SetIntField(studentObject, ageField, (jint)27);

    // Set score of Student
    // Alloc CourseScore
    jclass courseScoreClass = env->FindClass("com/lmshao/jniexample/CourseScore");
    jfieldID chineseField = env->GetFieldID(courseScoreClass, "mChinese", "I");
    jfieldID mathField    = env->GetFieldID(courseScoreClass, "mMath", "I");
    jfieldID musicField   = env->GetFieldID(courseScoreClass, "mMusic", "Lcom/lmshao/jniexample/CourseScore$ScoreLevel;");

    jobject courseScoreObject = env->AllocObject(courseScoreClass);
    env->SetIntField(courseScoreObject, chineseField, (jint)90);
    env->SetIntField(courseScoreObject, mathField, (jint)96);

    // Alloc ScoreLevel
    jclass scoreLevelClass = env->FindClass("com/lmshao/jniexample/CourseScore$ScoreLevel");
    jmethodID fromMethod = env->GetStaticMethodID(scoreLevelClass, "fromValue", "(I)Lcom/lmshao/jniexample/CourseScore$ScoreLevel;");
    jobject scoreLevelObject = env->CallStaticObjectMethod(scoreLevelClass, fromMethod, (jint)2);

    env->SetObjectField(courseScoreObject, musicField, scoreLevelObject);
    env->SetObjectField(studentObject, scoreField, courseScoreObject);

    return studentObject;
}