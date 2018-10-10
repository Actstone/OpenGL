//利用 DDA算法画出直线段。
#include<GLUT/GLUT.h>
#include "iostream"
#include <cmath>
#include <unistd.h>
using namespace std;

void myInit_dda(void)

{
    
    glClearColor(1.0,1.0,1.0,0.0); // 设置白色背景
    
    glColor3f(1.0f,0.0f,0.0f);  // 设置绘图颜色
    
    glPointSize(2.0); // 点的像素大小。
    
    glMatrixMode(GL_PROJECTION);
    
    //glLoadIdentity();
    
    gluOrtho2D(-30,30,-40,40);//从原点坐标开始算起：向右横向0到300米，向上纵向0到400米。当参数取负值时，可以改变原点坐标。
    
}

class DDA{
public:
    int xa,ya,xb,yb;
}dda;
void mymouse(int x,int y){//        得到鼠标的轨迹
    cout<<"x: "<<x<<", y:"<<y<<endl;
}


void lineDDA(){         //DDA 算法
    
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    int Axis_x=-30,Axis_y=-40;  //坐标轴
    for (;Axis_x<=30;Axis_x++){
        glVertex2i(Axis_x, 0);
        glColor3f(0.0f,0.0f,1.0f);
        
        
    }
    for(;Axis_y<40;Axis_y++){
        glVertex2i(0, Axis_y);
        glColor3f(0.0f,0.0f,1.0f);
        
    }
    
    int dx,dy,n,k;
    float x,y;
    float xinc, yinc;
    dx=dda.xb-dda.xa;
    dy=dda.yb-dda.ya;
    
    if (abs(dx)>abs(dy))
        n = abs(dx);
    else
        n = abs(dy);
    
    xinc = (float)dx/n;
    yinc = (float)dy/n;
    
    x = float(dda.xa);y = float(dda.ya);
    
    for(k=1;k<=n;k++){
        glVertex2i(int(x), int(y));
        cout<<int(x)<<"  "<<int(y)<<endl;
        glColor3f(1.0f,0.0f,0.0f);
        x += xinc;
        y += yinc;
    }
    glEnd();
    glFlush();
}


int dda1(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 设置显示模式
    
    glutInitWindowSize(500,500); // 设置窗口尺寸
    
    glutInitWindowPosition(100,100); // 设置窗口在屏幕上的位置
    glutCreateWindow("DDA");
    cout<<"input xa:";cin>>dda.xa;
    cout<<"input ya:";cin>>dda.ya;
    cout<<"input xb:";cin>>dda.xb;
    cout<<"input yb:";cin>>dda.yb;
    myInit_dda();
    glutDisplayFunc(lineDDA);
    glutMainLoop();
    return(0);
}

