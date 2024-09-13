#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Fisher-Yates ϴ���㷨�������������
void Shuffle(int arr[], int n)
{
    srand(time(0));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// ��������ڸ����Ƿ�Ϸ�
bool Conflict_Row(int board[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
}

// ��������ڸ����Ƿ�Ϸ�
bool Conflict_Col(int board[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
}

// ��������ڸ�3x3�����Ƿ�Ϸ�
bool Conflict_Block(int board[9][9], int startRow, int startCol, int num)
{
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row + startRow][col + startCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool Conflict_Cross(int board[9][9], int row, int col, int num)
{
    if (row + col == 8) { // ���Խ���
        for (int i_row = 0; i_row < 9; i_row++) {
            if (i_row == row) { // ��������
                continue;
            }
            if (board[i_row][8 - i_row] == num) {
                return true;
            }
        }
        return false;
    } else if (row == col) { // ���Խ���
        for (int i_row = 0; i_row < 9; i_row++) {
            if (i_row == row) { // ��������
                continue;
            }
            if (board[i_row][i_row] == num) {
                return true;
            }
        }
        return false;
    } else { // ���ڶԽ���
        return false;
    }
}

// ����ܷ���ָ��λ�÷�������
bool Fillable(int board[9][9], int row, int col, int num)
{
    return !Conflict_Row(board, row, num) &&
           !Conflict_Col(board, col, num) &&
           !Conflict_Cross(board, row, col, num) &&
           !Conflict_Block(board, row - row % 3, col - col % 3, num);
}

// ���ݷ���������������
bool Fill_Board(int board[9][9], int row, int col)
{
    if (row == 9 - 1 && col == 9) {
        return true;
    }

    if (col == 9) {
        row++;
        col = 0;
    }

    if (board[row][col] != 0) {
        return Fill_Board(board, row, col + 1);
    }

    for (int num = 1; num <= 9; num++) {
        if (Fillable(board, row, col, num)) {
            board[row][col] = num;

            if (Fill_Board(board, row, col + 1)) {
                return true;
            }

            board[row][col] = 0;
        }
    }
    return false;
}

// ��ʼ��9x9������
void Init_Board(int board[9][9])
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            board[row][col] = 0;
        }
    }
}

// ����ڶ�
void Dig(int board[9][9], int num_holes)
{
    srand(time(0));
    for (int i = 0; i < num_holes;) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (board[row][col] != 0) {
            board[row][col] = 0;
            i++;
        }
    }
}

// ��ӡ����
void print_board(int board[9][9])
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0)
                printf(". ");
            else
                printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

void Generate_XSudoku_And_Answer(int board[9][9], int given, int board_answer[9][9])
{
    Init_Board(board_answer);

    // ��һ���������1-9������
    int first_row[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Shuffle(first_row, 9);

    // ��������еĵ�һ����������
    for (int col = 0; col < 9; col++) {
        board_answer[0][col] = first_row[col];
    }

    // ʹ�û��ݷ�����ʣ������
    Fill_Board(board_answer, 0, 9);

    // ����
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            board[row][col] = board_answer[row][col];
        }
    }
    
    // ����ڶ�
    int num_holes = 9 * 9 - given; // 40����λ
    Dig(board, num_holes);

}
