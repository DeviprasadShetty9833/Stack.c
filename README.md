# Stack.c

<br> ![Author: Deviprasad Shetty](https://img.shields.io/badge/Author-💫_Deviprasad%20Shetty-000000?style=for-the-badge&labelColor=white)
<br> 


# My Intro:
<br> Hi, 😃👋 I'm Deviprasad Shetty, highly passionate for coding, learning and exploring new fields in Computer Science domain. 
<br> I'm excited 😃 to dive deeper into my technical skills, collaborate with others, and take on projects that challenge me to grow. 
<br> Always eager to learn and connect with others who share similar interests! 🤗🧑‍💻
<br> 
| [![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5?style=for-the-badge&logo=LinkedIn&logoColor=white)](https://linkedin.com/in/deviprasad-shetty-4bba49313) | [![Website](https://img.shields.io/badge/Website-indigo?style=for-the-badge&logo=About.me&logoColor=white)](https://yourwebsite.com/) | [![My Portfolio](https://img.shields.io/badge/My_Portfolio-000?style=for-the-badge&logo=GitHub&logoColor=white)](https://github.com/DeviprasadShetty9833/My_Portfolio)  |                      
|---|---|---|
<br> 

---

| [![DSA_in_C_Tutorial](https://img.shields.io/badge/Back_to-DSA_in_C_Tutorial-000080?style=for-the-badge&logo=C&logoColor=white)](https://github.com/DeviprasadShetty9833/DSA_in_C_Tutorial) | [![Resources](https://img.shields.io/badge/📚_Back_to-Resources-A52A2A?style=for-the-badge&logo=book&logoColor=white)](https://github.com/DeviprasadShetty9833/Resources) |
|---|---|

---

👉 Source code to implement the basic operations of a singly linked list (insertion, deletion, and traversal) from the file : [src.c](https://github.com/DeviprasadShetty9833/Stack.c/blob/3b59308a1191ee4e4cc662b8bfdc20ecb9c7c3bf/src/Stack_using_Array.c)


---

📂 Stack Using Array

<table>  
<tr><td>  
  ⏺️ A stack is a linear data structure that follows the LIFO (Last In, First Out) principle.

  ⏺️ The stack has a maximum size, and operations must check for overflow (too many elements) and underflow (trying to pop from an empty stack).

<details>  
  <summary>Click to expand 🔻</summary>  
<br> 🟠 Basic Operations:

```html

- Push (insert an element) onto the top of the stack.

- Pop (remove an element) from the top of the stack.

- Peek (get top element without removing) the top element without removing it.

- Display (print all elements in stack order)

```

<br> 🟠 Applications:

```html

- Expression evaluation (postfix/prefix).

- Undo/Redo in editors.

- Function call management in recursion.

- Browser forward/backward navigation.

```

<br> 🟠 Advantages:

```html

- Easy to implement with arrays or linked lists.

- Ensures controlled access order.

```

</details>  

</td></tr>  
</table>  

---

👉 Source Code (file: stack_array.c)

<table>
<tr><td>

<br> ![1.](https://img.shields.io/badge/_1]_-Headers-000080?style=for-the-badge&logo=C&logoColor=white)   


*Code:*

```c

#include <stdio.h>   // For printf and scanf  
#include <stdlib.h>  // For exit()

```

*In Plain English:*

> "These are my toolkits. stdio.h helps me talk to you (input/output), and stdlib.h helps me quit when things go wrong."

</td></tr>  
</table>  

<table>
<tr><td>

<br> ![2.](https://img.shields.io/badge/_2]_-Define_Stack-000080?style=for-the-badge&logo=C&logoColor=white)   


*Code:*

```c

#define MAX 5   // Maximum size of the stack

typedef struct {
    int arr[MAX];   // Array to hold stack elements
    int top;        // Index of the top element
} Stack;

```

*Explanation:*

> - MAX defines the stack’s capacity.
> - arr[MAX] is the container holding stack elements.
> - top keeps track of where the top element is (starts at -1 when empty).


*In Plain English:*

> "Think of me as a stack of plates. arr is the plate rack, and top tells me which plate is on the very top. Initially, top = -1, meaning the rack is empty."

</td></tr>  
</table>  


<br> ![3.](https://img.shields.io/badge/_3]_-Create_a_Node-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));  // Allocate memory

    newNode->data = data;                         // Set the value
    newNode->next = NULL;                         // Initially points to nothing

    return newNode;                               // Return the new node
}

```

*Algorithm:*

```html

CreateNode(data):
   1. Allocate memory for new node.
   2. Set newNode.data = data.
   3. Set newNode.next = NULL.
   4. Return newNode.

```

*Explanation:*

> - 'createNode' is function that returns a pointer to a Node.
> - 'newNode' is a pointer to a Node.
> - 'malloc' calculates the size in bytes needed to store a Node Structure and allocates memory from the heap(dynamic memory) and returns void pointer.
> - (Node*) before malloc converts (typecasting) the generic void pointer into a Node pointer.
> - int data is stored in newNode's data and newNode's next pointer points to NULL i.e does not point to anything.

*Example:*

```html
HEAD→[Data1 | next1]→[Data2 | next2]→[Data3 | next3]→NULL
      \_____________/ \_____________/  \_____________/
             |                |               |  
            Node             Node            Node
\__________________________________________________________/
                              |
                      Singly Linked List

```

*In Plain English:*

> "I made a new node for you. I saved your number in it. I made sure it doesn't point to any other node yet. Here’s your brand-new node, ready to put it into your list."

</td></tr>
</table>

<table>
<tr><td>

<br> ![3.](https://img.shields.io/badge/_3]_-Initialize_Stack-000080?style=for-the-badge&logo=C&logoColor=white)   


```c
void initStack(Stack *s) {
    s->top = -1;   // Empty stack
}
```

Algorithm:

1. Set s->top = -1.



In Plain English:

> "I reset the rack so it’s empty. No plates here yet."

</td></tr>  
</table>  

<table>
<tr><td>

<br> ![4.](https://img.shields.io/badge/_4]_-Push_Operation-000080?style=for-the-badge&logo=C&logoColor=white)   


```c
void push(Stack *s, int data) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    s->arr[++(s->top)] = data;
    printf("%d pushed into stack\n", data);
}
```

Algorithm:

1. Check if stack is full → if yes, print “Overflow”.


2. Increment top.


3. Place data at arr[top].



Example:

Before push: top = -1

Push 10 → arr[0] = 10, top = 0

Push 20 → arr[1] = 20, top = 1


Stack: [10, 20] (20 is on top)

In Plain English:

> "I check if the rack is full. If not, I place your plate on the top and move the marker up. Voilà — plate stacked!"

</td></tr>  
</table>  

<table>
<tr><td>

5. Pop Operation

```c
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! Nothing to pop\n");
        return -1;
    }
    return s->arr[(s->top)--];
}
```

Algorithm:

1. Check if stack is empty → if yes, underflow.


2. Return arr[top].


3. Decrement top.



Example:

Stack: [10, 20, 30] (top = 2)

Pop → returns 30, new top = 1


Stack: [10, 20]

In Plain English:

> "I look at the top plate, hand it back to you, and then move the marker down. One less plate in the stack!"

</td></tr>  
</table>  

<table>
<tr><td>

6. Peek Operation

```c
int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}
```

In Plain English:

> "I won’t touch the stack, but I’ll tell you which plate is on top right now."

</td></tr>  
</table>  

<table>
<tr><td>

7. Display Stack

```c
void display(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (int i = s->top; i >= 0; i--)
        printf("%d\n", s->arr[i]);
}
```

Example:
If stack = [10, 20, 30], output is:

30
20
10

In Plain English:

> "I’ll show you all plates starting from the top. Like tipping the stack for a peek."

</td></tr>  
</table>  

<table>
<tr><td>

8. Main Function - Static Input

*Code:*

```c
int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    printf("Top element: %d\n", peek(&s));
    push(&s, 20);
    printf("Top element: %d\n", peek(&s));
    push(&s, 30);
    display(&s);
    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Top element: %d\n", peek(&s));
    display(&s);

    return 0;
}
```

*Sample Output:*

```html

10 pushed into stack
Top element: 10
20 pushed into stack
Top element: 20
30 pushed into stack
Stack elements (top to bottom):
30
20
10
Top element: 30
Popped: 30
Top element: 20
Stack elements (top to bottom):
20
10
```

</td></tr>  
</table>  

<table>
<tr><td>

9. Main Function - Static Input

*Code:*

```c
int main() {
    Stack s;
    initStack(&s);
    int choice, elem;

    while (1) {
        printf("Press \n 1. Push \n 2. Pop \n 3. Display \n 4. Exit \n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
              printf("Enter element to push: ");
              scanf("%d", &elem);
              push(&s, elem);
              break;

            case 2:
              elem = pop(&s);
              if (elem != -1)
              printf("%d popped from stack\n", elem);
              break;

            case 3:
              display(&s);
              break;

            case 4:
              return 0;

            default:
              printf("Invalid choice!\n");
        }
    }
}
```


</td></tr>  
</table>  
---


