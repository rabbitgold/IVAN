package com.example.myanimals_mobile;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DBManager extends SQLiteOpenHelper
{
    static private final String nameDB = "AnimalsDB";
    static private final int versionDB = 1;

    public DBManager(Context context)
    {
        super(context, nameDB, null, versionDB);
    }

    @Override
    public void onCreate(SQLiteDatabase db)
    {
        db.execSQL("create table Animals(id integer primary key autoincrement, animalName text, animalClass text, animalWeight integer);");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion)
    {

    }
}
