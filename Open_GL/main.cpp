#include "dda.h"
#include "Bresenham_optimization_line.h"
#include "national_flag.h"
#include "circle.h"
#include "iostream"
using namespace std;
int main(int argc, char ** argv){
    while (1) {
        int choice;
        cout<<"1 dda"<<endl<<"2 Bresenham_optimization_line"<<endl<<"3 national_flag"<<endl<<"4 circle"<<endl<<endl<<"input the directive：";
        cin>>choice;
        switch (choice) {
            case 1:
                dda1(argc, argv);
                break;
            case 2:
                b_o_l(argc, argv);
                break;
            case 3:
                national_flag1(argc,argv);
                break;
            case 4:
                circle_1(argc, argv);
                break;
            default:
                break;
        }
    }
    
    return 0;
    
}
