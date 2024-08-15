class Customer
{
    String name, address, phoneNum;
    public Customer(String name, String address, String phoneNum)
    {
        this.name = name;
        this.address = address;
        this.phoneNum = phoneNum;
    }
    public void Display()
    {
        System.out.println("Name: " + name +"\nAddress: " + address + "\nPhone Number: " + phoneNum+"\n");
    }
}

class Account
{
    private int accNum;
    private double bal;
    public Account(int accNum, double bal)
    {
        this.accNum = accNum;
        this.bal = bal;
    }
    public void withdraw(double amount)
    {
        bal = bal - amount;
    }
    public void Display()
    {
        System.out.println("Account number: " + accNum +"\nBalance: Rs." + bal+ "\n");
    }
}

class SBP {
    private Customer customer;
    private Account account;
    private double minimumInterestRate = 4.2;
    private double minimumBalance = 10000.0;
    private double maxWithLimit = 5000.0;

    public SBP(Customer customer, Account account)
    {
        this.customer = customer;
        this.account = account;
    }

    public double getMinInterestRate()
    {
        return minimumInterestRate;
    }

    public double getMaxWithLimit() {
        return maxWithLimit;
    }

    public double getInterestRate() {
        return minimumInterestRate;
    }

    public double getWithLimit() {
        return maxWithLimit;
    }
}

class MCB extends SBP
{
    public MCB(Customer customer, Account account)
    {
        super(customer, account);
    }


    public double getInterestRate()
    {
        return super.getMinInterestRate() + 0.5;
    }
}

class BOP extends SBP
{
    public BOP(Customer customer, Account account)
    {
        super(customer, account);
    }

    public double getWithLimit()
    {
        return super.getMaxWithLimit() + 1000.0;
    }
}

class Main {
    public static void main(String[] args) {
        Customer customer = new Customer("Syed Farhan Jafri", "Askari 11", "0318-1234567");
        Account account = new Account(133766621, 690000.0);

        SBP sbp = new SBP(customer, account);
        MCB mcb = new MCB(customer, account);
        BOP bop = new BOP(customer, account);

        customer.Display();
        account.Display();
        System.out.println("SBP Interest Rate: " + sbp.getInterestRate());
        System.out.println("MCB Interest Rate: " + mcb.getInterestRate());
        System.out.println("BOP Withdrawal Limit: " + bop.getWithLimit());

    }
}
  