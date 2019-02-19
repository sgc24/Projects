package com.steffen.eggtimer;

import android.media.MediaPlayer;
import android.os.CountDownTimer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity
{
    TextView textView;
    SeekBar setTimer;
    Button stop;
    Button go;
    boolean timerStopped = false;
    MediaPlayer soundAlarm;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        soundAlarm = MediaPlayer.create(this, R.raw.timer);
        stop = findViewById(R.id.stopButton);
        go = findViewById(R.id.goButton);
        go.bringToFront();

        textView =  findViewById(R.id.timerText);
        setTimer = findViewById(R.id.setTimer);

        setTimer.setMax(900000);
        setTimer.setProgress(30000);
        textView.setText("00:30");

        setTimer.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser)
            {
                Log.i("on change: ", String.valueOf(setTimer.getProgress()));
                String seconds = String.valueOf((setTimer.getProgress() / 1000) % 60);
                String minutes = String.valueOf((setTimer.getProgress() / (1000 * 60)) % 60);

                int secZeroCheck = seconds.length();
                int minZeroCheck = minutes.length();

                if(secZeroCheck == 1)
                {
                    seconds = "0" + seconds;
                }

                if(minZeroCheck == 1)
                {
                    minutes = "0" + minutes;
                }

                textView.setText( String.valueOf( minutes) + ":" + String.valueOf( seconds)); // set timer tied to seekbar
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar)
            {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar)
            {

            }
        });
    }

    public void startTimer(View view)
    {
        setTimer.setAlpha(0f);
        stop.bringToFront();
        go.setAlpha(0f);
        stop.setAlpha(1f);
        timerStopped = false;
        Log.i("start before: ", String.valueOf(setTimer.getProgress()));
        new CountDownTimer(setTimer.getProgress(), 1000) // change millisinfuture to seekbar value
        {
            public void onTick(long millisecondsUntilDone)
            {
                if(timerStopped == true)
                {
                    cancel();
                }

                if(timerStopped == false)
                {
                    String seconds = String.valueOf((millisecondsUntilDone / 1000) % 60);
                    String minutes = String.valueOf((millisecondsUntilDone / (1000 * 60)) % 60);

                    int secZeroCheck = seconds.length();
                    int minZeroCheck = minutes.length();

                    if(secZeroCheck == 1)
                    {
                        seconds = "0" + seconds;
                    }

                    if(minZeroCheck == 1)
                    {
                        minutes = "0" + minutes;
                    }

                    Log.i("time Left: ", String.valueOf( minutes ) + ":" + String.valueOf(seconds));
                    textView.setText(minutes + ":" + seconds); // start counting down from seekbar value

                }
            }

            public void onFinish()
            {
                soundAlarm.start();

                setTimer.setAlpha(1f);
                go.bringToFront();
                stop.setAlpha(0f);
                go.setAlpha(1f);
                setTimer.setProgress(30000);
                textView.setText("00:30");
                timerStopped = true;
                Log.i("fin", "Countdown timer finished");
            }

        }.start();
    }

    public void stopTimer(View view)
    {
        Log.i("stop before: ", String.valueOf(setTimer.getProgress()));
        setTimer.setAlpha(1f);
        go.bringToFront();
        stop.setAlpha(0f);
        go.setAlpha(1f);
        setTimer.setProgress(30000);
        textView.setText("00:30");
        timerStopped = true;
        Log.i("stop after: ", String.valueOf(setTimer.getProgress()));
    }
}