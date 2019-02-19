package com.steffen.connectthree;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity
{
    public static String color = "red";
    public int gameState[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    public int winningStates[][] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6} };

    public void one(View view)
    {
        Button button = findViewById(R.id.button1);
        ImageView redScreen = findViewById(R.id.redWinScreen);
        ImageView yellowScreen = findViewById(R.id.yellowWinScreen);

        if(color.equals("red"))
        {
            ImageView chip = findViewById(R.id.redId1);
            chip.setTranslationX(70f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(535f);
            color = "yellow";
            gameState[0] = 1;
        }
        else if(color.equals("yellow"))
        {
            ImageView chip = findViewById(R.id.yellowId1);
            chip.setTranslationX(70f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(535f);
            color = "red";
            gameState[0] = 2;
        }

        button.setClickable(false);

        for(int winningState[] : winningStates)
        {
            if(gameState[winningState[0]] == 1 && gameState[winningState[1]] == 1 && gameState[winningState[2]] == 1) // check each possible winning combination
            {
                Toast.makeText(MainActivity.this, "Red Wins", Toast.LENGTH_SHORT).show();
                redScreen.setAlpha(1f);
                redScreen.animate().alpha(1f).setDuration(2000);
                redScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }

            else if(gameState[winningState[0]] == 2 && gameState[winningState[1]] == 2 && gameState[winningState[2]] == 2)
            {
                Toast.makeText(MainActivity.this, "Yellow Wins", Toast.LENGTH_SHORT).show();
                yellowScreen.setAlpha(1f);
                yellowScreen.animate().alpha(1f).setDuration(2000);
                yellowScreen.animate().alpha(0f).setDuration(2000);
                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;

                }
            }
        }
    }

    public void two(View view)
    {
        Button button = findViewById(R.id.button2);
        ImageView redScreen = findViewById(R.id.redWinScreen);
        ImageView yellowScreen = findViewById(R.id.yellowWinScreen);

        if(color.equals("red"))
        {
            ImageView chip = findViewById(R.id.redId2);
            chip.setTranslationX(555f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(535f);
            color = "yellow";
            gameState[1] = 1;
        }
        else if(color.equals("yellow"))
        {
            ImageView chip = findViewById(R.id.yellowId2);
            chip.setTranslationX(555f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(535f);
            color = "red";
            gameState[1] = 2;
        }


        button.setClickable(false);

        for(int winningState[] : winningStates)
        {
            if(gameState[winningState[0]] == 1 && gameState[winningState[1]] == 1 && gameState[winningState[2]] == 1)
            {
                Toast.makeText(MainActivity.this, "Red Wins", Toast.LENGTH_SHORT).show();
                redScreen.setAlpha(1f);
                redScreen.animate().alpha(1f).setDuration(2000);
                redScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }

            else if(gameState[winningState[0]] == 2 && gameState[winningState[1]] == 2 && gameState[winningState[2]] == 2)
            {
                Toast.makeText(MainActivity.this, "Yellow Wins", Toast.LENGTH_SHORT).show();
                yellowScreen.setAlpha(1f);
                yellowScreen.animate().alpha(1f).setDuration(2000);
                yellowScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }
        }

    }

    public void three(View view)
    {
        Button button = findViewById(R.id.button3);
        ImageView redScreen = findViewById(R.id.redWinScreen);
        ImageView yellowScreen = findViewById(R.id.yellowWinScreen);

        if(color.equals("red"))
        {
            ImageView chip = findViewById(R.id.redId3);
            chip.setTranslationX(1035f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(535f);
            color = "yellow";
            gameState[2] = 1;
        }
        else if(color.equals("yellow"))
        {
            ImageView chip = findViewById(R.id.yellowId3);
            chip.setTranslationX(1035f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(535f);
            color = "red";
            gameState[2] = 2;
        }


        button.setClickable(false);

        for(int winningState[] : winningStates)
        {
            if(gameState[winningState[0]] == 1 && gameState[winningState[1]] == 1 && gameState[winningState[2]] == 1)
            {
                Toast.makeText(MainActivity.this, "Red Wins", Toast.LENGTH_SHORT).show();
                redScreen.setAlpha(1f);
                redScreen.animate().alpha(1f).setDuration(2000);
                redScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }

            else if(gameState[winningState[0]] == 2 && gameState[winningState[1]] == 2 && gameState[winningState[2]] == 2)
            {
                Toast.makeText(MainActivity.this, "Yellow Wins", Toast.LENGTH_SHORT).show();
                yellowScreen.setAlpha(1f);
                yellowScreen.animate().alpha(1f).setDuration(2000);
                yellowScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }
        }
    }

    public void four(View view)
    {
        Button button = findViewById(R.id.button4);
        ImageView redScreen = findViewById(R.id.redWinScreen);
        ImageView yellowScreen = findViewById(R.id.yellowWinScreen);

        if(color.equals("red"))
        {
            ImageView chip = findViewById(R.id.redId4);
            chip.setTranslationX(70f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1040f);
            color = "yellow";
            gameState[3] = 1;
        }
        else if(color.equals("yellow"))
        {
            ImageView chip = findViewById(R.id.yellowId4);
            chip.setTranslationX(70f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1040f);
            color = "red";
            gameState[3] = 2;
        }


        button.setClickable(false);

        for(int winningState[] : winningStates)
        {
            if(gameState[winningState[0]] == 1 && gameState[winningState[1]] == 1 && gameState[winningState[2]] == 1)
            {
                Toast.makeText(MainActivity.this, "Red Wins", Toast.LENGTH_SHORT).show();
                redScreen.setAlpha(1f);
                redScreen.animate().alpha(1f).setDuration(2000);
                redScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }

            else if(gameState[winningState[0]] == 2 && gameState[winningState[1]] == 2 && gameState[winningState[2]] == 2)
            {
                Toast.makeText(MainActivity.this, "Yellow Wins", Toast.LENGTH_SHORT).show();
                yellowScreen.setAlpha(1f);
                yellowScreen.animate().alpha(1f).setDuration(2000);
                yellowScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }
        }
    }

    public void five(View view)
    {
        Button button = findViewById(R.id.button5);
        ImageView redScreen = findViewById(R.id.redWinScreen);
        ImageView yellowScreen = findViewById(R.id.yellowWinScreen);

        if(color.equals("red"))
        {
            ImageView chip = findViewById(R.id.redId5);
            chip.setTranslationX(555f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1040f);
            color = "yellow";
            gameState[4] = 1;
        }
        else if(color.equals("yellow"))
        {
            ImageView chip = findViewById(R.id.yellowId5);
            chip.setTranslationX(555f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1040f);
            color = "red";
            gameState[4] = 2;
        }


        button.setClickable(false);

        for(int winningState[] : winningStates)
        {
            if(gameState[winningState[0]] == 1 && gameState[winningState[1]] == 1 && gameState[winningState[2]] == 1)
            {
                Toast.makeText(MainActivity.this, "Red Wins", Toast.LENGTH_SHORT).show();
                redScreen.setAlpha(1f);
                redScreen.animate().alpha(1f).setDuration(2000);
                redScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }

            else if(gameState[winningState[0]] == 2 && gameState[winningState[1]] == 2 && gameState[winningState[2]] == 2)
            {
                Toast.makeText(MainActivity.this, "Yellow Wins", Toast.LENGTH_SHORT).show();
                yellowScreen.setAlpha(1f);
                yellowScreen.animate().alpha(1f).setDuration(2000);
                yellowScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }
        }
    }

    public void six(View view)
    {
        Button button = findViewById(R.id.button6);
        ImageView redScreen = findViewById(R.id.redWinScreen);
        ImageView yellowScreen = findViewById(R.id.yellowWinScreen);

        if(color.equals("red"))
        {
            ImageView chip = findViewById(R.id.redId6);
            chip.setTranslationX(1035f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1040f);
            color = "yellow";
            gameState[5] = 1;
        }
        else if(color.equals("yellow"))
        {
            ImageView chip = findViewById(R.id.yellowId6);
            chip.setTranslationX(1035f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1040f);
            color = "red";
            gameState[5] = 2;
        }


        button.setClickable(false);

        for(int winningState[] : winningStates)
        {
            if(gameState[winningState[0]] == 1 && gameState[winningState[1]] == 1 && gameState[winningState[2]] == 1)
            {
                Toast.makeText(MainActivity.this, "Red Wins", Toast.LENGTH_SHORT).show();
                redScreen.setAlpha(1f);
                redScreen.animate().alpha(1f).setDuration(2000);
                redScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }

            else if(gameState[winningState[0]] == 2 && gameState[winningState[1]] == 2 && gameState[winningState[2]] == 2)
            {
                Toast.makeText(MainActivity.this, "Yellow Wins", Toast.LENGTH_SHORT).show();
                yellowScreen.setAlpha(1f);
                yellowScreen.animate().alpha(1f).setDuration(2000);
                yellowScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }
        }
    }

    public void seven(View view)
    {
        Button button = findViewById(R.id.button7);
        ImageView redScreen = findViewById(R.id.redWinScreen);
        ImageView yellowScreen = findViewById(R.id.yellowWinScreen);

        if(color.equals("red"))
        {
            ImageView chip = findViewById(R.id.redId7);
            chip.setTranslationX(70f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1580f);
            color = "yellow";
            gameState[6] = 1;
        }
        else if(color.equals("yellow"))
        {
            ImageView chip = findViewById(R.id.yellowId7);
            chip.setTranslationX(70f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1580f);
            color = "red";
            gameState[6] = 2;
        }


        button.setClickable(false);

        for(int winningState[] : winningStates)
        {
            if(gameState[winningState[0]] == 1 && gameState[winningState[1]] == 1 && gameState[winningState[2]] == 1)
            {
                Toast.makeText(MainActivity.this, "Red Wins", Toast.LENGTH_SHORT).show();
                redScreen.setAlpha(1f);
                redScreen.animate().alpha(1f).setDuration(2000);
                redScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }

            else if(gameState[winningState[0]] == 2 && gameState[winningState[1]] == 2 && gameState[winningState[2]] == 2)
            {
                Toast.makeText(MainActivity.this, "Yellow Wins", Toast.LENGTH_SHORT).show();
                yellowScreen.setAlpha(1f);
                yellowScreen.animate().alpha(1f).setDuration(2000);
                yellowScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }
        }
    }

    public void eight(View view)
    {
        Button button = findViewById(R.id.button8);
        ImageView redScreen = findViewById(R.id.redWinScreen);
        ImageView yellowScreen = findViewById(R.id.yellowWinScreen);

        if(color.equals("red"))
        {
            ImageView chip = findViewById(R.id.redId8);
            chip.setTranslationX(555f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1580f);
            color = "yellow";
            gameState[7] = 1;
        }
        else if(color.equals("yellow"))
        {
            ImageView chip = findViewById(R.id.yellowId8);
            chip.setTranslationX(555f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1580f);
            color = "red";
            gameState[7] = 2;
        }


        button.setClickable(false);

        for(int winningState[] : winningStates)
        {
            if(gameState[winningState[0]] == 1 && gameState[winningState[1]] == 1 && gameState[winningState[2]] == 1)
            {
                Toast.makeText(MainActivity.this, "Red Wins", Toast.LENGTH_SHORT).show();
                redScreen.setAlpha(1f);
                redScreen.animate().alpha(1f).setDuration(2000);
                redScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }

            else if(gameState[winningState[0]] == 2 && gameState[winningState[1]] == 2 && gameState[winningState[2]] == 2)
            {
                Toast.makeText(MainActivity.this, "Yellow Wins", Toast.LENGTH_SHORT).show();
                yellowScreen.setAlpha(1f);
                yellowScreen.animate().alpha(1f).setDuration(2000);
                yellowScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }
        }
    }

    public void nine(View view)
    {
        Button button = findViewById(R.id.button9);
        ImageView redScreen = findViewById(R.id.redWinScreen);
        ImageView yellowScreen = findViewById(R.id.yellowWinScreen);

        if(color.equals("red"))
        {
            ImageView chip = findViewById(R.id.redId9);
            chip.setTranslationX(1035f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1580f);
            color = "yellow";
            gameState[8] = 1;
        }
        else if(color.equals("yellow"))
        {
            ImageView chip = findViewById(R.id.yellowId9);
            chip.setTranslationX(1035f);
            chip.setTranslationY(0f);
            chip.setAlpha(1f);
            chip.animate().translationYBy(1580f);
            color = "red";
            gameState[8] = 2;
        }


        button.setClickable(false);

        for(int winningState[] : winningStates)
        {
            if(gameState[winningState[0]] == 1 && gameState[winningState[1]] == 1 && gameState[winningState[2]] == 1)
            {
                Toast.makeText(MainActivity.this, "Red Wins", Toast.LENGTH_SHORT).show();
                redScreen.setAlpha(1f);
                redScreen.animate().alpha(1f).setDuration(2000);
                redScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }

            else if(gameState[winningState[0]] == 2 && gameState[winningState[1]] == 2 && gameState[winningState[2]] == 2)
            {
                Toast.makeText(MainActivity.this, "Yellow Wins", Toast.LENGTH_SHORT).show();
                yellowScreen.setAlpha(1f);
                yellowScreen.animate().alpha(1f).setDuration(2000);
                yellowScreen.animate().alpha(0f).setDuration(2000);

                for(int i = 0; i < gameState.length; i++)
                {
                    gameState[i] = 0;
                }
            }
        }
    }

    public void clearFunc(View view)
    {
        ImageView chip1 = findViewById(R.id.yellowId1);
        ImageView chip2 = findViewById(R.id.yellowId2);
        ImageView chip3 = findViewById(R.id.yellowId3);
        ImageView chip4 = findViewById(R.id.yellowId4);
        ImageView chip5 = findViewById(R.id.yellowId5);
        ImageView chip6 = findViewById(R.id.yellowId6);
        ImageView chip7 = findViewById(R.id.yellowId7);
        ImageView chip8 = findViewById(R.id.yellowId8);
        ImageView chip9 = findViewById(R.id.yellowId9);

        ImageView chip10 = findViewById(R.id.redId1);
        ImageView chip11 = findViewById(R.id.redId2);
        ImageView chip12 = findViewById(R.id.redId3);
        ImageView chip13 = findViewById(R.id.redId4);
        ImageView chip14 = findViewById(R.id.redId5);
        ImageView chip15 = findViewById(R.id.redId6);
        ImageView chip16 = findViewById(R.id.redId7);
        ImageView chip17 = findViewById(R.id.redId8);
        ImageView chip18 = findViewById(R.id.redId9);

        Button button1 = findViewById(R.id.button1);
        Button button2 = findViewById(R.id.button2);
        Button button3 = findViewById(R.id.button3);
        Button button4 = findViewById(R.id.button4);
        Button button5 = findViewById(R.id.button5);
        Button button6 = findViewById(R.id.button6);
        Button button7 = findViewById(R.id.button7);
        Button button8 = findViewById(R.id.button8);
        Button button9= findViewById(R.id.button9);

        chip1.setAlpha(0f);
        chip2.setAlpha(0f);
        chip3.setAlpha(0f);
        chip4.setAlpha(0f);
        chip5.setAlpha(0f);
        chip6.setAlpha(0f);
        chip7.setAlpha(0f);
        chip8.setAlpha(0f);
        chip9.setAlpha(0f);

        chip10.setAlpha(0f);
        chip11.setAlpha(0f);
        chip12.setAlpha(0f);
        chip13.setAlpha(0f);
        chip14.setAlpha(0f);
        chip15.setAlpha(0f);
        chip16.setAlpha(0f);
        chip17.setAlpha(0f);
        chip18.setAlpha(0f);

        button1.setClickable(true);
        button2.setClickable(true);
        button3.setClickable(true);
        button4.setClickable(true);
        button5.setClickable(true);
        button6.setClickable(true);
        button7.setClickable(true);
        button8.setClickable(true);
        button9.setClickable(true);

        for(int i = 0; i < gameState.length; i++)
        {
            gameState[i] = 0;
        }

        Toast.makeText(MainActivity.this, "Board Cleared", Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}
