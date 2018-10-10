#include <GLUT/glut.h>
#include "iostream"
using namespace std;
void myInit(void)

{
    glClearColor(1.0,1.0,1.0,0.0); // 设置白色背景
    glPointSize(0.1); // 点的像素大小。
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-30,30,-40,40);//从原点坐标开始算起：向右横向0到300米，向上纵向0到400米。当参数取负值时，可以改变原点坐标。
}


//大五角星的中心位于该长方形上5下5、左5右10之处。大五角星外接圆的直径为6单位长度。
//四颗小五角星的中心点，第一颗位于上2下8、左10右5，第二颗位于上4下6、左12右3，第三颗位于上7下3、左12右3，第四颗位于上9下1、左10右5之处。
//每颗小五角星外接圆的直径均为2单位长度。四颗小五角星均有一角尖正对大五角星的中心点。


void national_flag(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    
    for(int i=-30;i<30;i++){//坐标轴
        glVertex2i(i, 0);
        glColor3f(0.0f, 0.0f, 1.0f);
    }
    for(int j=-40;j<40;j++){
        glVertex2i(0, j);
        glColor3f(0.0f, 0.0f, 1.0f);
    }
    
    for (float i=-15.0;i<=15.0;i=i+0.1){
        for(float j=-10.0;j<=10.0;j=j+0.1){
            glVertex2f(i, j);
            glColor3f(255.0f,0.0f,0.0f);//设置绘图颜色
        }
    }
    {// 最大的五角星
        for (float i=-13;i<=-7;i+=0.1){ //勾画出最大的五角星的五条边
            
            glVertex2f(i, 6);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        
        for (float i=-12;i<=-10;i+=0.1){
            glVertex2f(i, 2.5*i+33);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-10;i<=-8;i+=0.1){
            glVertex2f(i, -2.5*i-17);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-13;i<=-8;i+=0.1){
            glVertex2f(i, -0.6*i-1.8);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-12;i<=-7;i+=0.1){
            glVertex2f(i, 0.6*i+10.2);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for(float y_1 =3;y_1<=6;y_1+=0.1){      //填充第二，三条边之间空间
            float x_1=(y_1-33)/2.5;
            float x_2 =(y_1-10.2)/0.6;
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.1){
                glVertex2f(item_1, y_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
            
        }
        
        for(float y_1 =3;y_1<=6;y_1+=0.1){      //填充第四，五条边之间空间
            float x_1=(y_1+1.8)/(-0.6);
            float x_2 =(y_1+17)/(-2.5);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.1){
                glVertex2f(item_1, y_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
        
        for(float y_1 =6;y_1<=8;y_1+=0.1){      //填充第三，四条边之间的空间，但是和前两次不同的是，y 的初始值从6开始，到8
            float x_1=(y_1-33)/2.5;
            float x_2 =(y_1+17)/(-2.5);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.1){
                glVertex2f(item_1, y_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
    }
    
    {//右边的第一个小五角星。
        for (float i=-5.8;i<=-4;i+=0.1){ //构画五条边
            glVertex2f(i, (-0.7/1.8)*i+8-2.8/1.8);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-6;i<=-4;i+=0.1){
            glVertex2f(i, 0.25*i+9);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-6;i<=-4.6;i+=0.1){
            glVertex2f(i, 1.07143*i+13.9286);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-4.9;i<=-4.6;i+=0.1){
            glVertex2f(i, 6.66667*i+39.6667);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-5.8;i<=-4.9;i+=0.1){
            glVertex2f(i, -1.88889*i-2.25556);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        
        for(float b_1 =4.77273;b_1<=8-2.8/1.8;b_1+=0.01){      //填充第二，三条边之间空间
            float x_1=(b_1-13.9286)/(1.07143+0.7/1.8);
            float x_2 =(b_1-9)/(0.25+0.7/1.8);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.01){
                glVertex2f(item_1, (-0.7/1.8)*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
        for(float b_1 =4.77273;b_1<=8-2.8/1.8;b_1+=0.01){      //填充第四，五条边之间空间
            float x_1=(b_1+2.25556)/(-1.88889+0.7/1.8);
            float x_2 =(b_1-39.6667)/(6.66667+0.7/1.8);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.1){
                glVertex2f(item_1, (-0.7/1.8)*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
        
        for(float b_1 =8-2.8/1.8;b_1<=7.21111;b_1+=0.01){      //填充第三，四条边之间空间，
            float x_1=(b_1-13.9286)/(1.07143+0.7/1.8);
            float x_2 =(b_1-39.6667)/(6.66667+0.7/1.8);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.1){
                glVertex2f(item_1, (-0.7/1.8)*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
    }
    
    {//右边第二个五角星
        for (float i=-4;i<=-2.3;i+=0.1){ //构画五条边
            glVertex2f(i, 0.470588*i+7.78235);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-3.1;i<=-2.3;i+=0.1){ //构画五条边
            glVertex2f(i, 2.125*i+11.5875);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-3.4;i<=-3.1;i+=0.1){ //构画五条边
            glVertex2f(i, -6.66667*i-15.6667);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-3.4;i<=-2;i+=0.1){ //构画五条边
            glVertex2f(i, -i+3.6);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-4;i<=-2;i+=0.1){ //构画五条边
            glVertex2f(i, -0.15*i+5.3);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        
        for(float b_1 =6.69091;b_1<=7.78235;b_1+=0.01){      //填充第二，三条边之间空间
            float x_1=(b_1+15.6667)/(-6.66667-0.470588);
            float x_2 =(b_1-11.5875)/(2.125-0.470588);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.01){
                glVertex2f(item_1, 0.470588*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
        for(float b_1 =6.69091;b_1<=7.78235;b_1+=0.01){      //填充第四，五条边之间空间
            float x_1=(b_1-5.3)/(-0.15-0.470588);
            float x_2 =(b_1-3.6)/(-1-0.470588);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.01){
                glVertex2f(item_1, 0.470588*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
        for(float b_1 =7.78235;b_1<=8.5999992;b_1+=0.01){      //填充第三，四条边之间空间
            float x_1=(b_1+15.6667)/(-6.66667-0.470588);
            float x_2 =(b_1-3.6)/(-1-0.470588);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.01){
                glVertex2f(item_1, 0.470588*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
    }
    
    {//右边第三个五角星
        for (float i=-4;i<=-2;i+=0.1){ //构画五条边
            glVertex2f(i, 0.05*i+3.4);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-3.5;i<=-2;i+=0.1){ //构画五条边
            glVertex2f(i, 0.8*i+4.9);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-3.5;i<=-3;i+=0.1){ //构画五条边
            glVertex2f(i, 3.8*i+15.4);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-3;i<=-2.4;i+=0.1){ //构画五条边
            glVertex2f(i, -3*i-5);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-4;i<=-2.4;i+=0.1){ //构画五条边
            glVertex2f(i, -0.625*i+0.7);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for(float b_1 =2.41818;b_1<=3.4;b_1+=0.01){      //填充第二，三条边之间空间
            float x_1=(b_1-15.4)/(3.8-0.05);
            float x_2 =(b_1-4.9)/(0.8-0.05);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.01){
                glVertex2f(item_1, 0.05*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
        for(float b_1 =2.41818;b_1<=3.4;b_1+=0.01){      //填充第四，五条边之间空间
            float x_1=(b_1-0.7)/(-0.625-0.05);
            float x_2 =(b_1+5)/(-3-0.05);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.01){
                glVertex2f(item_1, 0.05*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
        for(float b_1 =3.4;b_1<=4.15;b_1+=0.01){      //填充第三，四条边之间空间
            float x_1=(b_1-15.4)/(3.8-0.05);
            float x_2 =(b_1+5)/(-3-0.05);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.01){
                glVertex2f(item_1, 0.05*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
    }
    {//右边第四个五角星
        for (float i=-5.8;i<=-4;i+=0.1){ //构画五条边
            glVertex2f(i, -0.333333*i-0.333333);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-5.9;i<=-4;i+=0.1){ //构画五条边
            glVertex2f(i, 0.210526*i+1.84211);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-5.9;i<=-4.8;i+=0.1){ //构画五条边
            glVertex2f(i, 1.27273*i+8.10909);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-4.9;i<=-4.8;i+=0.1){ //构画五条边
            glVertex2f(i, 20*i+98);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for (float i=-5.8;i<=-4.9;i+=0.1){ //构画五条边
            glVertex2f(i, -1.77778*i-8.71111);
            glColor3f(255.0f, 255.0f, 0.0f);
        }
        for(float b_1 =-2.94;b_1<=-0.333333;b_1+=0.01){      //填充第二，三条边之间空间
            float x_1=(b_1-8.10909)/(1.27273+0.333333);
            float x_2 =(b_1-1.84211)/(0.210526+0.333333);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.01){
                glVertex2f(item_1, -0.333333*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
        for(float b_1 =-2.94;b_1<=-0.333333;b_1+=0.01){      //填充第四，五条边之间空间
            float x_1=(b_1+8.71111)/(-1.77778+0.333333);
            float x_2 =(b_1-98)/(20+0.333333);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.01){
                glVertex2f(item_1, -0.333333*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
        for(float b_1 =-0.333333;b_1<=0.4000016;b_1+=0.01){      //填充第三，四条边之间空间
            float x_1=(b_1-8.10909)/(1.27273+0.333333);
            float x_2 =(b_1-98)/(20+0.333333);
            for(float item_1 = x_1;item_1<=x_2;item_1+=0.01){
                glVertex2f(item_1, -0.333333*item_1+b_1);
                glColor3f(255.0f, 255.0f, 0.0f);
            }
        }
    }
    
    
    
    
    
    
    
    // for(float a)
    
    glEnd();
    glFlush();
}

void national_flag1(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 设置显示模式
    glutInitWindowSize(500,500); // 设置窗口尺寸
    glutInitWindowPosition(100,100); // 设置窗口在屏幕上的位置
    glutCreateWindow("national_flag");
    
    glutDisplayFunc(national_flag);
    myInit();
    glutMainLoop();
}


