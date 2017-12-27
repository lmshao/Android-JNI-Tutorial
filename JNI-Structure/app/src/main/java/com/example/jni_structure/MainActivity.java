package com.example.jni_structure;

//
//  Copyright (c) 2017 Liming Shao <lmshao@163.com>
//

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        byte[] id = "A12345".getBytes();
        String name = "Jack";
        int age = 26;

        UserInfo userInfo = fillUserInfo(id, name, age, true);
        String profile = getUserProfile(userInfo);

        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(profile);
    }


    public native String getUserProfile(UserInfo userInfo);
    public native UserInfo fillUserInfo(byte[] ID, String name, int age, boolean isBoy);

    class UserInfo {

        UserInfo(byte[] ID, String name, int age, boolean isBoy, String comments){
            this.ID = ID;
            this.name = name;
            this.age = age;
            this.isBoy = isBoy;
            this.comments = comments;
        }

        byte[] ID;
        String name;
        int age;
        boolean isBoy;
        String comments;
    }
}
