#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //linux/mac
//#include <windows.h>
// #include <mongoc.h>

/*
void insert_product(Product prod) {
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    bson_error_t error;
    bson_t *doc;

    // Create a new client object and connect to the MongoDB server
    client = mongoc_client_new("mongodb://localhost:27017");

    // Get a handle to the "products" collection
    collection = mongoc_client_get_collection(client, "store", "products");

    // Create a new BSON document to represent the product
    doc = bson_new();
    BSON_APPEND_INT32(doc, "sku", prod.sku);
    BSON_APPEND_UTF8(doc, "name", prod.prodName);
    BSON_APPEND_DOUBLE(doc, "price", prod.price);

    // Insert the document into the collection
    if (!mongoc_collection_insert_one(collection, doc, NULL, NULL, &error)) {
        fprintf(stderr, "Error inserting document: %s\n", error.message);
    }

    // Clean up
    bson_destroy(doc);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
}


 */


typedef struct {
    int sku;
    char prodName[100];
    float price;

} Product;

typedef struct {
    Product prod;
    int quantity;

} Cart;



void menu();

void addProduct();

void listProducts();

void viewCart();

void buyProduct();

Product grabProductById(int code);

void endPurchase();

int inCart(int code);

static int counter_product = 0;

static int counter_cart = 0;

static Cart cartSize[50];

static Product products[100];

void infoProduct(Product prod) {
    //it will take a product's name or ID and print out its information
    printf("Product Code: %d", prod.sku, "\n");
    printf("\n");
    printf("Product Price: %f", prod.price);
    printf("\n");
    printf("Product Name: %s\n", strtok(prod.prodName, "\n"));

}

void menu() {
    //prints out options menu;
    int option;
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
    printf("+=+=+=+=+=+W E L C O M E to MAISON MAITE+=+=+=+=+=+\n");
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
    
    printf("Select an option below:  \n");
    printf("[1] - Add Product");
    printf("[2] - Product List");
    printf("[3] - Buy Product");
    printf("[4] - See Cart");
    printf("[5] - Checkout");
    printf("[6] - Log Out");
    scanf("%d", &option);
    getchar();

    switch(option) {
        case 1: 
            addProduct();
            break;
        case 2:
            listProducts();
            break;
        case 3: 
            buyProduct();
            break;
        case 4: 
            viewCart();
            break;
        case 5:
            endPurchase();
            break;
        case 6:
            printf("Come again!\n");
            sleep(2);
            exit(0);
            break;
        default:
            printf("Invalid option");
            menu();

        

    }
    
    
}

void addProduct() {
    int continueAdding = 1;

    do {
         
        printf("Please type the name of the Product: \n");
        fgets(products[counter_product].prodName, 30, stdin);
        
        printf("Please type the STOCK KEEPING UNIT (sku) of the product: \n");
        scanf("%d", &products[counter_product].sku);
        getchar();
        printf("Please inform the PRICE of the product\n");
        scanf("%.2f", &products[counter_product].price);
        int items_read = scanf("%f", &products[counter_product].price);
        if (items_read != 1) {
            printf("Couldn't get the data, try again: \n");
            scanf("%.2f", &products[counter_product].price);
        }
        getchar();
         counter_product++;
        printf("Input done, would you like to keep adding? (1 for yes, 0 for no)");
        scanf("%d", &continueAdding);
        getchar();
        if(continueAdding != 1 && continueAdding != 0) {
            printf("Invalid input, please try again");
            printf("Input done, would you like to keep adding? (1 for yes, 0 for no)\n");
            scanf("%d", &continueAdding);
        }
    //adds newProd to Product;
    } while (continueAdding);
    if (!continueAdding) {
        menu();
    }
}


void listProducts() {
    if (counter_product > 0) {
        printf("=-=-=-=-=- [ P R O D U C T S] -=-=-=-=-=-=\n");
        printf("--------------------------------------------\n");
        for (int i = 0; i < counter_product; i++) {
            infoProduct(products[i]);
            printf("----------------------------------\n");
        }

    } else {
        printf("No products in storage yet");

        
    }

    menu();
}

int inCart(int code) {
    ;
    // Search for a product with the given SKU in the cartSize array
    for (int i = 0; i < counter_cart; i++) {
        if (cartSize[i].prod.sku == code) {
          
            // Return a pointer to the Cart struct if a match is found
            return i;
        }
    }
    // Return null if no match was found
    return -1;
}

void viewCart() {
    if (counter_cart > 0) {
        printf("Products in cart:  \n");
        printf("-------------------\n");
        for (int i = 0; i < counter_cart; i++) {
            infoProduct(cartSize[i].prod);
            printf("Qtd: %d\n", cartSize[i].quantity);
            sleep(1);
        }
    } else {
        printf("Cart is empty");
        
       
    }

    menu();
}


Product grabProductById(int code) {
    Product p;
    for (int i = 0; i < counter_product; i++) {
        if(products[i].sku == code) {
            p = products[i];
        }
    }
    return p;
}
void endPurchase() {
    if (counter_cart > 0) {
        float totalAmount = 0.0;
        printf("Products in Cart: \n");
        printf("-------------------\n");
        for (int i = 0; i < counter_cart; i++) {
            Product p = cartSize[i].prod;
            int amount = cartSize[i].quantity;
            totalAmount += p.price * amount;
            infoProduct(p);
            
            printf("Quantity: %d\n", amount);
            printf("----------------------\n");
            sleep(1);
        }
        printf("Your total purchase amount is:  %.2f\n", totalAmount);

        counter_cart = 0;

        printf("Thank you for your business");
        sleep(5);
        menu();

    } else {
        printf("Cart is empty... so far\n");
        sleep(3);
        menu();
    }

}

void buyProduct() {
    if (counter_product > 0) {
            printf("Inform the code of the product you wish to add to the cart");
            int choice;
            int quantity;
            printf("===============[AVAILABLE PRODUCTS]================\n");
            for (int i = 0; i < counter_product; i++) {
                    infoProduct(products[i]);
                    printf("----------------------\n");
                    sleep(1);
            }
        scanf("%d", &choice);
        getchar();

        
        int choiceBuy = 1;
       while (choiceBuy == 1) {
        int inCartCheck = inCart(choice);
        if (inCartCheck != -1) {
            cartSize[inCartCheck].quantity++;
        } else {
          
          
                Product p = grabProductById(choice);
                if (p.sku) {
                      printf("Please make sure to write the QUANTITY now.\n");
                      scanf("%d", &quantity);
                        cartSize[counter_cart].prod = p;
                        cartSize[counter_cart].quantity = quantity;
                        counter_cart++;
                } else {
                        printf("Invalid product choice");
                }
      
        }

          printf("Items purchased. Would you like to purchase more? 1 for yes, 2 for no");
          scanf("%d", &choiceBuy);
          } 
    } else {
                printf("There are no products for sale yet");
                menu();
            }
                menu();
    }


int main() {
        menu();
        return 0;
}