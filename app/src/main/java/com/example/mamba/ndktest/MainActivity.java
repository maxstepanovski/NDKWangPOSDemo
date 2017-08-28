package com.example.mamba.ndktest;

import android.os.RemoteException;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import wangpos.sdk4.libbasebinder.Core;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    private Core core;

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        new Thread(new Runnable() {
            @Override
            public void run() {
                core = new Core(getApplicationContext());
            }
        }).start();

        runCore();
    }

    public void makeBeep() throws RemoteException {
        core.buzzerEx(600);
    }

    public native void runCore();

    @Override
    public void onClick(View view) {
        try {
            core.buzzer();
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
