class Customer {
    String name, address, mobileNumber;

    public Customer(String name, String address, String mobileNumber)
    {
        this.name = name;
        this.address = address;
        this.mobileNumber = mobileNumber;
    }

    public String getName()
    {
        return name;
    }

    public String getAddress()
    {
        return address;
    }

    public String getPhoneNumber()
    {
        return mobileNumber;
    }
    public void Print()
    {
        System.out.println("Name of User: " + name +"\nAddress of User: " + address + "\nPhone Number of User: " + mobileNumber);
    }
}

class Account
{
    private int accountNumber;
    private double accountBalance;
    public Account(int accountNumber, double accountBalance)
    {
        this.accountNumber = accountNumber;
        this.accountBalance = accountBalance;
    }
    public int getAccountNumber()
    {
        return accountNumber;
    }
    public double getBalance()
    {
        return accountBalance;
    }
    public void deposit(double amount)
    {
        accountBalance = accountBalance + amount;
    }
    public void withdraw(double amount)
    {
        accountBalance = accountBalance - amount;
    }
    public void Print()
    {
        System.out.println("Account Number of User: " + accountNumber +"\nBalance of User: " + accountBalance+ " Dollars\n");
    }
}

class SBP {
    private Customer user;
    private Account acc;
    private double minInterest = 4.5;
    private double minAccBal = 1000.0;
    private double maxWithdraw = 5000.0;

    public SBP(Customer user, Account acc)
    {
        this.user = user;
        this.acc = acc;
    }

    public double getMinInterest() {
        return minInterest;
    }

    public double getMinAccBal() {
        return minAccBal;
    }

    public double getMaxWithdraw() {
        return maxWithdraw;
    }

    public double getInterest() {
        return minInterest;
    }

    public double getWithdrawal() {
        return maxWithdraw;
    }
}

class MCB extends SBP
{
    public MCB(Customer user, Account acc)
    {
        super(user, acc);
    }


    public double getInterest()
    {
        return super.getMinInterest() + 0.5;
    }
}

class BOP extends SBP
{
    public BOP(Customer user, Account acc)
    {
        super(user, acc);
    }

    public double getWithdrawal()
    {
        return super.getMaxWithdraw() + 1000.0;
    }
}

class Main {
    public static void main(String[] args) {
        Customer user = new Customer("Zoya Arif", "DHA", "0314-7654321");
        Account acc = new Account(659402952, 500000.0);

        SBP sbpObj = new SBP(user, acc);
        MCB mcbObj = new MCB(user, acc);
        BOP bopObj = new BOP(user, acc);

        user.Print();
        acc.Print();
        System.out.println("SBP Interest Rate is " + sbpObj.getInterest());
        System.out.println("MCB Interest Rate is " + mcbObj.getInterest());
        System.out.println("BOP Withdrawal Limit is " + bopObj.getWithdrawal());

    }
}
  