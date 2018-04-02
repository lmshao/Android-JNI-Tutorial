package com.lmshao.jniexample;

import java.util.UUID;

/**
 * Created by Liming Shao on 4/1/2018.
 */

public class JniManager {
    static {
        System.loadLibrary("native-lib");
    }

    public Student getStudentInfo(){
        Student student = new Student();
        student.mName = "XiaoMing";
        student.mId = UUID.randomUUID();
        student.mAge = 27;
        student.mIsBoy = true;

        CourseScore score = new CourseScore();
        score.mChinese = 90;
        score.mMath = 96;
        score.mMusic = CourseScore.ScoreLevel.fromValue(2);

        student.mScore = score;
        return student;
    }

    public native Student nGetStudentInfo();
}
