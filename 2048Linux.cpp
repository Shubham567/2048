#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
//#include <conio.h>




#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


using namespace std;



struct Index{
    int x;
    int y;
};

class CoreMatrix{
    int **mat;
    int matLen;
    Index *emptyIndex;
    int countEmptyIndex;
    long score;
    vector <Index> generatedElements;
    public:
        CoreMatrix(const int n){
            srand(time(NULL));
            score = 0;
            matLen = n;
            mat = new int*[n];
            for(int i = 0; i < n; i++){
                mat[i] = new int[n];
            }
            for(int i = 0; i < matLen;i++){
                for(int j = 0; j < matLen;j++){
                    mat[i][j] = 0;
                }
            }
            emptyIndex = new Index[n*n];
            countEmptyIndex = n*n;
            findEmptySpaces();
        }
        
        bool isNewElement(int x, int y){
            bool found = false;
            for(int i = 0; i < generatedElements.size();i++){
                if(generatedElements[i].x == x && generatedElements[i].y == y){
                    found = true;
                    break;
                }
            }
            return found;
        }
        
        void printMatrix(string msg = ""){
            if(msg.size() > 0)
                cout<<endl<<msg<<endl<<endl;
            
            for(int i = 0; i < matLen*7 - 12/matLen;i++){
                cout<<"-";
            }
            cout<<endl;
            for(int i = 0; i < matLen ; i++){
                for(int j = 0; j < matLen;j++){
                            cout<<mat[i][j]<<"\t";

                }
                cout<<endl;
            }
            
            for(int i = 0; i < matLen*7 - 12/matLen;i++){
                cout<<"_";
            }
            cout<<endl;

            generatedElements.clear();
        }


        int genRandom(){
            int n = matLen;
            int m = (n+1)/2;
            vector <int> r;
            if(n & 1){
                for(int i = 1; i <= m + 1; i++)
                {
                    r.push_back(pow(2,i));
                }
            }
            else{
                for(int i = 1; i <= m; i++)
                {
                    r.push_back(pow(2,i));
                }
            }
            int t = r.size();
            int p = (t*(t+1))/2;
            int x = rand()%p+1;


            int pSum = 0;
            int index = 0;

            for(int i = t;i > 0; i--){
                pSum += i;
                float u = (float)x/(float)pSum;
                if(u > 0 && u <= 1){
                    index = t - i;
                    break;
                }
            }
            return r[index];
        }


        bool randomSpawning(){
            findEmptySpaces();
            Index newElement;
            if(countEmptyIndex > 0){
                int pos = rand()%countEmptyIndex;
                mat[emptyIndex[pos].x][emptyIndex[pos].y] = genRandom();
                newElement.x = emptyIndex[pos].x;
                newElement.y = emptyIndex[pos].y;
                generatedElements.push_back(newElement);
                return true;
            }
            else{
                return false;
            }
        }
        
        void findEmptySpaces(){
            int c = 0;
            for(int i = 0; i < matLen; i++){
                for(int j = 0;  j < matLen; j++){
                    if(mat[i][j] == 0){
                        emptyIndex[c].x = i;
                        emptyIndex[c++].y = j;
                    }
                }
            }
            countEmptyIndex = c;
        }
        
        void moveLeft(){
            for(int i = 0; i < matLen; i++){
                for(int j = 0; j < matLen; j++){
                    if(mat[i][j] == 0){
                        for(int k = matLen - 1; k > j; k--){
                            if(mat[i][k] != 0){
                                swap(mat[i][j],mat[i][k]);
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < matLen; i++){
                for(int j = 0; j < matLen; j++){
                    if(mat[i][j] != 0 && j+1 < matLen && mat[i][j] == mat[i][j+1]){
                        score += mat[i][j];
                        mat[i][j] = 2 * mat[i][j];
                        mat[i][j+1] = 0;

                    }
                }
            }
            for(int i = 0; i < matLen; i++){
                for(int j = 0; j < matLen; j++){
                    if(mat[i][j] == 0){
                        for(int k = matLen - 1; k > j; k--){
                            if(mat[i][k] != 0){
                                swap(mat[i][j],mat[i][k]);
                            }
                        }
                    }
                }
            }

        }

        void moveRight(){
            for(int i = 0; i < matLen; i++){
                for(int j = matLen - 1; j >= 0; j--){
                    if(mat[i][j] == 0){
                        for(int k = j - 1; k >= 0; k--){
                            if(mat[i][k] != 0){
                                swap(mat[i][j],mat[i][k]);
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < matLen; i++){
                for(int j = matLen - 1; j >= 0; j--){
                    if(mat[i][j] != 0 && j-1 >= 0 && mat[i][j] == mat[i][j-1]){
                        score += mat[i][j];
                        mat[i][j] *= 2 ;
                        mat[i][j-1] = 0;

                    }
                }
            }
            for(int i = 0; i < matLen; i++){
                for(int j = matLen - 1; j >= 0; j--){
                    if(mat[i][j] == 0){
                        for(int k = j - 1; k >= 0; k--){
                            if(mat[i][k] != 0){
                                swap(mat[i][j],mat[i][k]);
                            }
                        }
                    }
                }
            }

        }
        
        void moveUp(){
            for(int i = 0; i < matLen; i++){
                for(int j = 0; j < matLen; j++){
                    if(mat[j][i] == 0){
                        for(int k = matLen - 1; k > j; k--){
                            if(mat[k][i] != 0){
                                swap(mat[j][i],mat[k][i]);
                            }
                        }SetConsoleTextAttribute(hConsole, 12);
                    }
                }
            }
            for(int i = 0; i < matLen; i++){
                for(int j = 0; j < matLen; j++){
                    if(mat[j][i] != 0 && j+1 < matLen && mat[j][i] == mat[j+1][i]){
                        score += mat[j][i];
                        mat[j][i] = 2 * mat[j][i];
                        mat[j+1][i] = 0;
                    }
                }
            }
            for(int i = 0; i < matLen; i++){
                for(int j = 0; j < matLen; j++){
                    if(mat[j][i] == 0){
                        for(int k = matLen - 1; k > j; k--){
                            if(mat[k][i] != 0){
                                swap(mat[j][i],mat[k][i]);
                            }
                        }
                    }
                }
            }
        }
        
        void moveDown(){
            for(int i = 0; i < matLen; i++){
                for(int j = matLen - 1; j >= 0; j--){
                    if(mat[j][i] == 0){
                        for(int k = j - 1; k >= 0; k--){
                            if(mat[k][i] != 0){
                                swap(mat[j][i],mat[k][i]);
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < matLen; i++){
                for(int j = matLen - 1; j >= 0; j--){
                    if(mat[j][i] != 0 && j-1 >= 0 && mat[j][i] == mat[j-1][i]){
                        score += mat[j][i];
                        mat[j][i] *= 2 ;
                        mat[j-1][i] = 0;

                    }
                }
            }
            for(int i = 0; i < matLen; i++){
                for(int j = matLen - 1; j >= 0; j--){
                    if(mat[j][i] == 0){
                        for(int k = j - 1; k >= 0; k--){
                            if(mat[k][i] != 0){
                                swap(mat[j][i],mat[k][i]);
                            }
                        }
                    }
                }
            }
        }

        long getScore(){
            return score;
        }

};
int main(){


    

    cout<<"Enter Game Size (n x n):";
    int n = 4;
    cin>>n;
    if(n < 2){
        cout<<"\nInvalid input. Minimum 2 x 2.\n\n";
        return 1;
    }

    CoreMatrix m(n);
    system("clear");
    cout<<"\t\t2048\n\t    Game Begins";
    cout<<"\n\nPress arrow buttons to play.\nPress 0 to exit.\n\n";
    char res = 1;

    m.randomSpawning();
    bool validMove = true;
    while(res != '0'){
        if(validMove){
            if(m.randomSpawning()){
                m.printMatrix("\t2048");
             }
            else{
                cout<<":)";
                system("clear");
                m.printMatrix("\tGame Over");
                cout<<"\n\tYour Score : "<<m.getScore()<<endl;
                break;
            }
        }
        else{
            m.printMatrix("2048");
            cout<<"Invalid OutPut! Valid Options are arrow keys. 0 to Exit.\n";
        }
        res = getch();
        validMove = false;
        if(res == KEY_UP){
            m.moveUp();
            validMove = true;
        }
        else if(res == KEY_LEFT){
            m.moveLeft();
            validMove = true;
        }
        else if(res == KEY_DOWN){
            m.moveDown();
            validMove = true;
        }
        else if(res == KEY_RIGHT){
            m.moveRight();
            validMove = true;
        }
        system("clear");

    }
    if(res == 0){
        cout<<":)";
        system("clear");
    }
    cout<<"\n\n\t<3 Thanks For Playing - - - S S 7 <3\n\n\n";
    return 0;

}
