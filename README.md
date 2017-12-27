# Android JNI Tutorial
Android JNI tutorial with Android Studio 3.0+ .

## Introduction 
### JNI-Java2C   
Call Native function from Java.   
### JNI-C2Java
Call Java code from Native layer.  
### JNI-All
Include the above two.   
### JNI-Advanced
Uesed to test.   
### JNI-Structure
复杂数据结构在 JAVA & C 之间传递。   
在Java中定义一个用户信息的类UserInfo，JAVA中调用`UserInfo fillUserInfo(byte[] ID, String name, int age, boolean isBoy);`函数把各种用户信息传递给Native层，Native填充并返回一个UserInfo结构。然后JAVA中调用`String getUserProfile(UserInfo userInfo);`函数把这个结构传递给Native层，Native收到后把这些信息组成一段话以字符串形式再返回给JAVA层。   
