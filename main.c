#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int time_played = 0;
int position;
int actual_player;



bool on = true;
int movements[2];
char positions[3][3];

void printBoard()
{

    system("CLS");
    printf("\n\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\t\tCurrent player: Player %d.\n", 186, 32, positions[0][0], 32, 186, 32,positions[0][1] , 32, 186, 32, positions[0][2], 32, 186, actual_player + 1);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\t\tTotal movements:  %d.\n", 186, 32, positions[1][0], 32, 186, 32, positions[1][1], 32, 186, 32, positions[1][2], 32, 186, movements[actual_player]);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, positions[2][0], 32, 186, 32, positions[2][1], 32, 186, 32, positions[2][2], 32, 186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n", 200, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
}


void checkWin()
{
    int p1_cont_h = 0;
    int p2_cont_h = 0;
    int p1_cont_v = 0;
    int p2_cont_v = 0;
    int p1_cont_c = 0;
    int p2_cont_c = 0;

    //Check horizontals and verticals
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (positions[i][j] == 'X')
                p1_cont_h++;
            if (positions[i][j] == 'O')
                p2_cont_h++;
            if (positions[j][i] == 'X')
                p1_cont_v++;
            if (positions[j][i] == 'O')
                p2_cont_v++;
        }

        if (p1_cont_h == 3 || p2_cont_h ==  3 || p1_cont_v == 3 || p2_cont_v ==  3)
            on = false;
    }
    printf("p1_cont_h: %d\n", p1_cont_h);
    printf("p2_cont_h: %d\n", p2_cont_h);
    printf("p1_cont_v: %d\n", p1_cont_v);
    printf("p2_cont_v: %d\n", p2_cont_v);

    //Check cross Up to Down
    for (int i=0, j=0; i<3, j<3; i++, j++)
    {
        if (positions[i][j] == 'X')
            p1_cont_c++;
        if (positions[i][j] == 'O')
            p2_cont_c++;
    }
    if (p1_cont_c == 3 || p2_cont_c == 3)
        on = false;

    p1_cont_c = 0;
    p2_cont_c = 0;
    //Check cross Down to Up
    for (int i=2, j=0; i>=0, j<3; i--, j++)
    {
        if (positions[i][j] == 'X')
            p1_cont_c++;
        if (positions[i][j] == 'O')
            p2_cont_c++;
    }
    if (p1_cont_c == 3 || p2_cont_c == 3)
        on = false;

}

void writePlay()
{
    bool correct = false;
    while (!correct){
        printf("Enter your position, Player %d.\n", actual_player + 1);
        scanf("%d", &position);
        printf("Position chosen: %d\n", position);

        int row = (position / 10);
        int column = (position - row*10) - 1;
        row--;


        printf("row: %d\n", row);
        printf("col: %d\n", column);

        if (positions[row][column] != ' ' || row > 2 || column > 2)
            printf("\n\nThe position is not correct, select another!\n" );
        else
        {
            switch (actual_player) {
                case 0:
                    positions[row][column] = 'X';
                    checkWin();
                    break;
                case 1:
                    positions[row][column] = 'O';
                    checkWin();
                    break;
            }
            correct = true;
        }

    }

}


void update()
{
    while(on == true){



        // printf("\n\n Tiempo: %d s", ++time);
        // Sleep(1000);
        writePlay();
        movements[actual_player]++;
        actual_player = (actual_player + 1) % 2;
        printBoard();
    }

    printf("The winner is player %d!!!\n", actual_player + 1);

}

void init()
{
    time_t t;
    srand((unsigned) time(&t));
    actual_player = rand() % 2;
    printf("actual_player: %d\n", actual_player);
    position = 00;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            positions[i][j] = ' ';
}


int main(int argc, char** argv)
{

    init();
    printBoard();
    update();



    return 0;
}
