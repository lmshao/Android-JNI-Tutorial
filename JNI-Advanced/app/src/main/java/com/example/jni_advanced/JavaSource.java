package com.example.jni_advanced;

import android.util.Log;

/**
 * Created by shao.liming on 8/28/2017.
 */

public class JavaSource {
    public interface InterClass{
        void onStatus(int status);
    }

    private static InterClass mInterClass;

    public void setOnStatusListener(InterClass interClass){
        mInterClass = interClass;
        mInterClass.onStatus(8);
        String log = "setOnStatusListener InterClass = " + mInterClass;
        Log.d("JavaSource", log);
    }

    public static String getStr(){
        String str = "Hello from JavaSource class\n" + mInterClass;
        return str;
    }


}
