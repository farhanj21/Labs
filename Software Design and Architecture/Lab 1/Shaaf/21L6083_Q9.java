class Customer {
     String name;
     String address;
     String phoneNumber;
  
    public Customer(String name, String address, String phoneNumber) {
      this.name = name;
      this.address = address;
      this.phoneNumber = phoneNumber;
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
      return phoneNumber;
    }
    public void Display()
    {
        System.out.println("Name: " + name +"\nAddress: " + address + "\nPhone Number: " + phoneNumber+"\n");   
    }
  }
  
  class Account 
  {
    private int accountNumber;
    private double balance;
    public Account(int accountNumber, double balance) 
    {
      this.accountNumber = accountNumber;
      this.balance = balance;
    }
    public int getAccountNumber() 
    {
      return accountNumber;
    }
    public double getBalance() 
    {
      return balance;
    }
    public void deposit(double amount) 
    {
      balance += amount;
    }
    public void withdraw(double amount) 
    {
      balance -= amount;
    }
    public void Display()
    {
        System.out.println("Account number: " + accountNumber +"\nBalance: " + balance+ " pkr\n");   
    }
  }
  
  class SBP {
    private Customer customer;
    private Account account;
    private double minimumInterestRate = 4.0;
    private double minimumBalance = 1000.0;
    private double maximumWithdrawalLimit = 5000.0;
  
    public SBP(Customer customer, Account account) {
      this.customer = customer;
      this.account = account;
    }
  
    public double getMinimumInterestRate() {
      return minimumInterestRate;
    }
  
    public double getMinimumBalance() {
      return minimumBalance;
    }
  
    public double getMaximumWithdrawalLimit() {
      return maximumWithdrawalLimit;
    }
  
    public double getInterestRate() {
      return minimumInterestRate;
    }
  
    public double getWithdrawalLimit() {
      return maximumWithdrawalLimit;
    }
  }
  
  class MCB extends SBP {
    public MCB(Customer customer, Account account) 
    {
      super(customer, account);
    }
  
    
    public double getInterestRate() 
    {
      return super.getMinimumInterestRate() + 0.5;
    }
  }
  
  class BOP extends SBP 
  {
    public BOP(Customer customer, Account account) 
    {
      super(customer, account);
    }
  
    public double getWithdrawalLimit() 
    {
      return super.getMaximumWithdrawalLimit() + 1000.0;
    }
  }
  
   class Main {
    public static void main(String[] args) {
      Customer customer = new Customer("Shaaf Salman", "Model Town Ext.", "0317-xxxxxx");
      Account account = new Account(1977901101, 50000.0);
  
      SBP sbp = new SBP(customer, account);
      MCB mcb = new MCB(customer, account);
      BOP bop = new BOP(customer, account);
  
      customer.Display();
      account.Display();
      System.out.println("SBP Interest Rate: " + sbp.getInterestRate());
      System.out.println("MCB Interest Rate: " + mcb.getInterestRate());
      System.out.println("BOP Withdrawal Limit: " + bop.getWithdrawalLimit());

      account.withdraw(10000);
      System.out.print("\nAfter Withdrawing 10000\n");
      account.Display();
    }
}
  