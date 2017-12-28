package com.example.jni_structure;

//
//  Copyright (c) 2017 Liming Shao <lmshao@163.com>
//

import android.provider.MediaStore;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;

import static android.widget.Toast.*;

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

        TextView tv = (TextView) findViewById(R.id.textViewUserInfo);
        tv.setText(profile);

        Button btOK = (Button) findViewById(R.id.buttonOK);
        btOK.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Get name
                EditText etName = (EditText) findViewById(R.id.editTextName);
                String name = etName.getText().toString();
                if (name.isEmpty()){
                    name = "Name";
                }

                // Get ID
                EditText etID = (EditText) findViewById(R.id.editTextID);
                String idStr = etID.getText().toString();
                if (idStr.isEmpty()){
                    idStr = "00000000";
                }
                byte[] id = idStr.getBytes();

                // Get age
                EditText etAge = (EditText) findViewById(R.id.editTextAge);
                String ageStr = etAge.getText().toString();
                if (ageStr.isEmpty()){
                    ageStr = "1";
                }
                int age = Integer.parseInt(ageStr);
                if (age > 100){
                    Toast.makeText(getApplicationContext(),"You are too old!", LENGTH_SHORT).show();
                    age = 1;
                }

                // Get
                RadioButton rbBoy = findViewById(R.id.radioButtonBoy);

                UserInfo userInfo = fillUserInfo(id, name, age, rbBoy.isChecked());
                String profile = getUserProfile(userInfo);
                TextView tv = (TextView) findViewById(R.id.textViewUserInfo);
                tv.setText(profile);
            }
        });

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
