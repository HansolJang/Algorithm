// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#define SIZE 111111

typedef struct stack
{
    int top;
    int data[SIZE];    
}stack;

void push(stack* st, int num)
{
    if(st->top != SIZE - 1)
    {
        st->data[++st->top] = num;
    }
}

int peek(stack* st)
{
    return st->data[st->top];    
}

int pop(stack* st)
{
     return st->data[st->top--];
}

int is_empty(stack* st)
{
    if(st->top < 0)
        return 1;
    else
        return 0;
}

int solution(int H[], int N) {
    int blocks = 0;
    int pivot;
    stack st;
    st.top = -1;
    push(&st, H[0]);
    
    for(int i=1; i<N; i++)
    {
        pivot = peek(&st);
        //같은 높이의 기둥은 같은 블럭
        if(pivot == H[i])
        {
            if(!is_empty(&st))
                pop(&st);
            push(&st, H[i]);
        }
        //작거나 큰 기둥은 서로 다른 블럭
        else
        {
            blocks++;
            //더 작은 블록이 나옴
            if(pivot > H[i])
            {
                if(!is_empty(&st))
                    pop(&st);
                push(&st, H[i]);
            }
            //더 큰 블록이 나옴
            else
            {
                push(&st, H[i]);
            }
        }
    }
    return blocks;
}

/*
You are going to build a stone wall. 
The wall should be straight and N meters long, 
and its thickness should be constant; 
however, it should have different heights in different places. 
The height of the wall is specified by a zero-indexed array H of N positive integers. 
H[I] is the height of the wall from I to I+1 meters to the right of its left end. 
In particular, H[0] is the height of the wall's left end and H[N−1] is the height of 
the wall's right end.

The wall should be built of cuboid stone blocks 
(that is, all sides of such blocks are rectangular). 
Your task is to compute the minimum number of blocks needed to build the wall.

Write a function:

int solution(int H[], int N);

that, given a zero-indexed array H of N positive integers specifying 
the height of the wall, returns the minimum number of blocks needed to build it.

For example, given array H containing N = 9 integers:

  H[0] = 8    H[1] = 8    H[2] = 5
  H[3] = 7    H[4] = 9    H[5] = 8
  H[6] = 7    H[7] = 4    H[8] = 8
the function should return 7. 
The figure shows one possible arrangement of seven blocks.



Assume that:

N is an integer within the range [1..100,000];
each element of array H is an integer within the range [1..1,000,000,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage 
(not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/
