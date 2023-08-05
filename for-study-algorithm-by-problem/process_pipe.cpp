#include <iostream>
#include <string>
using namespace std;

FILE *pipe;
string input_buffer, out_buffer_1, out_buffer_2;
char cBuffer[100];





void makeTC()
{
    input_buffer.clear();

    int N = rand() % 17 + 2;

    input_buffer = to_string(N) + "\n"; 

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            input_buffer += to_string(rand() % 2) + " ";
        }
        input_buffer += "\n";
    }
}


int main()
{
    int T = 0;

    while(1)
    {
        cout << "T = " << T << endl;

        makeTC();

        // char* charBuffer = new char[buffer.length() + 1];
        // strcpy(charBuffer, buffer.c_str());
        
        cout << input_buffer;
        pipe = popen("./b.out", "r+");
        

        fputs(input_buffer.c_str(), pipe);

        out_buffer_1.clear();
        out_buffer_2.clear();

        while(fgets(cBuffer, sizeof(cBuffer), pipe) != NULL){
            out_buffer_1 += cBuffer;
        }

        cout << out_buffer_1 << endl;

        pclose(pipe);


        // int right, wrong;
        // right = codeA();
        // wrong = codeD();
        // if (right != wrong) 
        // {
        //     // printf("%d %d %d \n", A, B, C);
        //     printf("%d\n", N);
        //     for (int i = 0; i < N; ++i){
        //         for (int j = 0; j < N; ++j)
        //             cout << board[i][j] << " ";
        //         cout << "\n";
        //     }


        //     cout << "right Ans = " << right << endl;
        //     cout << "wrong Ans = " << wrong << endl;
        //     cout << "======================" << endl;
        //     break;
        // }
        T++;
        // if(T%10000 == 0) cout << "T = " << T << endl;
    }
}