package com.example.jni_all;

/**
 * Created by shao.liming on 8/28/2017.
 */

public class JavaSource {
    public static int getSum(int a, int b) {
        return a + b;
    }

    public static String getStr(){
        String str = "Hello from JavaSource class";
        return str;
    }

    public String printMsg(String str){
        String ret = str + " from JAVA";
        return ret;
    }
}
