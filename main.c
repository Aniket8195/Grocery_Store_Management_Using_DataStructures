#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct node {
  char name[50];
  int price;
  struct node *next;
  int quantity;
};

// Stack structure using linked list
struct stack {
  struct node *top;
};

//create a new node in the linked list
struct node* createNode(char name[], int price) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  strcpy(newNode->name, name);
  newNode->price = price;
  newNode->next = NULL;
  return newNode;
}

//add a new node to the linked list
struct node* addNode(struct node *head, char name[], int price) {
  struct node *newNode = createNode(name, price);

  if (head == NULL) {
    return newNode;
  }

  struct node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;

  return head;
}



//display the products available in the store
void displayProducts(struct node *head) {
  printf("\nProducts available in the store:\n");
  printf("Name\t\tPrice\n");
  printf("------------------------------\n");
  while (head != NULL) {
    printf("%s\t\t%d\n", head->name, head->price);
    head = head->next;
  }
}

//create a new stack
struct stack* createStack() {
  struct stack *s = (struct stack*)malloc(sizeof(struct stack));
  s->top = NULL;
  return s;
}

// Function to push a new node to the stack
void push(struct stack *s, char name[], int price) {
  struct node *newNode = createNode(name, price);
  newNode->next = s->top;
  s->top = newNode;
}

//pop a node from the stack
void pop(struct stack *s) {
  if (s->top == NULL) {
    printf("\nCart is empty.\n");
    return;
  }
  struct node *temp = s->top;
  s->top = s->top->next;
  free(temp);
}

//displaying the items in the cart
void displayCart(struct stack *s) {
  printf("\nItems in the cart:\n");
  printf("Name\t\tPrice\n");
  printf("------------------------------\n");
  struct node *temp = s->top;
  while (temp != NULL) {
    printf("%s\t\t%d\n", temp->name, temp->price);
    temp = temp->next;
  }
}
void generateBill(struct stack *cart) {
  if (cart->top == NULL) {
    printf("\nCart is empty. Cannot generate bill.\n");
    return;
  }

  printf("\n************************PCMC-MART************************\n");
  printf("-----------------------------------------------------------\n");
  printf("Name\t\tPrice(Per Unit)\t\tQuantity\n");
  printf("-----------------------------------------------------------\n");

  int total = 0;
  struct node *temp = cart->top;
  while (temp != NULL) {
    printf("%s\t\t%d\t\t\t%d\n", temp->name, temp->price, temp->quantity);
    total += temp->price * temp->quantity;
    temp = temp->next;
  }
  printf("\n");
  printf("\n");
  printf("-----------------------------------------------------------\n");
  printf("Total\t\tRs.%d\n", total);
  printf("-----------------------------------------------------------\n");
}

void updateQuantities(struct stack *cart) {
  if (cart->top == NULL) {
    printf("\nCart is empty. Cannot update quantities.\n");
    return;
  }

  struct node *temp = cart->top;
  while (temp != NULL) {
    printf("\nEnter the quantity for item '%s': ", temp->name);
    scanf("%d", &temp->quantity);
    temp = temp->next;
  }
}

int main() {
  
  struct node *products = NULL;

  // Adding products to the store
  products=addNode(products, "Apple", 100);
  products=addNode(products, "Banana", 50);
  products=addNode(products, "Orange", 150);
  products=addNode(products, "Grapes", 50);
 products=addNode(products, "Mango", 500);
  products=addNode(products, "Almonds", 975);
  products=addNode(products, "Turmeric",165);
  products=addNode(products, "Mustard oil", 176);
  products=addNode(products, "Coconut oil", 130);
  products=addNode(products, "Ghee", 450);
  products=addNode(products, "Pasta", 500);
  products=addNode(products, "Sugar", 40);
  products=addNode(products, "Coca-Cola 1.25L", 45);
  products=addNode(products, "Jaggery",100);
  products=addNode(products, "Basmati rice", 288);
  products=addNode(products, "Maida", 49);
  products=addNode(products, "Toor dal",185);
  products=addNode(products, "Chana dal",89);
  products=addNode(products, "salt", 24);
  products=addNode(products, "Tooth paste – 200 gms",108);
  products=addNode(products, "Bathing soap", 30);
  products=addNode(products, "Body lotion ",42);
  products=addNode(products, "Washing powder – 1 kg",100);
  products=addNode(products, "Dettol – 1 bottle", 329);
  products=addNode(products, "Mosquito liquid", 277);

  // Display the products available in the store
  displayProducts(products);

  // Create a stack to store the items in the cart
  struct stack *cart = createStack();

  int choice;
  char name[50];
  int price;
  int found;

  do {
    printf("\nMenu:\n");
    printf("1. Add item to cart\n");
    printf("2. Remove item from cart\n");
    printf("3. Display cart\n");
    printf("4. Update quantities\n");
    printf("5. Checkout\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter the name of the item: ");
        scanf("%s", name);
        found = 0;
        struct node *temp = products;
        while (temp != NULL) {
          if (strcmp(temp->name, name) == 0) {
            found = 1;
            price = temp->price;
            break;
          }
          temp = temp->next;
        }
        if (found) {
          push(cart, name, price);
          printf("\nItem added to the cart.\n");
        } else {
          printf("\nItem not found in the store.\n");
        }
        break;
      case 2:
        pop(cart);
        printf("\nItem removed from the cart.\n");
        break;
      case 3:
        displayCart(cart);
        break;
      case 4:
       updateQuantities(cart);
        break;
      case 5:
        generateBill(cart);
        break;
      case 6:
        printf("\nExiting the program.\n");
        break;
      default:
        printf("\nInvalid choice.\n");
        break;
    }
  } while (choice != 6);

  return 0;
}


