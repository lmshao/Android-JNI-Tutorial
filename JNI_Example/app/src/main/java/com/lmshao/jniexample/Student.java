package com.lmshao.jniexample;

import java.util.UUID;

/**
 * Created by Liming Shao on 3/31/2018.
 */

public class Student {
    public Student() {
    }

    public Student(String mName, UUID mId, boolean mIsBoy, int mAge, CourseScore mScore) {
        this.mName = mName;
        this.mId = mId;
        this.mIsBoy = mIsBoy;
        this.mAge = mAge;
        this.mScore = mScore;
    }

    public String mName;
    public UUID mId;
    public boolean  mIsBoy;
    public int mAge;
    CourseScore mScore;
}
