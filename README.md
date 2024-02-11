# Task 2

## About The Project
### A Banking Program

This is a small banking application where users can create their own accounts, make deposits and withdraw money. When opening an account, users can choose between different types, such as **savings** and **checking accounts**. Additionally,  user types are categorised into three groups: **Senior, Adult** and **Student**. Naturally, the interest rates for savings and check accounts vary based on the user’s type. Below are the annual interest rates for different user types:

	Senior
		saving interest : 	0.04 
		checking interest:	0.01
	Adult
		saving interest : 	0.03 
		checking interest:	0.01
	Student
		saving interest : 	0.04
		checking interest:	0.01

There are also **withdrawal charges** for **checking accounts**:

	Senior
		check charge:	0.01
	Adult
		check charge:	0.03
	Student
		check charge:	0.02


In some cases, if the withdrawn amount exceeds than account balance (meaning there are insufficient funds), the user will be charges **a $25 overdraft penalty** and the withdrawal transaction will not be allowed. The Overdraft Penalty is the same for all types of users.

Furthermore, if the account balance becomes **negative** by any reason, the user will also be **prohibited from withdrawing money** from the account.


## Build With
The c++ program is built using Visual Studio Code on MacOS.

## Getting Started

### Prerequisites 
1. An integrated development environment (IDE) capable of running c++ programs, such as CLion, Visual Studio Code and Eclipse installed.
2. Mac OS or Window OS.
3. An internet connection to check out the project from the repository.

### Installation
1. Clone the repo
    git clone https://github.com/swezinooszo/cs700-a2.git


### Usage
Please follow the below steps to run the program:
 
1. Open Assignment-2 project from IDE
2. Run the command in terminal 
    - g++ main.cpp transaction.cpp customer.cpp checking_account.cpp saving_account.cpp bank.cpp account.cpp bankUtil.cpp Date.cpp adult.cpp senior.cpp student.cpp -o main
    - ./main
  
At the start of the program, the user will be prompted with 5 options:

	0: Add Account
	1: Make Deposit
	2: Make Withdrawal
	3: Check Account
	4: Exit

#### 0: Add Account
To open an account,  the user must enter **‘0’**. Following that, the program will prompt the user to enter customer details including **Name, Address, Age** and **Phone Number**.

```
0: Add Account
1: Make Deposit
2: Make Withdrawal
3: Check Account
4: Exit
0

Enter Customer Name John
Enter Customer Address Regina
Enter Customer Age 40
Enter Customer Phone Number 30633333
```

After entering customer details, the user has to choose the type of user: **Senior, Adult** or **Student**. The user may select between **0, 1** and **2** for the user type.
```
Select: 
0: Senior 
1: Adult 
2: Student
1
```

For the next step, the user has to choose the account type: **Savings** or **Checking**. The user may also select between  **0** and **1** for the account type.
```
Select: 
0: Checking 
1: Savings
1
```
Finally, the account has been created. The program will display the assigned account number as follows.
```
Account: 91 Added
```

In this example, the program has created account number 91, which is a saving account belonging to an adult customer.

#### 1: Make Deposit
To make a deposit, the user must enter number **‘1’**. Following that, the user needs to input the **account number, deposit amount** and **deposit date**.
```
Select: 
0: Add Account 
1: Make Deposit 
2: Make Withdrawal 
3: Check Account 
4: Exit
1

Enter Account Number 91
Enter The Amount 2000
Enter the date yyyy-mm-dd 2018-10-10
```

After entering the date, the program will display the **transaction details** for that deposit as follows:
```
Deposit in 91 amount: $2000 on 2018-10-10 new balance: $2000
```

#### 2: Make Withdrawl
The user must enter **'2'** to make a withdrawal. After that, they need to enter the **account number, withdrawal amount** and **withdrawal date**, which are the same required information as for making a deposit.
```
Select: 
0: Add Account 
1: Make Deposit 
2: Make Withdrawal 
3: Check Account 
4: Exit
2

Enter Account Number 91
Enter The Amount 100
Enter the date yyyy-mm-dd 2020-10-10
```
After entering the date, the program will display **transaction details** for that withdrawal as follows:
```
Withdraw from 91 amount: $100 on 2020-10-10 new balance: $2020.16
```

#### 3: Check Account
Users can check all of their account transactions by entering value **‘3’**. Only the account number is required for this operation.
```
Select: 
0: Add Account 
1: Make Deposit 
2: Make Withdrawal 
3: Check Account 
4: Exit
3

Enter Account Number 91
```
Then the program will display **all transactions history** as below:

```
Account: 91
Owner: John
Type of customer: Adult
Balance: $2020.16
         DEP 2018-10-10 $ 2000.00 $ 2000.00
      INT CR 2020-10-10 $ 120.16 $ 2120.16
          WD 2020-10-10 $ 100.00 $ 2020.16
```

All transactions including **deposits, withdrawals, interests, check charges and overdraft penalties** are stored in the transaction history.


When checking transaction history, acronyms will be used as follows:
- **DEP** stands for Deposit.
- **INT CR** stands for Interest Credit.
- **WD** stands for Withdrawal.
- **CHKCHG** stands for Check Charge.
- **OD PEN** stands for Overdraft Penalty.

#### 4: Exit
Finally, after completing all transactions, the user can choose option **4** to exit the program.
```
Select: 
0: Add Account 
1: Make Deposit 
2: Make Withdrawal 
3: Check Account 
4: Exit
4
```

#### Check Charge for Checking Account
For withdrawal from a checking account, the program applies **a ‘check charge’** to the user. Below are the sample outputs of check charges for different user types.

Senior
(0.01 cents for withdrawl)
```
Account: 94
Owner: Kate
Type of customer: Senior
Balance: $899.99
         DEP 2024-01-10 $ 1000.00 $ 1000.00
          WD 2024-01-10 $ 100.00 $ 900.00
      CHKCHG 2024-01-10 $   0.01 $ 899.99
```
Adult
(0.03 cents for withdrawl)
```
Account: 7
Owner: William
Type of customer: Adult
Balance: $899.97
         DEP 2024-01-10 $ 1000.00 $ 1000.00
          WD 2024-01-10 $ 100.00 $ 900.00
      CHKCHG 2024-01-10 $   0.03 $ 899.97
```
Student
(0.02 cents for withdrawl)
```
Account: 67
Owner: Sam
Type of customer: Student
Balance: $899.98
         DEP 2024-01-10 $ 1000.00 $ 1000.00
          WD 2024-01-10 $ 100.00 $ 900.00
      CHKCHG 2024-01-10 $   0.02 $ 899.98
```     
#### Interest Rate calculation 
The interest amount is calculated using the **annual rate** and based on the **number of days** that the balance has been held. Below are the sample output of calculated **2-years interest rates** for different user types.

##### Senior
Saving Account
(0.04 interest rate)
```
Account: 86
Owner: Kate
Type of customer: Senior
Balance: $2260
         DEP 2018-10-11 $ 2000.00 $ 2000.00
      INT CR 2020-10-10 $ 160.00 $ 2160.00
         DEP 2020-10-10 $ 100.00 $ 2260.00
```
Checking Account (0.01 interest rate)
```
Account: 87
Owner: Kate
Type of customer: Senior
Balance: $2140
         DEP 2018-10-11 $ 2000.00 $ 2000.00
      INT CR 2020-10-10 $  40.00 $ 2040.00
         DEP 2020-10-10 $ 100.00 $ 2140.00
```
##### Adult
Saving Account (0.03 interest rate)
```

Account: 36
Owner: William
Type of customer: Adult
Balance: $2220
         DEP 2018-10-11 $ 2000.00 $ 2000.00
      INT CR 2020-10-10 $ 120.00 $ 2120.00
         DEP 2020-10-10 $ 100.00 $ 2220.00
```
Checking Account (0.01 interest rate)
```
Account: 27
Owner: William
Type of customer: Adult
Balance: $2140
         DEP 2018-10-11 $ 2000.00 $ 2000.00
      INT CR 2020-10-10 $  40.00 $ 2040.00
         DEP 2020-10-10 $ 100.00 $ 2140.00
```

##### Student
Saving Account (0.04 interest rate)
```
Account: 94
Owner: Sam
Type of customer: Student
Balance: $2260
         DEP 2018-10-11 $ 2000.00 $ 2000.00
      INT CR 2020-10-10 $ 160.00 $ 2160.00
         DEP 2020-10-10 $ 100.00 $ 2260.00
```
Checking Account (0.01 interest rate)
```
Account: 92
Owner: Sam
Type of customer: Student
Balance: $2140
         DEP 2018-10-11 $ 2000.00 $ 2000.00
      INT CR 2020-10-10 $  40.00 $ 2040.00
         DEP 2020-10-10 $ 100.00 $ 2140.00
```

#### Overdraft Penalty
The program will charge **an overdraft penalty** to user if there are **insufficient funds** in the account for a withdrawal.

```
Overdraft Penalty is charged from 27 amount: $25 on 2020-10-10 new balance: $75
```
Transaction History sample
```
Account: 27
Owner: James
Type of customer: Senior
Balance: $75
         DEP 2020-10-10 $ 100.00 $ 100.00
      OD PEN 2020-10-10 $  25.00 $  75.00
```

#### Prohibition from withdrawal
If the account balance becomes **negative**, the user is prohibited from withdrawing funds from the account. Below is a sample output:

```
The balance from account 27 is negative -20. Withdrawal failed.
```
Transaction History sample
```
Account: 27
Owner: James
Type of customer: Senior
Balance: $-20
         DEP 2020-10-10 $ 100.00 $ 100.00
      OD PEN 2020-10-10 $  25.00 $  75.00
          WD 2020-10-10 $  70.00 $   5.00
      OD PEN 2020-10-10 $  25.00 $ -20.00
```

### External Document
The location of the external document is cs700-a2/Assigment-2/doc/html/index.html

### Contact
[swezinoo410@gmail.com](mailto:swezinoo410@gmail.com)

### Additional Note
The newly created data fields and functions which are not specified in the question for the needs of the program:
##### Customer Class:
An enum **customer_type** is added to this class to differentiate later for which type of customer is created. (Savings and checking interest rates are different for each customer type.)

##### Savings Account Class:
A **charge_overdraft_penalty()** function is created to charge overdraft penalties for exceeding withdrawal amounts.

##### Checking Account Class:
A **charge_overdraft_penalty()** function is created to charge overdraft penalties for exceeding withdrawal amounts.
A **deduct_check_charge()** function is created for check charges for checking accounts.
