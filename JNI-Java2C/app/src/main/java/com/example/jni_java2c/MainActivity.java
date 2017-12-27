package com.example.jni_java2c;

//
//  Copyright (c) 2017 Liming Shao <lmshao@163.com>
//

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView) findViewById(R.id.textView1);
        tv.setText("1. " + stringFromJNI());

        TextView tv2 = (TextView) findViewById(R.id.textView2);
        tv2.setText("2. " + getStringFromJNI());

        TextView tv3 = (TextView) findViewById(R.id.textView3);
        tv3.setText("3. 7+8 = " + getSumFromJNI(7, 8));

        char[] arr = {'e','x', 'a', 'm', 'p', 'l', 'e'};
        putCharArrayToJNI(arr);
        TextView tv4 = (TextView) findViewById(R.id.textView4);
        tv4.setText("4. call putCharArrayJNI, please view the log");

    }

    // 1st method to call C from Java
    public native String stringFromJNI();


    // 2nd method to call C from Java
    public native String getStringFromJNI();
    public native int getSumFromJNI(int x, int y);
    public native void putCharArrayToJNI(char[] in);
}
