#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
struct Points {
    float x;
    float y;
};
float RandmonNewX(Points points[100], int n) { 
    float maxX = points[0].x;             //funkcja szukająca największe wspólrzędne x z podanych punktów
    for (int i = 0; i < n; i++) {
        if (points[i].x > maxX) maxX = points[i].x;
    }
    float newX = maxX + 1;              //wartosc x nowego punktu 
    return newX;
}
float RandomNewY(Points points[100], int n) {
    float maxY = points[0].y;              //funkcja szukająca największe wspólrzędne y z podanych punktów
    for (int i = 0; i < n; i++) {
        if (points[i].y > maxY) maxY = points[i].y;
    }
    float newY = maxY + 1;               //wartosc x nowego punktu 
    return newY;
}

int main()
{
    fstream myFile;
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    Points points[100];
    myFile.open(filename, ios::in);

    if (!myFile.is_open()) {
        cout << "Unable to open file." << endl;
        return 1; 
    }
   
    int n;
    myFile >> n;

    for (int i = 0; i < n; i++) {
        myFile >> points[i].x >> points[i].y;
    }
    myFile.close();
    float Y=RandomNewY(points, n);
    float X=RandmonNewX(points, n);
    
    float lenght[100];
    float longestDistance = 0;
    int index=0;
    for (int i=0; i < n; i++) {
        lenght[i] = sqrt(pow(X - points[i].x, 2) + pow(Y - points[i].y, 2));
        if (lenght[i] > longestDistance) {
            longestDistance = lenght[i];
            index = i;
            
        }
        
    }
    cout << "[(" << points[index].x << ", " << points[index].y << ")";
    
    for (int j = 0; j < n; j++) {
        if (j != index) {
        if (points[index].y - points[j].y != 0) { //warunek, aby uniknąć dzielenia przez zero
            float a = (points[index].x - points[j].x) / (points[index].y - points[j].y);
            int rep = 0;
            for (int k = 0; k < n; k++) {
                 

                    if (points[k].y >= a * (points[index].x - points[j].x) + points[j].y) {
                        rep++;
                    }
                
            }
                if (rep == n || rep == 0) {
                    cout << "(" << points[j].x << ", " << points[j].y << ")";
                }
                rep = 0;
            }
        }
        
    }
    cout << "]" << endl;
    return 0;
}