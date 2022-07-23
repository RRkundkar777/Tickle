package com.ryuapps.tickle;

import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    boolean gameActive = true;
    int[][] gameState = {{2,2,2},{2,2,2},{2,2,2}};
    int activePlayer = 0;

    static Boolean areMovesLeft(int[][] board) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 2) {
                    return true;
                }
            }
        }
        return false;
    }

    static int evaluate(int[][] board) {
        for (int row = 0; row < 3; row++) {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                if (board[row][0] == 0) {
                    return +10;
                }
                else if (board[row][0] == 1) {
                    return -10;
                }
            }
        }

        for (int col = 0; col < 3; col++) {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                if (board[0][col] == 0) {
                    return +10;
                }
                else if (board[0][col] == 1) {
                    return -10;
                }
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 0) {
                return +10;
            }
            else if (board[0][0] == 1) {
                return -10;
            }
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 0) {
                return +10;
            }
            else if (board[0][2] == 1) {
                return -10;
            }
        }
        return 0;
    }

    public void setCell(ImageView view){
        view.setTranslationY(-1000f);
        if(activePlayer == 0){
            view.setImageResource(R.drawable.x);
            activePlayer = 1;
            TextView status = findViewById(R.id.status);
            status.setText(R.string.opponentTurn);
        }
        else{
            view.setImageResource(R.drawable.o);
            activePlayer = 0;
            TextView status = findViewById(R.id.status);
            status.setText(R.string.playerTurn);
        }
        view.animate().translationYBy(1000f).setDuration(300);
    }

    public void gameReset(View view){
        gameActive = true;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                gameState[i][j] = 2;
            }
        }
        activePlayer = 0;

        ((ImageView) findViewById(R.id.imageView00)).setImageResource(0);
        ((ImageView) findViewById(R.id.imageView01)).setImageResource(0);
        ((ImageView) findViewById(R.id.imageView02)).setImageResource(0);
        ((ImageView) findViewById(R.id.imageView10)).setImageResource(0);
        ((ImageView) findViewById(R.id.imageView11)).setImageResource(0);
        ((ImageView) findViewById(R.id.imageView12)).setImageResource(0);
        ((ImageView) findViewById(R.id.imageView20)).setImageResource(0);
        ((ImageView) findViewById(R.id.imageView21)).setImageResource(0);
        ((ImageView) findViewById(R.id.imageView22)).setImageResource(0);

        TextView status = findViewById(R.id.status);
        status.setText(R.string.playerTurn);

        showMessage(getString(R.string.resetMessage));
    }


    public void manualHandle(View view,int x,int y) {
        // Placing the card
        ImageView img  = (ImageView) view;
        if(gameState[x][y] == 2 && gameActive){
            gameState[x][y] = activePlayer;
            setCell(img);
        }

        // Checking for win or lose
        int score = evaluate(gameState);
        if(score == 10){
            gameActive = false;
            TextView status = findViewById(R.id.status);
            status.setText(R.string.playerWon);
            return;
        }
        else if(score == -10){
            gameActive = false;
            TextView status = findViewById(R.id.status);
            status.setText(R.string.opponentWon);
            return;
        }

        // Checking for left moves
        if(!areMovesLeft(gameState)){
            gameActive = false;
            TextView status = findViewById(R.id.status);
            status.setText(R.string.gameDraw);
        }
    }

    static int minimax(int[][] board, int depth, Boolean isMax) {
        int score = evaluate(board);

        if(score == 10) {
            return score - depth;
        }
        if(score == -10) {
            return score + depth;
        }
        if(!areMovesLeft(board)) {
            return 0;
        }

        int best;
        if(isMax) {
            best = -1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if(board[i][j] == 2) {
                        board[i][j] = 0;
                        best = Math.max(best,minimax(board,depth+1,!isMax));
                        board[i][j] = 2;
                    }
                }
            }
        }
        else {
            best = 1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if(board[i][j] == 2) {
                        board[i][j] = 1;
                        best = Math.min(best,minimax(board,depth+1,!isMax));
                        board[i][j] = 2;
                    }
                }
            }
        }
        return best;
    }

    static int[] findOptimalMove(int[][] board) {
        int bestValue = -1000;
        int[] coordinates = new int[2];
        coordinates[0] = -1;
        coordinates[1] = -1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3;j++) {
                if(board[i][j] == 2) {
                    board[i][j] = 0;
                    int moveValue = minimax(board,0,false);
                    board[i][j] = 2;

                    if(moveValue > bestValue) {
                        coordinates[0] = i;
                        coordinates[1] = j;
                        bestValue = moveValue;
                    }
                }
            }
        }
        return coordinates;
    }

    public void autoHandle(View view,int x,int y){
        // Placing the card
        ImageView img  = (ImageView) view;
        if(gameState[x][y] == 2 && gameActive){
            gameState[x][y] = activePlayer;
            setCell(img);
        }

        // Checking for win or lose
        int score = evaluate(gameState);
        if(score == 10){
            gameActive = false;
            TextView status = findViewById(R.id.status);
            status.setText(R.string.playerWon);
            return;
        }
        else if(score == -10){
            gameActive = false;
            TextView status = findViewById(R.id.status);
            status.setText(R.string.opponentWon);
            return;
        }

        // Checking for left moves
        if(!areMovesLeft(gameState)){
            gameActive = false;
            TextView status = findViewById(R.id.status);
            status.setText(R.string.gameDraw);
            return;
        }

        // Auto placing opponent card
        int[] coordinates = findOptimalMove(gameState);
        LinearLayout grid = findViewById(R.id.linearLayout);

        if(coordinates[0] != -1 && coordinates[1] != -1){
            final Handler handler = new Handler();
            handler.postDelayed(() -> {
                // Placing the opponent's card
                gameState[coordinates[0]][coordinates[1]] = activePlayer;

                String tag = coordinates[0] +
                        Integer.toString(coordinates[1]);
                ImageView view1 = grid.findViewWithTag(tag);
                setCell(view1);

                // Checking for win or lose
                int score1 = evaluate(gameState);
                if(score1 == 10){
                    gameActive = false;
                    TextView status = findViewById(R.id.status);
                    status.setText(R.string.playerWon);
                    return;
                }
                else if(score1 == -10){
                    gameActive = false;
                    TextView status = findViewById(R.id.status);
                    status.setText(R.string.opponentWon);
                    return;
                }

                // Checking for left moves
                if(!areMovesLeft(gameState)){
                    gameActive = false;
                    TextView status = findViewById(R.id.status);
                    status.setText(R.string.gameDraw);
                }
            }, 500);
        }
    }

    public void playerTap(View view) {
        ImageView img  = (ImageView) view;
        int tappedImage = Integer.parseInt(img.getTag().toString());
        int x = tappedImage / 10;
        int y = tappedImage % 10;

        // Check for gameover
        if(!gameActive){
            gameReset(view);
            return;
        }

        // Check for game mode
        Switch gameMode = (Switch) findViewById(R.id.mode);

        if(gameMode.isChecked()) {
            autoHandle(view,x,y);
        }
        else{
            manualHandle(view,x,y);
        }
    }

    private void showMessage(String msg) {
        Toast.makeText(this,msg, Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Switch modeSwitch = (Switch) findViewById(R.id.mode);
        modeSwitch.setOnCheckedChangeListener((buttonView, isChecked) -> {
            gameReset(modeSwitch);
            showMessage("Mode changed");
            if(modeSwitch.isChecked()){
                modeSwitch.setText(R.string.mode1);
            }
            else{
                modeSwitch.setText(R.string.mode2);
            }
        });
    }
}