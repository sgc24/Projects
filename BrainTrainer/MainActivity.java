package com.steffen.braintrainer;

import android.graphics.Color;
import android.os.CountDownTimer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity
{
    Button go;
    Button b1;
    Button b2;
    Button b3;
    Button b4;
    TextView seconds;
    TextView equation;
    TextView score;
    int firstNum = 0;
    int secondNum = 0;
    int sum = 0;
    int flag = 0;
    int correct = 0;
    int total = 0;
    TextView message;
    TextView finalScore;
    Button playAgain;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        b1 = findViewById(R.id.button1);
        b2 = findViewById(R.id.button2);
        b3 = findViewById(R.id.button3);
        b4 = findViewById(R.id.button4);
        seconds = findViewById(R.id.seconds);
        equation = findViewById(R.id.equation);
        score = findViewById(R.id.score);
        message = findViewById(R.id.message);
        finalScore = findViewById(R.id.finalScore);
        playAgain = findViewById(R.id.playAgain);

        playAgain.setVisibility(View.INVISIBLE);
        finalScore.setVisibility(View.INVISIBLE);
        message.setVisibility(View.INVISIBLE);
        b1.setVisibility(View.INVISIBLE);
        b2.setVisibility(View.INVISIBLE);
        b3.setVisibility(View.INVISIBLE);
        b4.setVisibility(View.INVISIBLE);
        seconds.setVisibility(View.INVISIBLE);
        equation.setVisibility(View.INVISIBLE);
        score.setVisibility(View.INVISIBLE);

    }

    public void goFunc(View view)
    {
        go = findViewById(R.id.go);
        go.setVisibility(view.INVISIBLE);
        b1.setVisibility(View.VISIBLE);
        b2.setVisibility(View.VISIBLE);
        b3.setVisibility(View.VISIBLE);
        b4.setVisibility(View.VISIBLE);
        seconds.setVisibility(View.VISIBLE);
        equation.setVisibility(View.VISIBLE);
        score.setVisibility(View.VISIBLE);
        finalScore.setVisibility(View.INVISIBLE);

        firstNum = 0;
        secondNum = 0;
        sum = 0;
        flag = 0;
        correct = 0;
        total = 0;

        firstNum = eqRandomizer();
        secondNum = eqRandomizer();
        sum = firstNum + secondNum;
        equation.setText(String.valueOf(firstNum) + " + " + String.valueOf(secondNum));
        flag = corrRandomizer();
        pickButton();
        setButtons();



        new CountDownTimer(30000, 1000)
        {
            public void onTick(long millisecondsUntilDone)
            {
                String secs = String.valueOf((millisecondsUntilDone / 1000) % 60);
                int secZeroCheck = secs.length();

                if(secZeroCheck == 1)
                {
                    secs = "0" + secs;
                }
                seconds.setText(secs + "s");
            }

            public void onFinish()//                       Enable when you make play again button
            {
                b1.setEnabled(false);
                b2.setEnabled(false);
                b3.setEnabled(false);
                b4.setEnabled(false);
                message.setVisibility(View.INVISIBLE);
                finalScore.setText("Your Score: " + score.getText().toString());
                finalScore.setVisibility(View.VISIBLE);
                playAgain.setVisibility(View.VISIBLE);
            }
        }.start();

    }

    public void b1Func(View view)
    {
        if(flag == 1)
        {
            correct += 1;
            total += 1;

            score.setText(String.valueOf(correct) + "/" + String.valueOf(total));
            message.setTextColor(Color.GREEN);
            message.setText("CORRECT!");
            message.setVisibility(View.VISIBLE);
        }

        else
        {
            total += 1;

            score.setText(String.valueOf(correct) + "/" + String.valueOf(total));
            message.setTextColor(Color.RED);
            message.setText("WRONG!");
            message.setVisibility(View.VISIBLE);

        }

        firstNum = eqRandomizer();
        secondNum = eqRandomizer();
        sum = firstNum + secondNum;
        equation.setText(String.valueOf(firstNum) + " + " + String.valueOf(secondNum));
        flag = corrRandomizer();
        pickButton();
        setButtons();

    }

    public void b2Func(View view)
    {
        if(flag == 2)
        {
            correct += 1;
            total += 1;

            score.setText(String.valueOf(correct) + "/" + String.valueOf(total));
            message.setTextColor(Color.GREEN);
            message.setText("CORRECT!");
            message.setVisibility(View.VISIBLE);
        }

        else
        {
            total += 1;

            score.setText(String.valueOf(correct) + "/" + String.valueOf(total));
            message.setTextColor(Color.RED);
            message.setText("WRONG!");
            message.setVisibility(View.VISIBLE);

        }

        firstNum = eqRandomizer();
        secondNum = eqRandomizer();
        sum = firstNum + secondNum;
        equation.setText(String.valueOf(firstNum) + " + " + String.valueOf(secondNum));
        flag = corrRandomizer();
        pickButton();
        setButtons();

    }

    public void b3Func(View view)
    {
        if(flag == 3)
        {
            correct += 1;
            total += 1;

            score.setText(String.valueOf(correct) + "/" + String.valueOf(total));
            message.setTextColor(Color.GREEN);
            message.setText("CORRECT!");
            message.setVisibility(View.VISIBLE);
        }

        else
        {
            total += 1;

            score.setText(String.valueOf(correct) + "/" + String.valueOf(total));
            message.setTextColor(Color.RED);
            message.setText("WRONG!");
            message.setVisibility(View.VISIBLE);
        }

        firstNum = eqRandomizer();
        secondNum = eqRandomizer();
        sum = firstNum + secondNum;
        equation.setText(String.valueOf(firstNum) + " + " + String.valueOf(secondNum));
        flag = corrRandomizer();
        pickButton();
        setButtons();

    }

    public void b4Func(View view)
    {
        if(flag == 4)
        {
            correct += 1;
            total += 1;

            score.setText(String.valueOf(correct) + "/" + String.valueOf(total));
            message.setTextColor(Color.GREEN);
            message.setText("CORRECT!");
            message.setVisibility(View.VISIBLE);
        }

        else
        {
            total += 1;

            score.setText(String.valueOf(correct) + "/" + String.valueOf(total));
            message.setTextColor(Color.RED);
            message.setText("WRONG!");
            message.setVisibility(View.VISIBLE);
        }

        firstNum = eqRandomizer();
        secondNum = eqRandomizer();
        sum = firstNum + secondNum;
        equation.setText(String.valueOf(firstNum) + " + " + String.valueOf(secondNum));
        flag = corrRandomizer();
        pickButton();
        setButtons();

    }

    public int eqRandomizer()
    {
        Random rand = new Random();

        int n = rand.nextInt(49);

        return n;
    }

    public int corrRandomizer()
    {
        Random rand = new Random();
        int n = rand.nextInt(4) + 1;

        return n;
    }

    public int incRamdomzer()
    {
        Random rand = new Random();

        int n = rand.nextInt(98);

        while(n == sum)
        {
            n = rand.nextInt(98);
        }

        return n;
    }


    public void pickButton()
    {
        switch(flag)
        {
            case 1:
                    b1.setText(String.valueOf(sum));
                    break;
            case 2:
                    b2.setText(String.valueOf(sum));
                    break;
            case 3:
                    b3.setText(String.valueOf(sum));
                    break;
            case 4:
                    b4.setText(String.valueOf(sum));
                    break;
        }
    }

    public void setButtons()
    {
        if(flag == 1)
        {
            b2.setText(String.valueOf(incRamdomzer()));
            b3.setText(String.valueOf(incRamdomzer()));
            b4.setText(String.valueOf(incRamdomzer()));
        }
         else if(flag == 2)
        {
            b1.setText(String.valueOf(incRamdomzer()));
            b3.setText(String.valueOf(incRamdomzer()));
            b4.setText(String.valueOf(incRamdomzer()));
        }

        else if(flag == 3)
        {
            b1.setText(String.valueOf(incRamdomzer()));
            b2.setText(String.valueOf(incRamdomzer()));
            b4.setText(String.valueOf(incRamdomzer()));
        }

        else if(flag == 4)
        {
            b1.setText(String.valueOf(incRamdomzer()));
            b2.setText(String.valueOf(incRamdomzer()));
            b3.setText(String.valueOf(incRamdomzer()));
        }

    }

    public void againFunc(View view)
    {

        b1.setEnabled(true);
        b2.setEnabled(true);
        b3.setEnabled(true);
        b4.setEnabled(true);

        playAgain.setVisibility(View.INVISIBLE);
        score.setText("0/0");
        goFunc(view);

        /*
        firstNum = 0;
        secondNum = 0;
        sum = 0;
        flag = 0;
        correct = 0;
        total = 0;



        finalScore.setVisibility(View.INVISIBLE);
        playAgain.setVisibility(View.INVISIBLE);

        firstNum = eqRandomizer();
        secondNum = eqRandomizer();
        sum = firstNum + secondNum;
        equation.setText(String.valueOf(firstNum) + " + " + String.valueOf(secondNum));
        flag = corrRandomizer();
        pickButton();
        setButtons();



        new CountDownTimer(30000, 1000)
        {
            public void onTick(long millisecondsUntilDone)
            {
                String secs = String.valueOf((millisecondsUntilDone / 1000) % 60);
                int secZeroCheck = secs.length();

                if(secZeroCheck == 1)
                {
                    secs = "0" + secs;
                }
                seconds.setText(secs + "s");
            }

            public void onFinish()//                       Enable when you make play again button
            {
                b1.setEnabled(false);
                b2.setEnabled(false);
                b3.setEnabled(false);
                b4.setEnabled(false);
                message.setVisibility(View.INVISIBLE);
                finalScore.setText("Your Score: " + score.getText().toString());
                finalScore.setVisibility(View.VISIBLE);
                playAgain.setVisibility(View.VISIBLE);
            }
        }.start();

*/
    }

}
