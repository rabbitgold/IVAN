package com.example.myanimals_mobile;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import java.util.ArrayList;
import java.util.HashMap;

public class MainActivity extends AppCompatActivity {

    DBManager dataBase;
    ListView animalsView;

    ArrayList<HashMap<String, String>> arrayList = new ArrayList<>();
    HashMap<String, String> map;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        dataBase= new DBManager(this);
        animalsView = findViewById(R.id.animalsView);
        animalsView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                int currentID = Integer.parseInt(arrayList.get(position).get("AnimalID").toString());

                SQLiteDatabase sqLiteDatabase = dataBase.getWritableDatabase();
                sqLiteDatabase.delete("Animals", "id = " + currentID, null);

                updateAnimals();
            }

        });;

        updateAnimals();
    }

    public void updateAnimals()
    {
        arrayList.clear();

        ListView _animalsView = findViewById(R.id.animalsView);
        SQLiteDatabase sqLiteDatabase = dataBase.getWritableDatabase();
        Cursor cursor = sqLiteDatabase.query("Animals", null,null,null,null,null, null);

        if(cursor.moveToFirst())
        {
            map = new HashMap<>();
            map.put("AnimalID", cursor.getString(cursor.getColumnIndex("id")));
            map.put("AnimalName", cursor.getString(cursor.getColumnIndex("animalName")));
            map.put("AnimalClass", cursor.getString(cursor.getColumnIndex("animalClass")));
            arrayList.add(map);

            while (cursor.moveToNext())
            {
                map = new HashMap<>();
                map.put("AnimalID", cursor.getString(cursor.getColumnIndex("id")));
                map.put("AnimalName", cursor.getString(cursor.getColumnIndex("animalName")));
                map.put("AnimalClass", cursor.getString(cursor.getColumnIndex("animalClass")));
                arrayList.add(map);
            }
        }

        SimpleAdapter adapter = new SimpleAdapter(this, arrayList, R.layout.list_animal,
                new String[]{"AnimalID", "AnimalName", "AnimalClass"},
                new int[]{R.id.text_view_animalID, R.id.text_animalName, R.id.text_animalClass});
        _animalsView.setAdapter(adapter);

    }

    public void refreshView(View view)
    {
        updateAnimals();
    }

    public void addAnimal(View view)
    {
        Intent intent = new Intent(this, activity_add_animal.class);
        startActivity(intent);
    }
}
