/*
http://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
*/
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if(s.empty() == true)
   {
       return -1;
   }
   return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty() == true)
   {
       return -1;
   }
   int front = s.top();
   s.pop();
   if(front < minEle)
   {
       minEle = (minEle*2)-front;
       front = (minEle + front)/2;
       return front;
   }
   else
   {
       return front;
   }
}
/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty() == true)
   {
       s.push(x);
       minEle = x;
       return;
   }
   if(x >= minEle)
   {
       s.push(x);
   }
   else
   {
       s.push((2*x)-minEle);
       minEle = x;
   }
}
