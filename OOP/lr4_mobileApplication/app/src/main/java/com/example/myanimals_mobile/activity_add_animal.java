package com.example.myanimals_mobile;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class activity_add_animal extends AppCompatActivity {

    DBManager dataBase;

    EditText animalNameEdit, animalClassEdit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_animal);

        animalNameEdit = findViewById(R.id.animalNameEdit);
        animalClassEdit = findViewById(R.id.animalClassEdit);

        dataBase = new DBManager(this);
    }

    public void acceptBtn(View view)
    {
        if(animalNameEdit.getText().toString().isEmpty()||
                animalClassEdit.getText().toString().isEmpty())
        {
            Toast massage = Toast.makeText(getApplicationContext(), "Заполните все поля", Toast.LENGTH_LONG);
            massage.show();
        }
        else
        {
            final SQLiteDatabase sqLiteDatabase = dataBase.getWritableDatabase();

            ContentValues contentValues = new ContentValues();
            contentValues.put("animalName", animalNameEdit.getText().toString());
            contentValues.put("animalClass", animalClassEdit.getText().toString());

            sqLiteDatabase.insert("Animals", null, contentValues);
            this.finish();
        }
    }
}