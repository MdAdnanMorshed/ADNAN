// project name :Bkash
// project leader name :adnan morshed
// date : 31/12/2016 to 07/01/17

#include<stdio.h>
int desgin();  // complete
int menu_ber(int); // complete
int send_money();  // complete
int airtime(int); //50% complete
int airtime_desgin(); // complete
int payment();    //complete
int cash_out(int);   //complete 
int cash_out_desgin(); //complete
int my_bkash(int);    //20% complete
int my_bkash_desgin();//complete
int help_line(); //complete

int main(){    // main function
 	int number;
	while(1){
 		desgin();    
		printf("\nChoose your select number :");
		scanf("%d",&number);
			menu_ber(number);	
	 		if(number==00){break;}
	 	}
	return 0;
}
//----------------------------desgin--------------------------------
int desgin(){
	int i;
	printf("\n");
	for(i=0;i<=15;i++){
		printf("--");
	}
	printf("Bkash");
	for(i=0;i<=15;i++){
		printf("--");
	}
      printf("\n 01. Send money\n");
      printf(" 02. Airtime\n");
      printf(" 03. Payment\n");
      printf(" 04. Cash In\n");
      printf(" 05. Cash Out\n");
	  printf(" 06. My Bkash\n");
      printf(" 07. Help line\n");     
  
    for(i=0;i<=35;i++){
		printf("--");
	}
}

//----------------------------menu_bar--------------------------------
int menu_ber(int number){
	 switch(number){
	 	case 01 :{
	 		printf("case 01: Send money\n");
	 		int i;
	 			for(i=0;i<=15;i++){printf("--");}
				printf("\n");
			 	send_money();
			break;
		 }
		 case 02 :{
	 		printf("case 02: airtime\n");
	 			int i;
	 			for(i=0;i<=15;i++){printf("--");}
				printf("\n\n");
	 		 	airtime_desgin();		 		 	
			break;
		 }
		 case 03 :{
	 		printf("case 03: payment\n");
	 			int i;
	 			for(i=0;i<=15;i++){printf("--");}
				printf("\n\n");
			 	payment();
			break;
		 }
		 case 04 :{
	 		printf("case 04: cash_In\n");
	 		int pay,total_pay;
			FILE *fp;
			FILE *show;
	 		
	 		show=fopen("cash_In.txt","r+");
	 		fscanf(show,"%d",&total_pay);
			printf("Total Amount ::%d tk\n",total_pay);
	 		
			 fp=fopen("cash_In.txt","w+");
	 		printf("Pay the amount of money:");
	 		scanf("%d",&pay);
	 		
	 		 total_pay+=pay;
			 fprintf(fp,"%d",total_pay);
			 fclose(fp);
	 		 fclose(show);
	 		printf("\n Cash in Tk %d to 01712895799 successfull.\n free tk 00.00.Balance tk %d\n TrixID 0124\n at date(1/1/16 9:12)\n",pay,total_pay);
	
			break;
		 }
		 case 05 :{
	 		printf("case 05: cash_out\n");
	 		int i;
	 			for(i=0;i<=15;i++){printf("--");}
				 printf("\n\n");
	 		 	cash_out_desgin();
			break;
		 }
		 case 06 :{
	 		printf(" case 06: my_bkash\n");
	 			my_bkash_desgin();
			break;
		 }
		 case 07 :{
	 		printf(" case 07: help_line\n");
	 		help_line();
			break;
		 }
	 }       
}

int send_money(){
int amount,bkash_account,pin,total_amount,new_pin;
char ref[10];
FILE *fp;
FILE *pass;
	printf("\n Enter the bKash Account Number:");
	scanf("%d",&bkash_account);
	printf(" Enter the amount:");
	scanf("%d",&amount);
	printf(" Enter a reference about the transaction:");
	scanf("%s",ref);	
	printf(" Enter your bKash Mobile Menu PIN:");
	scanf("%d",&pin);
	pass=fopen("password.txt","r+");
	fscanf(pass,"%d",&new_pin);
	if(new_pin==pin){
		fp=fopen("cash_In.txt","r+");
		fscanf(fp,"%d",&total_amount);
		
		total_amount-=amount;
		printf("\n\tTotal Amount:%d\n",total_amount);
		printf("\tSuccessfull\n");
	}
	else {
		printf("\tNot Successfull...\n");
	}
}
int payment(){
	int amount,bkash_account,pin,total_amount,new_pass;
	char ref[10];
	FILE *fp;
	FILE *pass;
	printf("\nEnter the bKash Account Number:");
	scanf("%d",&bkash_account);
	printf("Enter the amount:");
	scanf("%d",&amount);
	printf("Enter a reference about the transaction:");
	scanf("%s",ref);
	printf("Enter the bKash Account Number:%d\nEnter the amount:%d\nEnter a reference about the transaction:%s\n",bkash_account,amount,ref);
	printf("Enter your bKash Mobile Menu PIN:");
	scanf("%d",&pin);
	pass=fopen("password.txt","r+");
	fscanf(pass,"%d",&new_pass);
	if(new_pass==pin){
		fp=fopen("cash_In.txt","r+");
		fscanf(fp,"%d",&total_amount);
		total_amount+=amount;
		printf("Total Amount:%d\n",total_amount);
		printf("Successfull\n");
	}
	else {
		printf("Not Successfull...\n");
	}
	fclose(fp);
	fclose(pass);
}
int airtime_desgin(){
      int count;
	  printf("\n 01.GP\n");
      printf(" 02.Airtle\n");
      printf(" 03.Robi\n");
      printf(" 04.Bangalink\n");
	  printf("\n\n Choose your select number :"); 
	  scanf("%d",&count);
	  airtime(count);	 	  
}
//---------------------- airtime full processing-------------------------
int airtime(int count){
	int phone_number,password,amount,total_amount,new_password;
	FILE *fp;
	FILE *update_air;
	FILE *pass;
	pass=fopen("password.txt","r+");
	fscanf(pass,"%d",&new_password);
	printf("Enter the phone number:");
	scanf("%d",&phone_number);
	printf("Enter the Ammount (tk):");
	scanf("%d",&amount);
	printf("\nEnter the Pin number");
	scanf("%d",&password);
	if(password==new_password){
		fp=fopen("cash_In.txt","r+");
		fscanf(fp,"%d",&total_amount);
		if(total_amount>=amount){

			total_amount-=amount;
		    update_air=fopen("cash_In.txt","w+");
			fprintf(update_air,"%d",total_amount);
			printf("total Amount :%d",total_amount);
			fclose(fp);
			fclose(update_air);	
		printf("\n\n your Faxiload Successfull\n");
		}
		else{
			printf("\n not more money!\n");
		}
	}
	else {
		printf("\n\n your Password is Wrong.....\n");
	}	
}

int cash_out_desgin(){
	int count;
	  printf("\n 01.From agent\n");
      printf(" 02.From ATM\n");
      printf(" 00.Menu\n");
	  printf("\n\n Choose your select number :"); 
	  scanf("%d",&count);
	  cash_out(count);	 	  
}

int cash_out(int count){
	switch (count){
		case 01:{
			int agent_number,cash_money,pass,new_pass,total_amount;
			float charge,balance;
			FILE *password;
			FILE *total_tk;
			password=fopen("password.txt","r+");
			fscanf(password,"%d",&new_pass);
			printf("Enter agent's bkash account number :");
			scanf("%d",&agent_number);
			printf("Enter the amount:");
			scanf("%d",&cash_money);
			printf("\n To account number %d Amount %d tk",agent_number,cash_money);
			printf("Enter the Bkash Mobile Menu pin:");
			scanf("%d",&pass);
			
			if(new_pass==pass){
				total_tk=fopen("cash_In.txt","w+");
				fscanf(total_tk,"%d",&total_amount);
				charge=(cash_money*18.5)/1000;
				 balance=total_amount-(cash_money+charge);
				
				printf("\n Cash Out tk %d to %d\n",cash_money,agent_number); 
				printf("Free tk %.2f\n",charge);
				printf("Balance tk %.2f TrxID 01234\n",balance); 
				printf("at date(12/1/16 9:12)\n");
				
			}
			else {
				printf("Your pin number is Worng....\n");
			}
			fclose(total_tk);
			fclose(password);
			break;
		}
		case 02:{
			break;
		}
		case 00:{
			desgin();
			break;
		}
	}
}
//--------------------my_bkash_desgin------------------------------------
int my_bkash_desgin(){
	int count;
	  printf("\n 01. check balance\n");
      printf(" 02. Change mobile menu pin\n");
      printf(" 03. activete ATM\n");
      printf(" 04. Change ATM pin\n");
      printf(" 00. Menu	\n");
	  printf("\n\n Choose your select number :"); 
	  scanf("%d",&count);
	 my_bkash(count);	
}

//---------------my_bkash processing-----------------------------------------
int my_bkash(int count){
	switch (count){
		case 01:{
			int pass,total_amount,new_pass;
			FILE *fp;
			FILE *password;
			printf("\n------- Check balance ---------------\n");
			  password=fopen("password.txt","r+");
			   fscanf(password,"%d",&new_pass);
			   printf("Enter the pin number:");
			   scanf("%d",&pass);  
			   if(new_pass==pass){
			   	fp=fopen("cash_In.txt","r+");
				fscanf(fp,"%d",&total_amount);
			   	 printf("\nyour current bkash account balance is tk %d.\n your avielavel bkash account balance tk%d.\n",total_amount,total_amount);
			   }
			   else {
			   		printf("\n\n your Password is Wrong.....\n");
			   } 
			break;
		}
		case 02:{
			int pass,new_pass;
			FILE *password;	
			 printf("-----------------Change mobile menu pin----------------\n");
			password=fopen("password.txt","r+");
			fscanf(password,"%d",&new_pass);
			
			printf("Enter the pin number :");
			scanf("%d",&pass);
			if(new_pass==pass){
				printf("OK\n");
				printf("change your new password:");
				scanf("%d",&new_pass);
				password=fopen("password.txt","w+");
				fprintf(password,"%d",new_pass);
				printf("Password:%d",new_pass);
				fclose(password);	
			}
			else {
				printf("Enter the pin number Wrong\n");
			}			
			break;
		}
		case 03:{
			printf("\n---------------------activete ATM-------------------\n");
			break;
		}
		case 04:{
			
			break;
		}
		case 00:{
			printf("-------------------------Menu---------------------------\n");
			desgin();
			break;
		}
	}	
}

int help_line(){
	printf(" #.Send money :\n\n");
	printf("\t01.Go to your bKash Mobile Menu by dialing *247#\n");
	printf("\t02.Choose Send Money\n");
	printf("\t03.Enter the bKash Account Number you want to send money to\n");
	printf("\t04.Enter the amount you want to send\n");
	printf("\t05.Enter a reference about the transaction.\n");
	printf("\t06.Now enter your bKash Mobile Menu PIN to confirm the transaction \n\n");
	
	printf(" #.cash_In :\n\n");
	printf("\t01.Go to any bKash Agent\n");
	printf("\t01.Let the Agent know the amount you want to Cash In\n");
	printf("\t03.Write down your bKash Account Number.\n");
	printf("\t04.Pay the amount of money you want to Cash In\n");
	printf("\t05.In exchange, the Agent will send balance to your bKash Account.\n\n");	
	
	printf(" #.cash_Out :\n\n");
	printf("\t01.Go to your bKash Mobile Menu by dialing *247#\n");
	printf("\t02.Choose Cash Out\n");
	printf("\t03.Choose “From Agent”\n");
	printf("\t04.Enter Agent’s bKash Account Number (ask the Agent)\n");
	printf("\t05.Enter the amount\n");
	printf("\t06.Enter your bKash Mobile Menu PIN\n\n");
	
	printf(" #.Airtime:\n\n");
	printf("\t01.Go to your bKash Mobile Menu by dialing *247#\n");
	printf("\t02.Choose Buy Airtime\n");
	printf("\t03.Choose your operator\n");
	printf("\t04.Choose your connection type\n");
	printf("\t05.Enter the 11 digit mobile number you want to buy airtime for\n");
	printf("\t06.Enter the amount of airtime you want to buy\n");
	printf("\t07.Enter your bKash Mobile Menu PIN to confirm\n\n");

	printf(" #.My Bkash :\n\n");
	printf("\t01.Go to your bKash Mobile Menu by dialing *247#\n");
	printf("\t02.Choose Send Money\n");
	printf("\t03.Enter the bKash Account Number you want to send money to\n");
	printf("\t04.Enter the amount you want to send\n");
	printf("\t05.Enter a reference about the transaction.\n");
	printf("\t06.Now enter your bKash Mobile Menu PIN to confirm the transaction\n\n");   
}
