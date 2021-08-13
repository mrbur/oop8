#include <iostream>
#include "functions.h"
#include "classes.h"
#include "robot.h"

using namespace std;

int main()
{
    //1 task
    {
        try {
            float floatResult = divNumbers(1.2, 2.7);
            int intResult = divNumbers(6, 0);
            floatResult = divNumbers(56.7, 2.7);
        }
        catch (DivisionByZero e) {
            cout << e.getExceptionText();
        }
    }

    //2 task
    {
        Bar bar;
        float x = 1;
        cout << endl << endl;
        while (x != 0) {
            cout << "Insert number" << endl;
            cin >> x;
            try {
                bar.set(x);
            }
            catch (Ex e) {
                cout << "Error " << e.getText();
            }
        }
        
    }

    //3 task 
    {
        Robot robot;
        string command;
        cout << endl << endl;
        
        try {
            while (command != "q") {
                cout << "Insert command" << endl;
                cin >> command;
                if (command == "l") {
                    robot.move(-1, 0);
                }
                else if (command == "r") {
                    robot.move(1, 0);
                }
                else if (command == "u") {
                    robot.move(0, 1);
                }
                else if (command == "d") {
                    robot.move(0, -1);
                }
                else {
                    throw IllegalCommand(robot.getX(), robot.getY());
                }
            }
        }
        catch (IllegalCommand e) {
            cout << "Error " << e.getEx();
        }
        catch (OffTheField e) {
            cout << "Error " << e.getEx();
        }
    }
}
