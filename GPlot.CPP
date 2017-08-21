#include<fstream.h>
#include<graphics.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<math.h>

#define PI 3.14159265
#define RADIANS(x) (x*(PI/180))
#define DEGREES(x) (x*(180/PI))
#define X0 (getmaxx()/2)
#define Y0 (getmaxy()/2)
#define X(x) (X0+(x))
#define Y(y) (Y0-(y))
#define x_left_border()  (-1*getmaxx()/2+10)
#define x_right_border() (getmaxx()/2-10)

int i;
fstream x;
char ename[30], epass[30];

void access();   //Verify user
void menu();     //User Menu
void modify();   //Modify User details
int Delete();    //Delete account
void Register(); //Register new account
void list();     //Display list of all graphs in database
void search();   //Search a graph from database
void welcome();  //Welcome screen
void load();     //Loading Screen
void drawaxis(); //For making x and y axis

class graphs     //Graphs database
{
char gname[30];  //Graph name
int code;        //Graph code
int noviews;     //Number of views of graph
public:
void graphinfo();//Enter Graph Information
void displayg(); //Display Graph information
void viewg();    //View the respect graph
void mod();      //Modulus
void tangent();
void sine();
void cosine();
void cosecant();
void secant();
void cotangent();
void logs();
void xy();
void circle();
void exps();
void ell();
int checkcode();
char*checkname();
}g;

//Class Graphs-Function Definitions
void graphs::mod()
{
int gd = DETECT, gm, error;
  int i,j,x,y;
  char no[]={"1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16"};
  char*p=no;

  initgraph(&gd,&gm,"D:\\TC\\BGI");
  settextstyle(2,0,0);
  for(i=320;i<600;i+=300)
  {
  outtextxy(i+10,getmaxy()/2,p);
  }

  drawaxis();

  setcolor(14);
  line(320,getmaxy()/2,220,0);

  setcolor(10);
  line(320,getmaxy()/2,400,0);

  getch();
  }

void graphs::cosine()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
float x,y,xpos;
int m;
drawaxis();
getch();
int margin = 50;
int height = getmaxy()-margin;
int width  = getmaxx()-margin;
int freq   = 2;
char buf[20];
for (x = x_left_border(); x < x_right_border(); x += 0.1)
 {
  delay(1);
  y = 50 * cos(RADIANS(2*x));
  xpos = x / 720.0 * width + margin / 2;
  putpixel(X(x), Y(y), 15);

    m = x;

    if( (m % 90) == 0.0)

	  {

	    line(X0+x, margin / 2 + height / 2 - 5,

		  X0+x, margin / 2 + height / 2 + 5);

	    sprintf(buf, "%d", m);

	    outtextxy(X0+x - 10, margin / 2 + height / 2 + 10, buf);

	  }

      }

getch();

}

void graphs::sine()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
float x,y,xpos;
int m;

drawaxis();
 getch();
 int margin = 50;
 int height = getmaxy()-margin;
 int width = getmaxx()-margin;
 int freq = 1;
 char buf[20];

 for (x = x_left_border(); x < x_right_border(); x += 0.1)
 {
  delay(1);
  y = 50 * sin(RADIANS(x*freq));

  putpixel(X(x), Y(y), 15);

    m = freq*x;

    if(m % 90 == 0)

	  {

	    line(X0+x, margin / 2 + height / 2 - 5,

		  X0+x, margin / 2 + height / 2 + 5);

	    sprintf(buf, "%d", m);

	    outtextxy((X0+x-10), margin / 2 + height / 2 + 10, buf);

	  }

      }

getch();

}

void graphs::tangent()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
float x,y,xpos;
int m;
drawaxis();
 int margin = 50;
 int height = getmaxy()-margin;
 int width = getmaxx()-margin;
 int freq = 1;
 char buf[20];

 for (x = x_left_border(); x < x_right_border(); x += 0.1)
 {
  delay(1);
  y = 50 * tan(RADIANS(x*freq));

  putpixel(X(x), Y(y), 15);

    m = freq*x;

    if(m % 90 == 0)

	  {

	    line(X0+x, margin / 2 + height / 2 - 5,

		  X0+x, margin / 2 + height / 2 + 5);

	    sprintf(buf, "%d", m);

	    outtextxy((X0+x-10), margin / 2 + height / 2 + 10, buf);

	  }

      }

getch();

}

void graphs::secant()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
float x,y,xpos;
int m;

 drawaxis();
 getch();
 int margin = 50;
 int height = getmaxy()-margin;
 int width = getmaxx()-margin;
 int freq = 1;
 char buf[20];

 for (x = x_left_border(); x < x_right_border(); x += 0.1)
 {
  delay(1);
  y = 50 * 1/cos(RADIANS(x*freq));

  putpixel(X(x), Y(y), 15);

    m = freq*x;

    if(m % 90 == 0)

	  {

	    line(X0+x, margin / 2 + height / 2 - 5,

		  X0+x, margin / 2 + height / 2 + 5);

	    sprintf(buf, "%d", m);

	    outtextxy((X0+x-10), margin / 2 + height / 2 + 10, buf);

	  }

      }

getch();

}

void graphs::cosecant()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
float x,y,xpos;
int m;

 drawaxis();
 getch();
 int margin = 50;
 int height = getmaxy()-margin;
 int width = getmaxx()-margin;
 int freq = 1;
 char buf[20];

 for (x = x_left_border(); x < x_right_border(); x += 0.1)
 {
  delay(1);
  y = 50 * 1/sin(RADIANS(x*freq));

  putpixel(X(x), Y(y), 15);

    m = freq*x;

    if(m % 90 == 0)

	  {

	    line(X0+x, margin / 2 + height / 2 - 5,

		  X0+x, margin / 2 + height / 2 + 5);

	    sprintf(buf, "%d", m);

	    outtextxy((X0+x-10), margin / 2 + height / 2 + 10, buf);

	  }

      }

getch();

}

void graphs::cotangent()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
float x,y,xpos;
int m;

 drawaxis();
 getch();
 int margin = 50;
 int height = getmaxy()-margin;
 int width = getmaxx()-margin;
 int freq = 1;
 char buf[20];

 for (x = x_left_border(); x < x_right_border(); x += 0.1)
 {
  delay(1);
  y = 50 * 1/tan(RADIANS(x*freq));

  putpixel(X(x), Y(y), 15);

    m = freq*x;

    if(m % 90 == 0)

	  {

	    line(X0+x, margin / 2 + height / 2 - 5,

		  X0+x, margin / 2 + height / 2 + 5);

	    sprintf(buf, "%d", m);

	    outtextxy((X0+x-10), margin / 2 + height / 2 + 10, buf);

	  }

      }
getch();

}


void graphs::logs()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
float x,y,xpos;
float m;
float n;

 drawaxis();
 getch();
 int margin = 50;
 int height = getmaxy()-margin;
 int width = getmaxx()-margin;
 int freq = 1;
 char buf[20];

 for (x = 0.001; x < x_right_border(); x += 0.1)
 {
  delay(1);
  y = 20 * log(x);

  putpixel(X(x), Y(y), 15);


     }
getch();

}

void graphs::exps()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
float x,y,xpos;
float m;
float n;

 drawaxis();
 getch();
 int margin = 50;
 int height = getmaxy()-margin;
 int width = getmaxx()-margin;
 int freq = 1;
 char buf[20];

 for (x =-200; x < 15; x += 0.001)
 {

  y =exp(x)/500;

  putpixel(X(x)+10, Y(y), 5);


     }
getch();

}

void graphs::ell()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
float x,y,xpos,ypos;

cout<<"Enter x and y radius :";
cin>>x>>y;
cout<<"\nEnter x and y co-ordinates :";
cin>>xpos>>ypos;
drawaxis();
setcolor(12);
x*=10;y*=10;xpos*=10;ypos*=10;
ellipse(X(xpos),Y(ypos),0,360,x,y);

getch();

}

void graphs::graphinfo()
{
gets(gname);
cout<<endl;
cin>>code;
cout<<endl;
cin>>noviews;
}

void graphs::displayg()
{
cout<<endl<<gname<<"\t  "<<code<<"\t  "<<noviews;
}

void graphs::viewg()
{
clrscr();
++noviews;
if(code==1)
mod();
if(code==2)
sine();
if(code==3)
cosine();
if(code==4)
tangent();
if(code==5)
cosecant();
if(code==6)
secant();
if(code==7)
cotangent();
if(code==8)
logs();
if(code==9)
exps();
if(code==10)
ell();
closegraph();
}

int graphs::checkcode()
{
return code;
}

char*graphs::checkname()
{
return gname;
}

class user //User Database
{
char name[30]; //Name
char pass[30]; //Password
public:
void getinfo();//get user Information
void display();//Display userInformation
void change(char[30],char[30]); //Modifying user information
int check(char[30],char[30]);   //Verification of user
}s,s1;

//Class User-Function Definitions
void user::getinfo()
{
int gd = DETECT, gm, error;
initgraph(&gd,&gm,"D:\\TC\\BGI");
setlinestyle(3,1,1);
setfillstyle(3,2);
floodfill(0,0,1);
settextstyle(3,0,1);
outtextxy(0,10,"Enter Name ");
rectangle(105,15,200,33);
gotoxy(15,2);
gets(name);
outtextxy(0,55,"Enter password ");
rectangle(137,60,210,80);
gotoxy(19,5);
i=0;
while(i<10)
{
pass[i]=getch();

if(pass[i]==8)
{
i=i-2;
if(i<-1)
i=-1;
clrscr();
initgraph(&gd,&gm,"D:\\TC\\BGI");
setlinestyle(3,1,1);
setfillstyle(3,2);
floodfill(0,0,1);
settextstyle(3,0,1);
outtextxy(0,10,"Enter Name ");
rectangle(105,15,200,33);
gotoxy(15,2);
cout<<name;
outtextxy(0,55,"Enter password ");
rectangle(137,60,210,80);
gotoxy(19,5);
for(int h=0;h<=i;h++)
{
cout<<"*";
}
}
else if(pass[i]==13)
{
pass[i]='\0';
break;
}
else
cout<<"*";
i++;
}
}

void user::display()
{
cout<<endl<<"Username :"<<name;
cout<<endl<<"Password :"<<pass;
}

void user::change(char a[30], char b[30])
{
if(strcmp(a,"."))
strcpy(name,a);
if(strcmp(b,"."))
strcpy(pass,b);
}

int user::check(char a[30],char b[30])
{
if(!strcmp(a,pass)&&!strcmp(b,name))
return 1;
else
return 0;
}

void main()
{
clrscr();
int choice='1',log='1';
x.open("info.txt", ios::out|ios::in|ios::binary);
int gd = DETECT, gm, error;

while(log!='4')
{
clrscr();
load();
welcome();
log=getch();
closegraph();

//Login Menu
if(log=='1')//Enter user details for access
{
initgraph(&gd,&gm,"D:\\TC\\BGI");
setlinestyle(3,1,1);
setfillstyle(3,1);
floodfill(0,0,1);
settextstyle(3,0,1);
outtextxy(0,10,"Enter Name ");
rectangle(105,15,200,33);
gotoxy(15,2);
gets(ename);
outtextxy(0,55,"Enter password ");
rectangle(137,60,210,80);
gotoxy(19,5);
i=0;
//password in star
while(i<10)
{
epass[i]=getch();

if(epass[i]==8)
{i=i-2;
if(i<-1)
i=-1;
clrscr();
initgraph(&gd,&gm,"D:\\TC\\BGI");
setlinestyle(3,1,1);
setfillstyle(3,1);
floodfill(0,0,1);
settextstyle(3,0,1);
outtextxy(0,10,"Enter Name ");
rectangle(105,15,200,33);
gotoxy(15,2);
cout<<ename;
outtextxy(0,55,"Enter password ");
rectangle(137,60,210,80);
gotoxy(19,5);
for(int h=0;h<=i;h++)
{cout<<"*";}
}
else if(epass[i]==13)
{
epass[i]='\0';
break;
}
else
cout<<"*";
i++;}
closegraph();
access(); //Verifies details from database
choice='0';

//User Menu
while(choice!='5')
{
menu();
choice=getch();
closegraph();
if(choice=='1') //view all graphs
list();
else if(choice=='2')//search a specific graph
search();
else if(choice=='3')//modify user details
{
modify();
getch();
closegraph();
}
else if(choice=='4')//delete account
{
if(Delete())
choice='5';
else
getch();
closegraph();
}

else if(choice=='5')//Logout and retairn to main menu
{
choice='0';
break;
}
}
}

//Registeration Menu
if(log=='2')
{
Register();
closegraph();
}

//Guest Menu
else if(log=='3')
{
graphs m; char c;
int gd = DETECT, gm, error;
initgraph(&gd,&gm,"D:\\TC\\BGI");
setbkcolor(3);
cout<<endl
    <<"You have access to the following graphs as a guest "<<endl
    <<"1.Sine"<<endl
    <<"2.Modulus"<<endl
    <<"3.Tan"<<endl;
    cout<<"Select from the above graphs"<<endl;
c=getch();
closegraph();
if(c=='1') //show sine graph
m.sine();
else if(c=='2') //show Modulus graph
m.mod();
else if(c=='3') //show tangent graph
m.tangent();
else
cout<<"Wrong option";
}
}

getch();
}

void access()
{
int found=0;
ifstream y("info.txt", ios::in|ios::binary);
y.seekg(ios::beg);

while(y.read((char*)&s, sizeof(s)))
{
if(s.check(epass,ename))
found=1;
}

if(found)
cout<<endl<<"Welcome";
else
{
cout<<endl<<"WRONG USERNAME OR PASSWORD!!! TERMINATING!";
delay(800);
exit(1);
}
}

void menu()
{
clrscr();
char *p[]={"1 -> View graph List",
	   "2 -> Search a graph",
	   "3 -> Modify Your Account settings",
	   "4 -> Delete Your Account",
	   "5 -> Logout "};
int gd = DETECT, gm, error,y;
y=getmaxy()/2-70;
initgraph(&gd,&gm,"D:\\TC\\BGI");
setcolor(10);
settextstyle(8,0,1);
setfillstyle(6,1);
floodfill(0,1,1);
for(int i=0;i<5;i++)
{
outtextxy(getmaxx()/2-150,y,p[i]);
y+=30;
}
}

void modify()
{
int gd = DETECT, gm, error;
initgraph(&gd,&gm,"D:\\TC\\BGI");
setbkcolor(6);

int pos,found=0; char newname[30], newpass[30];
fstream z("info.txt", ios::in|ios::out|ios::binary);
z.seekg(0);

while(z.read((char*)&s1, sizeof(s1)))
{
if(s1.check(epass,ename))
{
found=1;
pos=z.tellg();
cout<<endl<<"Enter new details ";
cout<<endl<<"Enter Your new username (press . to retain old one ) ";
gets(newname);
cout<<endl<<"Enter New Password ";
i=0;
while(i<10)
{
newpass[i]=getch();

if(newpass[i]==8)
{i=i-2;
if(i<-1)
i=-1;
clrscr();
cout<<"Enter password:";
for(int h=0;h<=i;h++)
{cout<<"*";}
}
else if(newpass[i]==13)
{
newpass[i]='\0';
break;
}
else
cout<<"*";
i++;}
s1.change(newname,newpass);
cout<<endl<<"New Account details are ";
s1.display();
z.seekp(pos-sizeof(s));
z.write((char*)&s1, sizeof(s1));
}
}
if(!found) cout<<"Sorry Account does not exist ";
z.close();
}

int Delete()
{
clrscr();
int gd = DETECT, gm, error;
initgraph(&gd,&gm,"D:\\TC\\BGI");
setbkcolor(4);
char ch; int confirm=0;
ofstream d("temp.txt",ios::out|ios::binary);
ifstream e("info.txt",ios::in|ios::binary);
cout<<endl<<"Are You Sure You wish to DELETE your account ?(y/n)";
cin>>ch;
e.seekg(0);
if(ch=='y')
{
while(!e.eof())
{
e.read((char*)&s1, sizeof(s1));
if(!s1.check(epass,ename))
d.write((char*)&s1, sizeof(s1));
}
d.close();
e.close();
remove("info.txt");
rename("temp.txt","info.txt");
cout<<endl<<"Record deleted successfuly ";
confirm=1;
}
else
cout<<endl<<"Press any key to return ";
return confirm;
}

void search()
{
int gd = DETECT, gm, error,sel,choice, found=0; char name[20];
initgraph(&gd,&gm,"D:\\TC\\BGI");
setbkcolor(4);
fstream m("graphinfo.txt", ios::in|ios::out|ios::binary);
int pos;
cout<<endl<<endl<<"If you wish to search by code press 1"
    <<endl<<endl<<"If you wish to search by name press 2";
cin>>choice;
if(choice==1)
{
cout<<endl<<endl<<"Enter the code of the graph you wish to view ";
cin>>sel;
closegraph();
while(m.read((char*)&g, sizeof(g)))
{
if(sel==g.checkcode())
{
found=1;
pos=m.tellg();
cout<<endl<<endl<<"The information of the graph is ";
cout<<endl<<endl<<"Name\t  Code\t  No. of Views";
g.displayg();
getch();
g.viewg();
m.seekp(pos-sizeof(g));
m.write((char*)&g, sizeof(g));
}
}
}

else if(choice==2)
{
cout<<endl<<endl<<"Enter the name of the graph you wish to search ";
gets(name);
while(m.read((char*)&g, sizeof(g)))
{
if(!strcmp(name,g.checkname()))
{
found=1;
pos=m.tellg();
cout<<endl<<endl<<"The information of the graph is ";
cout<<endl<<endl<<"Name\t  Code\t  No. of Views";
g.displayg();
getch();
g.viewg();
m.seekp(pos-sizeof(g));
m.write((char*)&g, sizeof(g));
}
}
}
if(!found)
{
cout<<"No graph exists";
getch();
}
}

void welcome()
{
int gd = DETECT, gm, error;
initgraph(&gd,&gm,"D:\\TC\\BGI");
setfillstyle(10,9);
floodfill(2,2,1);
settextstyle(7,1,0);
outtextxy(200,getmaxy()/2,"* * * *");
settextstyle(7,0,-4);
outtextxy(180,getmaxy()/2-40,"{");
outtextxy(450,getmaxy()/2-40,"}");
settextstyle(3,0,0);
outtextxy(250,getmaxy()/2-60,"WELCOME");
settextstyle(6,0,1);
outtextxy(225,getmaxy()/2-5,"Already a member? Press 1");
outtextxy(225,getmaxy()/2+23,"For sign up press 2");
outtextxy(225,getmaxy()/2+50,"Browse as a guest? Press 3");
outtextxy(225,getmaxy()/2+80,"Exit? Press 4");
settextstyle(7,0,-4);
for(int i=0;i<=15;i++)
{
setcolor(i);
outtextxy(20,2,"+");
outtextxy(480,2,"%");
outtextxy(20,300,"x");
outtextxy(500,300,"e");
delay(50);
}
}

void Register()
{
clrscr();
fstream a("info.txt",ios::in|ios::out|ios::binary|ios::app);
s.getinfo();
a.write((char*)&s, sizeof(s));
a.close();
}

void list()
{
clrscr(); int sel;
fstream c("graphinfo.txt", ios::in|ios::out|ios::binary);
int gd = DETECT, gm, error;
initgraph(&gd,&gm,"D:\\TC\\BGI");
setbkcolor(2);
setcolor(10);
cout<<endl<<"Name\tCode\tNo. Of Views";
while(c.read((char*)&g, sizeof(g)))
{
g.displayg();
}
c.close();
fstream m("graphinfo.txt", ios::in|ios::out|ios::binary);
int pos;
cout<<endl<<endl<<"Enter the code of the graph you wish to view ";
cin>>sel;
closegraph();
while(m.read((char*)&g, sizeof(g)))
{
if(sel==g.checkcode())
{
pos=m.tellg();
g.viewg();
m.seekp(pos-sizeof(g));
m.write((char*)&g, sizeof(g));
}
}
m.close();
getch();
closegraph();
}

void drawaxis()
{
line(x_left_border(),Y0,2*x_right_border(),Y0);
line(X0,0,X0,2*Y0);
}

void load()
{
clrscr();
int gd = DETECT, gm, error;
int rect[9];
int x,y;
//1st
rect[0]=0;
rect[1]=getmaxy()/2+250;
//2nd
rect[2]=0;
rect[3]=getmaxy()/2+250;
//3rd
rect[4]=0;
rect[5]=getmaxy()/2+270;
//4th
rect[6]=0;
rect[7]=getmaxy()/2+270;

initgraph(&gd,&gm,"D:\\TC\\BGI");
setfillstyle(11,1);
floodfill(1,1,1);
settextstyle(10,0,0);
outtextxy(180,getmaxy()/2-60,"INITIALIZING");
for(int i=0;i<40;i++)
{
for(int j=2;j<5;j+=2)
rect[j]+=i;
setfillstyle(5,i);
fillpoly(4,rect);
delay(150);
}
settextstyle(8,0,1);
outtextxy(200,getmaxy()/2+40,"Press any Key To continue");
getch();
closegraph();
}