package com.lmshao.jniexample;

/**
 * Created by Liming Shao on 3/31/2018.
 */

public class CourseScore {
    int mMath;
    int mChinese;
    ScoreLevel mMusic;

    public enum ScoreLevel {
        LEVEL_A (0x00, "excellent"),
        LEVEL_B (0x01, "good"),
        LEVEL_C (0x02, "pass"),
        LEVEL_D (0x03, "failed");

        private int mValue;
        private String mInfo;

        ScoreLevel(int value, String info) {
            mValue = value;
            mInfo = info;
        }

        public static ScoreLevel fromValue(int value){
            return ScoreLevel.values()[value];
        }
    }
}
