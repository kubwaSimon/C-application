#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items{
    /* data */
    char Items[20];
    float Price;
    int Qty;
};
struct Orders
{
    /* data */
    char Customer[50];
    char date[50];
    int numberofItems;
    struct items Itm[50];
};

//FUNCTION FOR GENERATING BILLS
void generateBillheader(char name[60],char date[35])
{
    printf("\n\n");
       printf("\n TOP SHOPPING");
       printf("\n\t_______________________________________\n");
       printf("\nDate:%s",date);
       printf("\nInvoice To:%s",name);
       printf("\n");
       printf("__________________________________________\n");
       printf("Items\t\t");
       printf("QTY\t\t");
       printf("Total\t\t");
       printf("\n__________________________________________\n");
       printf("\n\n");
}
void generateBillbody(char Item[40], int Qty,float Price)
{
     printf("%s\t\t",Item);
        printf("%d\t\t",Qty);
        printf("%.2f\t\t",Qty*Price);
        printf("\n\n");
}

void generateBillFooter(float Total)
{
    printf("\n");
    float disc=0.1*Total;
    float netTotal=Total-disc;
    float cgst=0.09*netTotal,grandTotal=netTotal*cgst;
    printf("______________________________________________\n");
    printf("SubTotal\t\t\t%.2f",Total);
    printf("\nDiscount@10%s\t\t\t%.2f","%",disc);
    printf("\n\t\t\t\t___________________________________\n");
    printf("\n\tnetTotal\t\t\t%.2f",netTotal);
    printf("\n\tCGST@9s\t\t\t%.2f","%",cgst);
    printf("SGST@9%s\t\t\t%.2f","%",cgst);
    printf("\n___________________________________________");
    printf("\nGrandTotal\t\t\t%.2f",grandTotal);
    printf("\n__________________________________________\n");
}
int main()
 {
    int opt,n;
    struct Orders Ord;
    struct Orders Order;
   
    char name[50];
    char saveBill = 'y';
    char contFlag = 'y';
    {
        /* data */
    };
    
    FILE *fp;
    
    
    //DASHBOARD
      while (contFlag =='y')
      {
          /* code */
          system("CLS");
       float total=0;
    int invoiceFound = 0;
    printf("\n\n========TOP  SHOPPING=====");
    printf("\n\nPlease select your preferred option%d:\t");
    printf("\n1.Generate Invoice");
    printf("\n2.Display Invoices");
    printf("\n3.Search Invoice");
    printf("\n4.EXIT");
    printf("\nYour choice:\t");
    scanf("\%d",&opt);
    fgetc(stdin);
   switch (opt)
   {
   case 1:/* constant-expression */
       /* code */
       system("CLS");
       printf("\nPlease Enter Customer Name:\n");
       fgets(Ord.Customer,50,stdin);
       Ord.Customer[strlen(Ord.Customer)-1 ]= 0;
       strcpy(Ord.date,__DATE__);
       printf("\n Enter NO. of Items:\t");
       scanf("%d",&n);
       Ord.numberofItems = n;

       for (int i = 0; i <n; i++)
       {
           /* code */
           fgetc(stdin);
           printf("\n\n");
           printf("Enter Item %d\t",i+1);
           fgets(Ord.Itm[i].Items,20,stdin);
           Ord.Itm[i].Items[strlen(Ord.Customer)-1]=0;
           printf("\nEnter Item Qty:\t");
           scanf("%d",&Ord.Itm[i].Qty);
           printf("\nEnter product unit price:\t");
           scanf("%f",&Ord.Itm[i].Price);
           total += Ord.Itm[i].Qty*Ord.Itm[i].Price;
       }
       generateBillheader(Ord.Customer,Ord.date);
       for (int i = 0; i < n; i++){
       generateBillbody(Ord.Itm[i].Items,Ord.Itm[i].Qty,Ord.Itm[i].Price);
       }
       generateBillFooter(total);

      printf("\nDo you want to save Invoice?[y/n]:\t");
      scanf("%s",&saveBill);
      if(saveBill =='y'){
          fp=fopen("shopBilling.dat","a+");
          fwrite(&Ord,sizeof(struct Orders),1,fp);
          if(fwrite!=0)
          printf("\nSAVED");
          else
          printf("\nError occured");
          fclose(fp);
    

      }
   break;

   case 2:
   system("CLS");
   fp = fopen("shopBilling.dat","r");
   printf("\n*******Previous Invoices*******\n");
   while (fread(&Order,sizeof(struct Orders),1,fp)){
       /* code */
       float tot = 0;
       generateBillheader(Ord.Customer,Ord.date);
       for (int i = 0; i < n; i++)
       {
           /* code */
           generateBillbody(Order.Itm[i].Items,Order.Itm[i].Qty,Order.Itm[i].Price);
           tot+=Order.Itm[i].Qty*Order.Itm[i].Price;
       }
       generateBillFooter(total);
       
   }
   fclose(fp);
   break;

   case 3:
   printf("\nEnter customer Name:\t");
   //fgetc(stdin);
   fgets(name,50,stdin);
   name[strlen(name)-1]=0;
   fp = fopen("shopBilling.dat","r");
   printf("\t *******check for invoice %s*******\n",name);
   while 
  ( fread(&Order,sizeof(struct Orders),1,fp))
   {
       /* code */
       float tot = 0;
       if(!strcmp(Order.Customer,name)){
            generateBillheader(Ord.Customer,Ord.date);
       for (int i = 0; i < n; i++)
       {
           /* code */
           generateBillbody(Order.Itm[i].Items,Order.Itm[i].Qty,Order.Itm[i].Price);
           tot+=Order.Itm[i].Qty*Order.Itm[i].Price;
       }
       generateBillFooter(total);
       invoiceFound = 1;

       }
      
       
   }
   if (!invoiceFound)
   {
       /* code */
       printf("Sorry invoice %s not found",name);
   }
   
   fclose(fp);
   break;

   case 4:
   printf("\n\t\t Bye:)\n");
   exit(0);
   break;
   default:
   printf("Invalid Option");
   break;


   
   
   }
   printf("\n\nDo you want to perform another operation?[y/n]:\t");
   scanf("%s",&contFlag);
   }
    printf("\n\t\t Bye :)\n");
    printf("\n\n");
    
 return 0;
}