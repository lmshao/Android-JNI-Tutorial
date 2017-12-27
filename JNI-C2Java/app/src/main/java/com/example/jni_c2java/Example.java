package com.example.jni_c2java;

//
//  Copyright (c) 2017 Liming Shao <lmshao@163.com>
//

public class Example {
    public static int getSum(int a, int b) {
        return a + b;
    }

    public static String getStr(){
        String str = "Hello from JAVA Example class";
        return str;
    }

    public String printMsg(String str){
        String ret = str + " from JAVA";
        return ret;
    }
}
