// 利用 Bresenham算法画直线段。
#include<GLUT/GLUT.h>
#include "iostream"
#include <cmath>
using namespace std;

void myInit_bre_line(void)

{
    
    glClearColor(1.0,1.0,1.0,0.0); // 设置白色背景
    
    //glColor3f(1.0f,0.0f,0.0f);  // 设置绘图颜色
    
    glPointSize(2.0); // 点的像素大小。
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    gluOrtho2D(-30,30,-40,40);//从原点坐标开始算起：向右横向0到300米，向上纵向0到400米。当参数取负值时，可以改变原点坐标。
    
}



class bresenham_line{
public:
    int x1,y1,x2,y2;
}Bre_line;
void DrawBresenhamline()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    int dx,dy;
    int x,y,p;
    int const1,const2;
    int inc;
    int tmp;
    dx = Bre_line.x2-Bre_line.x1;
    dy = Bre_line.y2-Bre_line.y1;
    if (dx * dy >= 0)   //准备 x 或者 y 的单位递变值
        inc = 1;
    else
        inc = -1;
    if(abs(dx)>abs(dy)){
        if(dx<0){
            tmp = Bre_line.x1;//将2a，3a 象限方向上的直线变换到1a，4a方向上去。
            Bre_line.x1=Bre_line.x2;
            Bre_line.x2=tmp;
            tmp = Bre_line.y1;
            Bre_line.y1 = Bre_line.y2;
            Bre_line.y2=tmp;
            dx = -dx;
            dy = -dy;
        }
        p = 2*dy - dx;
        const1 = 2*dy;      //注意此时误差的变化参数取值
        const2 = 2 * (dy - dx);
        x = Bre_line.x1;
        y = Bre_line.y1;
        glVertex2i(x, y);
        glColor3f(1.0f,0.0f,0.0f);
        
        cout<<x<<"   "<<y<<endl;
        while(x<Bre_line.x2){
            x++;
            if(p<0)
                p+=const1;
            else{
                y += inc;
                p += const2;
            }
            glVertex2i(x, y);
            glColor3f(1.0f,0.0f,0.0f);
            
            cout<<x<<"   "<<y<<endl;
        }
    }
    else{
        if (dy<0){
            tmp = Bre_line.x1;//将3b,4b 象限方向上的直线变换到2b,1b方向上去。
            Bre_line.x1=Bre_line.x2;
            Bre_line.x2=tmp;
            tmp = Bre_line.y1;
            Bre_line.y1 = Bre_line.y2;
            Bre_line.y2=tmp;
            dx = -dx;
            dy = -dy;
        }
        p= 2*dx-dy;
        const1= 2 * dx;
        const2=2*(dx-dy);
        x = Bre_line.x1;
        y = Bre_line.y1;
        glVertex2i(x, y);
        glColor3f(1.0f,0.0f,0.0f);
        
        cout<<x<<"   "<<y<<endl;
        while(y < Bre_line.y2){
            y++;
            if(p<0)
                p+=const1;
            else{
                x += inc;
                p += const2;
            }
            glVertex2i(x, y);
            glColor3f(1.0f,0.0f,0.0f);
            
            cout<<x<<"   "<<y<<endl;
        }
    }
    
    
    
    
    int Axis_x=-30,Axis_y=-40;  //坐标轴
    for (;Axis_x<=30;Axis_x++){
        glVertex2i(Axis_x, 0);
        glColor3f(0.0f,0.0f,1.0f);
        
        
    }
    for(;Axis_y<40;Axis_y++){
        glVertex2i(0, Axis_y);
        glColor3f(0.0f,0.0f,1.0f);
        
    }
    
    glEnd();
    glFlush();
}

int b_o_l(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 设置显示模式
    
    glutInitWindowSize(500,500); // 设置窗口尺寸
    
    glutInitWindowPosition(100,100); // 设置窗口在屏幕上的位置
    glutCreateWindow("DrawBresenhamline");
    cout<<"input x1:";cin>>Bre_line.x1;
    cout<<"input y1:";cin>>Bre_line.y1;
    cout<<"input x2:";cin>>Bre_line.x2;
    cout<<"input y2:";cin>>Bre_line.y2;
    
    myInit_bre_line();
    cout<<"x"<<"   y"<<endl;
    glutDisplayFunc(DrawBresenhamline);
    glutMainLoop();
    return 0;
}


