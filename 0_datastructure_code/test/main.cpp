
#include <stdio.h>

class A
{
public:
   char data;
public:
   A(){data = 'A';}
   void ShowA(){printf("A: %c\n", data);};
   void DispA(){printf("a\n");};
};

class B
{
public:
   char data;
public:
   B(){data = 'B';}
   virtual void Show(){printf("B\n");};
   virtual void DispB(){printf("b\n");};
};

class C
{
public:
   char data;
public:
   C(){data = 'C';}
   virtual void ShowC(){printf("C: %c\n", data);};
   virtual void DispC(){printf("c\n");};
};

class D : public B//, public B, public C
{
//public:
//   char data;
public:
   D(){data = 'D';}
   virtual void Show(){printf("D\n");};
   virtual void DispD(){printf("d: %d\n", data);};
};

int main()
{
//   A* a = new D;
//   a->ShowA();

//   C* c = new D;
//   c->ShowC();

   B* b = new B;
   D* d1 = (D*)b;
   d1->Show();
   d1->DispD();
   return 0;
}



