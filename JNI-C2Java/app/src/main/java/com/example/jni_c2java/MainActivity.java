package com.example.jni_c2java;

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

        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(getStrFromJNI());
//        tv.setText("7+8 = "+getSumFromJNI(7, 8));
//        tv.setText(printMsgFromJNI());

    }

    public native String getStrFromJNI();
    public native int getSumFromJNI(int x, int y);
    public native String printMsgFromJNI();
}
